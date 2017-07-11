//      /bin/adm/_broadcast.c
//      from the Nightmare mudlib
//      like shout, except that it overrides ALL blocking
//      created by Descartes of Borg 930823

#include <lib.h>
#include <daemons.h>

inherit LIB_DAEMON;

int cmd(string str) {

    object who = this_player(); 

    if(!archp(previous_object())) return 0;
    message("system", sprintf("%s",str),users() );
    CHAT_D->eventSendChannel("Echo Report", "reports", capitalize(who->GetName()) + " echoed to the mud: " + str);
    return 1;
}

string GetHelp (string blah) {
    return "Syntax: <echomud [message]>\n\n"
           "Sends out the passed message to all users, exactly as "
           "written, including any ansi used (see /doc/build/ansi). "
           "It is particularly useful for RP messages. Do not use this "
           "for shout matches!\n\n"
           "See also: broadcast, echo";
}
