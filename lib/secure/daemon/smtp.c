/*
 * Email Server. Sends outgoing emails to
 * an external SMTP server.
 * 
 * Created by Zaxan@Haven
 *
 * 24-Feb-2006
 */

#include <lib.h>
#include <daemons.h>
#include <network.h>
#include <config.h>
#include <commands.h>
#define ADMIN_EMAIL "havenmud@duuk.com"

#include "include/smtp.h"

inherit LIB_DAEMON;

private static mapping __MessageQueue = ([ ]);

static void create()
{
    daemon::create();
    SetNoClean(1);
}

private nomask string print_previous_objects()
{
    string str = "({ ";
    string *strobj = ({ });
    object *prevobj = all_previous_objects();

    foreach(object obj in prevobj)
    {
	strobj += ({ base_name(obj) });
    }

    str += implode(strobj, ", ") + " })";

    return str;
}

private nomask int check_security()
{
    if (base_name(previous_object()) != LIB_CONNECT && !adminp(this_player()) && base_name(previous_object()) != CMD_CHFN && base_name(previous_object()) != BUGS_D) 
    {
	CHAT_D->eventSendChannel("SMTP", "error",
		"Unauthorized email operation. Previous objects = "+
		print_previous_objects());
	error("Unauthorized email operation. Previous objects = "+
		print_previous_objects());
	return 0;
    }

    return 1;
}

mapping GetMessageQueue()
{
    if (!check_security())
    {
        return ([ ]);
    }
    else
    {
        return __MessageQueue;
    }
}

int eventCreateOutgoingMessage(string *recipients, string subj, string body)
{
    class EmailMessage Message = new (class EmailMessage);
    
    if (!check_security())
    {
        return 0;
    }

    // Initialize the message
    Message->State = SMTP_STATE_NOTSENT;
    Message->CanWrite = 0;
    Message->ToList = implode(recipients, ",");
    Message->Recipients = recipients;
    Message->Subject = subj;

    // Add the client headers
    Message->Body = "From: "+ADMIN_EMAIL+"\r\n"+
                    "To: "+Message->ToList+"\r\n"+
                    "Subject: "+subj+"\r\n\r\n";

    // Fix up any SMTP nuances in the message body and append it
    Message->Body += fix_body(body);

    // Queue up the message
    eventSendOutgoingMessage(Message);

    return 1;
}

private nomask void eventSendOutgoingMessage(class EmailMessage Message)
{
    int sockfd = 0;
    int retcode = 0;

    retcode = socket_create(STREAM, "eventCloseSocket");
    if (retcode < 0)
    {
        eventSocketError(Message, "Error in socket_create().", retcode);
    }
    sockfd = retcode;

    // Add message to queue
    __MessageQueue[sockfd] = Message;

    retcode = socket_connect(sockfd, EXTERNAL_SMTP_SERVER+" 25", "eventReadData", "eventCanWriteData");
    if (retcode < 0)
    {
        eventSocketError(Message, "Error in socket_connect().", retcode);
        eventCloseSocket(sockfd);
    }
}

private nomask string fix_body(string input_body)
{
    string *tmp_arr = ({ });
    string output_body = "";

    tmp_arr = explode(input_body, "\n");

    // Replace periods that start a line with two periods per RFC 2821 section 4.5.2
    for (int iIndex = 0; iIndex < sizeof(tmp_arr) ; iIndex++)
    {
        if (tmp_arr[iIndex][0] == '.')
        {
            tmp_arr[iIndex] = "." + tmp_arr[iIndex];
        }
    }
    
    // Turn \n's into \r\n's
    output_body = implode(tmp_arr, "\r\n");

    return output_body;
}

private nomask void eventSocketError(class EmailMessage msg, string str, int x)
{
    eventReportEmailError(msg, str);
}

