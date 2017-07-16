#include <lib.h>
inherit LIB_DAEMON;

mixed cmd(string ar) {
    this_player()->SetInvis(0);
    users()->eventPrint(this_player()->GetMessage("svis"));
    return 1;
}

string GetHelp(string blah) {
    return "Syntax: <svis>\n\n"
           "This command will broadcast your svis message. Use "
           "the message command to see what you currently have "
           "your svis set to. This is intended as an rp-appropriate "
           "way for an immortal to signal their arrival to the mud. "
           "Do not over-use it.\n\n"
           "See also: message";
}
