 /*   /secure/cmds/sages/removelanguage.c
  *   removes languages from the language daeamon
  *   balishae@haven
  *   7/99
  */

#include <lib.h>
#include <daemons.h>

inherit LIB_DAEMON;


mixed cmd(string args)
{
    if( !args || args == "" ) return "Syntax: <removelanguage LANGUAGE>";
    LANGUAGE_D->RemoveLanguage(args);
    previous_object()->eventPrint("Language removed.");
    return 1;
}

string GetHelp(string str) {
    return ("Syntax: <removelanguage LANGUAGE>\n\n"
            "Removes a language from the game.\n\n"
            "See also: addlanguage");
}
