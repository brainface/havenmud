/*    /cmds/creator/mwhich.c
 *    Basically which.c with an if statement added.
 *    Zedd@Haven 09/11/2004 08:32PM
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

  if (sizeof(found) == 1)
  {
    this_player()->eventPrint("");
    load_object("/secure/cmds/creators/more.c")->cmd(found[0]);
  }
  else
  {
    return "Too many results.  Use 'which' to decide what to look at.";
  }

  return 1;
}

string GetHelp()
{
    return ("Syntax: <mwhich [command|song|spell|verb]>\n\n"
	    "Locates the given item, and 'more's it for you.\n\n"
	    "See also: help, man");
}
