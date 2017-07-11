/*    /cmds/creator/which.c
 *    From the Dead Souls V Object Library
 *    gives you a list of directories in which a command may be found
 *    created by Descartes of Borg 950913
 *    Version: @(#) which.c 1.2@(#)
 *    Last modified: 96/10/08
 *
 *    Modified by Zaxan@Haven to also search
 *    for spells, songs, and verbs
 */

#include <lib.h>
#include <daemons.h>
#include <message_class.h>

inherit LIB_DAEMON;

mixed cmd(string args) {
    string array dirs;
    mapping verbs = VERBS_D->GetVerbs();
    string dir, *found = ({ });
    object spell, song;

    if( !args ) {
	return "You want to know information on which command/spell/song/verb?";
    }
    dirs = CMD_D->GetPaths(args);
    if (sizeof(dirs))
    {
	foreach(dir in dirs)
	{
	    found += ({ dir+"/"+args+".c" });
	}
    }

    spell = SPELLS_D->GetSpell(args);
    if (spell && !undefinedp(spell))
    {
	found += ({ base_name(spell)+".c" });
    }

    song = SONGS_D->GetSong(args);
    if (song && !undefinedp(song))
    {
	found += ({ base_name(song)+".c" });
    }

    if (member_array(args, keys(verbs)) != -1)
    {
	found += ({ verbs[args] });
    }

    if (!sizeof(found))
    {
	return args + ": not found.";
    }

    this_player()->eventPrint(args+":");
    foreach(string str in found)
    {
	this_player()->eventPrint("\t"+str);
    }

    return 1;
}

string GetHelp() {
    return ("Syntax: <which [command|song|spell|verb]>\n\n"
	    "Gives you a listing of all directories in which a command, "
	    "spell, song or verb may be found.\n\n"
	    "See also: help, man");
}
