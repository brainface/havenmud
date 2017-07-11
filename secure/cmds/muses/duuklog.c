/*
 * duuklog cmd
 * 
 * Written by Thoin@Haven
 */

#include <lib.h>

inherit LIB_DAEMON;

mixed cmd(string str) {
    object tp = this_player();
    
    if (!archp(tp)) {
        tp->eventPrint("You cannot use this command as it is assumed that "
        "immortals of your rank never do anything but idle.");
        return 1;
    }
    if (!str) return "Idiot, you didn't provide an update.";
    if (write_file("/doc/help/immortals/changelog", "\n** " + ctime(time()) + " by " + capitalize(tp->GetKeyName()) + " **/\n" + str + "\n ") )
      tp->eventPrint("File /doc/help/immortals/changelog has been updated.");
    else tp->eventPrint("Command fuckup.");
    return 1;
}

string GetHelp() {
    return ("Syntax: duuklog <string>\n\n"
            "Allows someone(mostly duuk) to append the changelog(/doc/help/immortals/changelog) "
            "with recent changes made to "
            "the lib or other things duuk does, like recode small countries.");
}
