/*    /daemon/services/tell.c
 *    from the Dead Souls LPC Library
 *    handles the IMP tell service
 *    created by Descartes of Borg 950507
 */

#define SERVICE_TELL

#include <daemons.h>
#include <message_class.h>

void eventReceiveTell(mixed *packet) {
    object ob;
    string who;
	  string msg;

    if( file_name(previous_object()) != INTERMUD_D ) return;
    who = convert_name(packet[5]);
    if (packet[6] == "Guest") return;
    if( !(ob = find_player(who)) || (int)ob->GetInvis() ) {
	      INTERMUD_D->eventWrite(({ "error", 5, mud_name(), 0, packet[2], packet[3], "unk-user",  capitalize(packet[5]) + " is nowhere to " "be found on " + mud_name() + ".", packet }));
	      return;
        }
    if (!creatorp(ob)) { INTERMUD_D->eventWrite(({"error", 5, mud_name(),  0, packet[2], packet[3], "unk-user", "That person is a player.  Leave them alone.", packet }));
        return;
        }
	  msg = "%^BOLD%^RED%^" + packet[6] + "@" + packet[2] + " tells you:%^RESET%^ " + packet[7]; ob->eventPrint(msg, MSG_CONV);
	  ob->AddRemoteTellHist(msg);
    ob->SetProperty("reply", packet[6] + "@" + packet[2]);
}

void eventSendTell(string who, string where, string msg) {
    string pl, plc;
    if (this_player()) {
      pl = (string)this_player(1)->GetName();
      plc = (string)this_player(1)->GetCapName();
    } else {
      pl = who;
      plc = capitalize(who);
    }
    where = (string)INTERMUD_D->GetMudName(where);
    INTERMUD_D->eventWrite(({ "tell", 5, mud_name(), pl, where,  convert_name(who), plc, msg }));
	  msg = "%^BOLD%^RED%^You tell " + capitalize(who) + "@" +  where + ":%^RESET%^ " + msg;
    if (this_player()) this_player(1)->eventPrint(msg, MSG_CONV);
    if (this_player()) this_player(1)->AddRemoteTellHist(msg);
 //   if (!this_player()) CHAT_D->eventSendChannel("20 Char", "spam", msg);
}

    

    
