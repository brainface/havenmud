/*
 * approvecode cmd
 * Used by QA ppl to approve code
 * 
 * Written by Zaxan@Haven
 */

#include <lib.h>

inherit LIB_DAEMON;

int cmd(string str) {
    object tp = this_player();
    
    if (!adminp(tp) && !member_group(tp, "APPROVAL"))
    {
	tp->eventPrint("You are not a member of the code approval group.");
	return 1;
    }

    if (!file_exists(str))
    {
	str = tp->query_cwd() + "/" + str;
    }

    if (!file_exists(str))
    {
	tp->eventPrint("The file " + str + " could not be found.");
	return 1;
    }

    if (str[<2..] != ".c")
    {
	tp->eventPrint("You can only approve code files that end in '.c'.");
	return 1;
    }

    if (!unguarded( (: write_file, str, "\n/** Approved by " + capitalize(this_player()->GetKeyName()) + " at " + ctime(time()) + ". **/", 0 :) ))
    {
	tp->eventPrint("An error occurred when appending to " + str + ".");
	return 1;
    }

    unguarded( (: log_file, "adm/code_approval", capitalize(this_player()->GetKeyName()) + " approved " +
		  str + " at " + ctime(time()) + ".\n" :) );

    tp->eventPrint("File " + str + " has been approved.");
	
    return 1;
}

string GetHelp() {
    return ("Syntax: approvecode <file>\n\n"
            "Allows a member of the code approval group to approve a piece "
	    "of code. This means that the code is approved to go into the "
	    "game. It does this by adding a comment to the end of the specified"
	    "file.");
}

/** Approved by Zaxan at Tue Jul  6 00:54:26 2004. **/
