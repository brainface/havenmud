/*    /cmds/player/emote.c
 *    from the Dead Souls LPC Library
 *    for those times when you are feeling emotional
 *    created by Descartes of Borg 950412
 */

#include <lib.h>
#include <daemons.h>

inherit LIB_DAEMON;

mixed cmd(string args) {
  if (this_player()->GetSleeping()) { return "You are asleep."; }
    if( !args || args == "" ) {
        message("my_action", "You are feeling emotional.", this_player());
        message("other_action", (string)this_player()->GetName() +
                " looks emotional.", environment(this_player()),
                ({ this_player() }));
        return 1;
    }
    if( args[0] != '\'' ) args = " " + args;
    message("my_action", this_player()->GetName() +
            args, this_player());
    message("other_action", (string)this_player()->GetName() + args,
            environment(this_player()), ({ this_player() }) );
    if (userp(this_player()) && !creatorp(this_player()) )
    CHAT_D->eventSendChannel("EMOTE_CMD", "souls",
         this_player()->GetKeyName() + " emoted: " + args, 1);
    return 1;
}

string GetHelp(string blah) {
    return "Syntax: <emote [message]>\n\n"
             "Places any message you specify directly after your name. "
             "For example, \"emote smiles.\" would have others see "
             "\"Duuk smiles.\". This command is intended to enhance role-"
           "play by allowing use of more complex emotions than those "
           "encompassed by the souls (also called emotes or feelings). "
           "Attempting use this command to circumvent languages will "
           "result in discipline.\n\n"
           "See also: adverbs, feelings";
}