private nomask void eventReportEmailError(class EmailMessage msg, string reason)
{
    CHAT_D->eventSendChannel("SMTP", "error",
            "Unable to send message to "+msg->ToList+" with "+
            "subject \""+msg->Subject+"\". Reason: "+reason);
    log_file("inet/smtp_error", ctime(time()) + " - Unable to send message to "+msg->ToList+
             " with "+"subject "+msg->Subject+". Reason: "+reason+"\n");
}

private nomask void eventReportEmailSuccess(class EmailMessage msg)
{
    CHAT_D->eventSendChannel("SMTP", "reports",
            "Successfully sent message to "+msg->ToList+" with "+
            "subject \""+msg->Subject+"\".");
}

void eventReadData(int fd, string data)
{
    string response;
    
    // Validate we're getting only strings
    if (!stringp(data))
    {
        eventCloseSocket(fd);
        error("Received non-string data on socket "+fd+".");
        return;
    }

    if (member_array(fd, keys(__MessageQueue)) == -1)
    {
        eventCloseSocket(fd);
        error("Received data on socket "+fd+", but there was no associated email message data.");
        return;
    }
    
    response = (string)data;

    // Process the response appropriately based on message state
    switch (__MessageQueue[fd]->State)
    {
        case SMTP_STATE_NOTSENT:
            eventProcessInitialResponse(fd, response);
            break;
        case SMTP_STATE_HELO:
            eventProcessHELOResponse(fd, response);
            break;
        case SMTP_STATE_MAILFROM:
            eventProcessMAILFROMResponse(fd, response);
            break;
        case SMTP_STATE_RCPTTO:
            eventProcessRCPTTOResponse(fd, response);
            break;
        case SMTP_STATE_DATA:
            eventProcessDATAResponse(fd, response);
            break;
        case SMTP_STATE_SENDING:
            eventProcessDataSentResponse(fd, response);
            break;
        case SMTP_STATE_FINISHED:
            eventProcessQUITResponse(fd, response);
            break;
        default:
            eventCloseSocket(fd);
            eventReportEmailError(__MessageQueue[fd], "Invalid email message state value "+__MessageQueue[fd]->State+".");
            break;
    }
}

private nomask void eventWriteData(int fd, string data)
{
    int retcode = EESUCCESS;
    
    while (data)
    {
        if (!__MessageQueue[fd]->CanWrite)
        {
            call_out( (: eventWriteData :), 3, fd, data);
            return;
        }
        
        retcode = socket_write(fd, data);
        switch (retcode)
        {
            case EESUCCESS:
                // Success!
                data = 0;
                break;
            case EECALLBACK:
                // Success, but wait for callback to send more
                data = 0;
                __MessageQueue[fd]->CanWrite = 0;
                break;
            case EEWOULDBLOCK:
                // Blocked, Send same data again after callback
                __MessageQueue[fd]->CanWrite = 0;
                continue;
            case EEALREADY:
            default:
                // Error. Flow control violated.
                eventSocketError(__MessageQueue[fd], "Error in socket_write().", retcode);
                eventCloseSocket(fd);
                return;
        }
    } 
}

void eventCanWriteData(int fd)
{
    if (member_array(fd, keys(__MessageQueue)) == -1)
    {
        eventCloseSocket(fd);
        error("Able to write on socket "+fd+", but there was no associated email message data.");
        return;
    }
    
    __MessageQueue[fd]->CanWrite = 1;
}

void eventCloseSocket(int fd)
{
    map_delete(__MessageQueue, fd);
    socket_close(fd);
}

private nomask void eventProcessInitialResponse(int fd, string response)
{
    if (response[0..2] == "220")
    {
        eventSendHELOCommand(fd);
    }
    else
    {
        eventReportEmailError(__MessageQueue[fd], "Recieved non-OK initial response from SMTP server: "+response);
        eventCloseSocket(fd);
    }
}

private nomask void eventProcessHELOResponse(int fd, string response)
{
    if (response[0..2] == "250")
    {
        // OK!
        eventSendMAILFROMCommand(fd);
    }
    else
    {
        eventReportEmailError(__MessageQueue[fd], "Recieved non-OK HELO response from SMTP server: "+response);
        eventCloseSocket(fd);
    }
}

