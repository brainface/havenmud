
/*  
 *  A player listing cmd.
 *  Idea taken from 'immortals' cmd
 *  Much more could be done with this for nifty player profiling
 *
 *  Created by Zaxan@Haven
 */
#include <lib.h>
#include <dirs.h>

inherit LIB_DAEMON;
inherit LIB_HELP;

private int Level, TestChar;
private string CapName;

int sort_by_level(string player1, string player2);

static void create() {
  daemon::create();
  SetNoClean(1);
  }

mixed cmd(string rank) {
    int total = 0;
    object who = this_player();

    string *Newbies = ({ });
    string *Mortals = ({ });
    string *HighMortals = ({ });
    string *Legends = ({ });
    string *Avatars = ({ });
    string *DemiGods = ({ });
    string *Epics = ({ });
    string *dirs = unguarded( (: get_dir, DIR_PLAYERS  "/" :));

    if (!archp(who))
    {
	return "Sorry, this info isn't for you.";
    }
  
  foreach(string letter in dirs) {
    string *files = unguarded( (: get_dir, DIR_PLAYERS  "/" + 
                                           letter + "/" :) );
    foreach(string file in files) {
	string desc;
        
	unguarded( (: restore_object, DIR_PLAYERS  "/" + letter + "/" + file[0..strlen(file)-3] :) );
	desc = CapName+"("+Level+")";

	if (TestChar)
	    continue;

	if (Level < 5)
	{
	    Newbies += ({ desc });
	}
	else if (Level < 25)
	{
	    Mortals += ({ desc });
	}
	else if (Level < 50)
	{
	    HighMortals += ({ desc });
	}
	else if (Level < 100)
	{
	    Legends += ({ desc });
	}
	else if (Level < 250)
	{
	    Avatars += ({ desc });
	}
        else if (Level < 300)
        {
            DemiGods += ({ desc });
        }
        else Epics += ({ desc });
    }
  }

  if (sizeof(Epics))
  {
      who->eventPrint("Epics:");
      foreach(string player in sort_array(Epics, (: sort_by_level :)))
      {
          who->eventPrint("\t"+player);
      }
  }
  if (sizeof(DemiGods))
  {
      who->eventPrint("Demi-Gods:");
      foreach(string player in sort_array(DemiGods, (: sort_by_level :)))
      {
	  who->eventPrint("\t"+player);
      }
  }
  if (sizeof(Avatars))
  {
      who->eventPrint("Avatars:");
      foreach(string player in sort_array(Avatars, (: sort_by_level :)))
      {
	  who->eventPrint("\t"+player);
      }
  }
  if (sizeof(Legends))
  {
      who->eventPrint("Legends:");
      foreach(string player in sort_array(Legends, (: sort_by_level :)))
      {
	  who->eventPrint("\t"+player);
      }
  }
  if (sizeof(HighMortals))
  {
      who->eventPrint("High Mortals:");
      foreach(string player in sort_array(HighMortals, (: sort_by_level :)))
      {
	  who->eventPrint("\t"+player);
      }
  }
  if (sizeof(Mortals))
  {
      who->eventPrint("Mortals:");
      foreach(string player in sort_array(Mortals, (: sort_by_level :)))
      {
	  who->eventPrint("\t"+player);
      }
  }
  if (sizeof(Newbies))
  {
      who->eventPrint("Newbies:");
      foreach(string player in sort_array(Newbies, (: sort_by_level :)))
      {
	  who->eventPrint("\t"+player);
      }
  }

  total = sizeof(DemiGods)+sizeof(Avatars)+sizeof(Legends)+sizeof(HighMortals)+sizeof(Mortals)+sizeof(Newbies);
  who->eventPrint("\nTotal player base: "+total+" players.");
  return 1;
}

string GetHelp()
{
    return "Syntax: <mortals>\n\n"
	   "Lists the entire playerbase sorted by rank, level and name.";
}

int sort_by_level(string player1, string player2)
{
    string name;
    int level1 = 0;
    int level2 = 0;
    int result = 0;

    sscanf(player1, "%s(%d)", name, level1);
    sscanf(player2, "%s(%d)", name, level2);

    result = level2 - level1;
    if (result == 0)
    {
	return strcmp(player1, player2);
    }
    else
    {
	return result;
    }
}
