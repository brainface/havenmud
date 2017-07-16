/* High Score Command
 * Well, because I wanted to code something fun.
 * Duuk
 * 9/11/04
 */
#include <dirs.h>
#include <lib.h>
#include <daemons.h>

int Level;
string *Religion;
string Town;
string Race;
string CapName, Class;
int TestChar, Retired;

int eventSortPlayers(object who);
int eventSortTowns(object who);
int eventSortReligions(object who);
int eventSortRaces(object who);

mixed cmd(string command) {
	object who = this_player();
	
	switch(command) {
		case "players":
		  eventSortPlayers(who);
		  break;
		case "towns":
		  eventSortTowns(who);
		  break;
		case "religions":
		  eventSortReligions(who);
		  break;
		case "races":
		  eventSortRaces(who);
		  break;
		default:
		  who->eventPrint("Sort players, towns, races, or religions?");
		  break;
		}
  return 1;
}

int eventSortPlayers(object who) {
	string *dirs = unguarded( (: get_dir, DIR_PLAYERS  "/" :));
	string *top20 = ({ });
	int *levels = ({ });
	string *ch_class = ({ });
	string *races = ({ });
	string *towns = ({ });
	int i;
	top20 = allocate(20);
	levels = allocate(20);
	ch_class = allocate(20);
	races = allocate(20);
	towns = allocate(20);
	
	foreach(string letter in dirs) {
    string *files = unguarded( (: get_dir, DIR_PLAYERS +
                                  "/" + letter + "/" :) );
    foreach(string file in files) {
	    TestChar = 0;
	    unguarded( (: restore_object, DIR_PLAYERS + "/" 
	                  + letter + "/" + file[0..strlen(file)-3] :) );
	    if (TestChar) continue;
	    i = 20;              
	    while(i) {
	      if (Level > levels[i - 1]) {
	    	  if (i != 20) { 
	    		  levels[i] = levels[i - 1];
	    		  top20[i] = top20[i - 1];
	    		  ch_class[i] = ch_class[i - 1];
	    		  towns[i] = towns[i -1];
	    		  races[i] = races[i-1];
	    		}
	    	  levels[i - 1] = Level;
	    	  top20[i - 1] = CapName;
	    	  ch_class[i - 1] = Class;
	    	  towns[i - 1] = Town;
	    	  races[i - 1] = Race;
	    	  if (Retired) top20[i - 1] += " (Retired)";
	    	}
	    i--;
	    }
	  }
	}
	who->eventPrint("Top 20 Players on Haven");
	for(i = 0; i <20; i++) {
     if (adminp(who)) who->eventPrint(sprintf("%2d)  %-12s (%3d) %10s %-12s (%s)", i + 1, top20[i], levels[i], races[i], towns[i], ch_class[i] ? ch_class[i] : "twink"));
     else who->eventPrint(sprintf("%2d)  %-15s", i + 1, top20[i]));
		}
	return 1;
}

int eventSortTowns(object who) {
	mapping towns = ([]);
  string *dirs = unguarded( (: get_dir, DIR_PLAYERS  "/" :));
  Level = 0;
		foreach(string letter in dirs) {
    string *files = unguarded( (: get_dir, DIR_PLAYERS +
                                  "/" + letter + "/" :) );
    foreach(string file in files) {
	    TestChar = 0;
	    unguarded( (: restore_object, DIR_PLAYERS + "/" 
	                  + letter + "/" + file[0..strlen(file)-3] :) );
	    if (TestChar) continue;
	    if (Level < 5) continue;
	    towns[Town]++;
	  }
	}
  who->eventPrint("Town Report for Haven's Mortal+ Population");
	foreach(string t in keys(towns)) {
		who->eventPrint(sprintf("%-12s has %3d citizens", t, towns[t]));
		}
	return 1;
}

int eventSortRaces(object who) {
		mapping towns = ([]);
    string *dirs = unguarded( (: get_dir, DIR_PLAYERS  "/" :));
    Level = 0;
		foreach(string letter in dirs) {
    string *files = unguarded( (: get_dir, DIR_PLAYERS +
                                  "/" + letter + "/" :) );
    foreach(string file in files) {
	    TestChar = 0;
	    unguarded( (: restore_object, DIR_PLAYERS + "/" 
	                  + letter + "/" + file[0..strlen(file)-3] :) );
	    if (TestChar) continue;
	    if (Level < 5) continue;
	    towns[Race]++;
	  }
	}
  who->eventPrint("Racial Report for Haven's Mortal+ Population");
	foreach(string t in keys(towns)) {
		who->eventPrint(sprintf("There are %3d %12s", towns[t], pluralize(t)));
		}
	return 1;
}

int eventSortReligions(object who) {
		mapping towns = ([]);
  string *dirs = unguarded( (: get_dir, DIR_PLAYERS  "/" :));
  Level = 0;
		foreach(string letter in dirs) {
    string *files = unguarded( (: get_dir, DIR_PLAYERS +
                                  "/" + letter + "/" :) );
    foreach(string file in files) {
	    TestChar = 0;
	    unguarded( (: restore_object, DIR_PLAYERS + "/" 
	                  + letter + "/" + file[0..strlen(file)-3] :) );
	    if (TestChar) continue;
	    if (Level < 5) continue;
	    towns[Religion[0]]++;
	  }
	}
  who->eventPrint("Religion Report for Haven's Mortal+ Population");
	foreach(string t in keys(towns)) {
		who->eventPrint(sprintf("There are %3d members of the %12s faith", towns[t], (t)));
		}
	return 1;
}

string GetHelp(string dir) {
	return "Syntax:    highscore <option>\n\n"
	       "With use of the options (players, religions, towns, races), you can see "
	       "which players are highest level, which religions, towns, and races have "
	       "the most followers.  Quite a fun but useless command.";
}