private nomask void eventProcessMAILFROMResponse(int fd, string response)
{
    if (response[0..2] == "250")
    {
        // OK!
        eventSendRCPTTOCommand(fd);
    }
    else
    {
        eventReportEmailError(__MessageQueue[fd], "Recieved non-OK MAIL FROM response from SMTP server: "+response);
        eventCloseSocket(fd);
    }
}

private nomask void eventProcessRCPTTOResponse(int fd, string response)
{
    if (response[0..2] == "250")
    {
        // OK! If we have more recipients, send more of these, otherwise send the data
        if (sizeof(__MessageQueue[fd]->Recipients))
        {
            eventSendRCPTTOCommand(fd);
        }
        else
        {
            eventSendDATACommand(fd);
        }
    }
    else if (response[0..2] == "251")
    {
        eventReportEmailError(__MessageQueue[fd], "Recieved response from SMTP server that indicates a forwarded email. "+
                                                  "Send the email to the new address manually. Response: "+response);
        eventCloseSocket(fd);
    }        
    else
    {
        eventReportEmailError(__MessageQueue[fd], "Recieved non-OK RCPT TO response from SMTP server: "+response);
        eventCloseSocket(fd);
    }
}

private nomask void eventProcessDATAResponse(int fd, string response)
{
    if (response[0..2] == "354")
    {
        // OK!
        eventSendDataContents(fd);
    }  
    else
    {
        eventReportEmailError(__MessageQueue[fd], "Recieved non-OK DATA response from SMTP server: "+response);
        eventCloseSocket(fd);
    }
}

private nomask void eventProcessDataSentResponse(int fd, string response)
{
    if (response[0..2] == "250")
    {
        // OK!
        eventSendQUITCommand(fd);
    }  
    else
    {
        eventReportEmailError(__MessageQueue[fd], "Recieved non-OK END OF DATA response from SMTP server: "+response);
        eventCloseSocket(fd);
    }
}

private nomask void eventProcessQUITResponse(int fd, string response)
{
    // No matter the response, we already sent the message. Report success.
    eventReportEmailSuccess(__MessageQueue[fd]);
    eventCloseSocket(fd);
}

private nomask void eventSendHELOCommand(int fd)
{
    __MessageQueue[fd]->State = SMTP_STATE_HELO;
    eventWriteData(fd, "HELO ["+HOST_IP+"]\r\n");
}

private nomask void eventSendMAILFROMCommand(int fd)
{
    __MessageQueue[fd]->State = SMTP_STATE_MAILFROM;
    eventWriteData(fd, "MAIL FROM: "+ADMIN_EMAIL+"\r\n");
}

private nomask void eventSendRCPTTOCommand(int fd)
{
    __MessageQueue[fd]->State = SMTP_STATE_RCPTTO;
    
    eventWriteData(fd, "RCPT TO: "+__MessageQueue[fd]->Recipients[0]+"\r\n");

    if (sizeof(__MessageQueue[fd]->Recipients) > 1)
    {
        __MessageQueue[fd]->Recipients = __MessageQueue[fd]->Recipients[1..];
    }
    else
    {
        __MessageQueue[fd]->Recipients = ({ });
    }
}

private nomask void eventSendDATACommand(int fd)
{
    __MessageQueue[fd]->State = SMTP_STATE_DATA;
    eventWriteData(fd, "DATA\r\n");
}

private nomask void eventSendDataContents(int fd)
{
    __MessageQueue[fd]->State = SMTP_STATE_SENDING;
    eventWriteData(fd, __MessageQueue[fd]->Body);
    eventWriteData(fd, "\r\n.\r\n");
}

private nomask void eventSendQUITCommand(int fd)
{
    __MessageQueue[fd]->State = SMTP_STATE_FINISHED;
    eventWriteData(fd, "QUIT\r\n");
}
