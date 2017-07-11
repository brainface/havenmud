//      /bin/dev/_elog.c
//      from the Dead Souls Mudlib
//      tails error logs
//      created by Descartes of Borg 930813

#include <lib.h>
#include <dirs.h>

inherit LIB_DAEMON;

int cmd(string str) {
     if(!str) str = DIR_ERROR_LOGS+"/"+(string)previous_object()->GetKeyName();
    else str = DIR_ERROR_LOGS+"/"+str;
    write(str+":\n");
    if(!tail(str)) write("No errors in "+str+".\nTry /log/debug.log.\n");
    return 1;
}

string GetHelp(string blah) {
    return "Syntax: <elog>\n"
           "        <elog [error log]>\n\n"
           "This command by itself will tail your personal error log. "
           "With an argument, it searches for a file by that name in the "
           "mud's error log directory. Examples of possible names include "
           "domain or directory names, e.g. <elog averath>, <elog verbs>\n\n"
           "See also: rlog, replog";
}
