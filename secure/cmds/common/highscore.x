/* High Score Command
 * Well, because I wanted to code something fun.
 * Duuk
 * 9/11/04
 */
#include <dirs.h>
#include <lib.h>
#include <daemons.h>

int Level;
mapping Skills;
string *Religion;
string Town;
string Race;
string CapName, Class;
int TestChar, Retired;
mapping VarM;

int eventSortPlayers(object who);
int eventSortTowns(object who);
int eventSortReligions(object who);
int eventSortRaces(object who);
int eventSortClasses(object who);

string GetHighestValue(string *str, mapping mapp) {
  string tmp;
  tmp = str[0];
  foreach(string s in str) {
    if (mapp[tmp] < mapp[s]) tmp = s;
  }
//  debug("foo = " + tmp);
  return tmp;
} 

string *sort_mapping(mapping m) {
  string *tmp = ({ });
  string foo;
  string *newtmp = ({ });
  int i;
  tmp = keys(m);
  i = sizeof(tmp);
//  debug("i = " + i);
  while(i > 1) {
    foo = GetHighestValue(tmp, m);
    newtmp += ({ foo });
    tmp -= ({ foo });
    i = sizeof(tmp);
//    debug("i = " + i);
//  debug("newtmp size = " + sizeof(newtmp));
  }
  return newtmp;
}   
  
  
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
		case "classes":
		  eventSortClasses(who);
		  break;
		default:
		  who->eventPrint("Sort players, towns, races, classes or religions?");
		  break;
		}
  return 1;
}

int FigureScore() {
  mapping sk = Skills;
  int score = 0, sk_bonus = 0;
  foreach(string skill in keys(sk)) {
    sk_bonus = SKILLS_D->GetSkillCost(skill);
    if (sk[skill]["class"] == 1)  sk_bonus = sk_bonus * 3;
    if (sk[skill]["class"] == 2)  sk_bonus = sk_bonus * 2;  
    score += sk[skill]["level"] * sk_bonus;
  }
  return score;
}

int FigureMyScore() {
  string *sk = this_player()->GetSkills();
  int score = 0, sk_bonus = 0;
  foreach(string skill in (sk)) {
    sk_bonus = SKILLS_D->GetSkillCost(skill);
    if (this_player()->GetSkillClass(skill) == 1)  sk_bonus = sk_bonus * 3;
    if (this_player()->GetSkillClass(skill) == 2)  sk_bonus = sk_bonus * 2;  
    score += this_player()->GetSkillLevel(skill) * sk_bonus;
  }
  return score;
}


int DiffPoints(int i, int *ilist) {
  if (i == 0) return 0;
  return ilist[i - 1] - ilist[i];
}  

int eventSortPlayers(object who) {
	string *dirs = unguarded( (: get_dir, DIR_PLAYERS  "/" :));
	string *top20 = ({ });
	int *levels = ({ });
	int *clevels = ({ });
	string *ch_class = ({ });
	string *races = ({ });
	string *towns = ({ });
	int i, myrank;
	int sc = 0;
	int playercount = 0;
	top20 = allocate(60);
	levels = allocate(60);
	clevels = allocate(60);
	ch_class = allocate(60);
	races = allocate(60);
	towns = allocate(60);
	
	
	foreach(string letter in dirs) {
    string *files = unguarded( (: get_dir, DIR_PLAYERS +
                                  "/" + letter + "/" :) );
    foreach(string file in files) {
	    TestChar = 0;
	    unguarded( (: restore_object, DIR_PLAYERS + "/" 
	                  + letter + "/" + file[0..strlen(file)-3] :) );
	    if (TestChar) continue;
	    playercount++;
	    sc = FigureScore();
	    i = 50;              
	    while(i) {
	      if (sc > levels[i - 1]) {
	    	  if (i != 50) { 
	    		  clevels[i] = clevels[i -1];
	    		  levels[i] = levels[i - 1];
	    		  top20[i] = top20[i - 1];
	    		  ch_class[i] = ch_class[i - 1];
	    		  towns[i] = towns[i -1];
	    		  races[i] = races[i-1];
	    		}
	    	  levels[i - 1] = sc;
	    	  clevels[i - 1] = Level;
	    	  top20[i - 1] = CapName;
	    	  ch_class[i - 1] = Class;
	    	  towns[i - 1] = Town;
	    	  races[i - 1] = Race;
	    	  if (Retired) top20[i - 1] += " (R)";
	    	}
	    i--;
	    }
	  }
	}
	who->eventPrint("Top Players on Haven");
	if (securep(who)) {
	  who->eventPrint(sprintf("%4s %-15s  %3s (%6s) %10s %-12s (%s)", "Rank", "Name", "Lvl", "Points", "Race", "Town", "Class"));
	} else {
	  who->eventPrint(sprintf("%4s %-15s %6s", "Rank", "Name", "Points Behind Next Higher"));
	}
	if (playercount > 50) playercount = 50;
	for(i = 0; i <playercount; i++) {
     if (capitalize(who->GetKeyName()) == top20[i]) myrank = i + 1;
     if (securep(who)) who->eventPrint(sprintf("%2d)  %-15s  %3d (%6d) %10s %-12s (%s)", i + 1, top20[i], clevels[i], levels[i], races[i], towns[i], ch_class[i] ? ch_class[i] : "twink"));
     else who->eventPrint(sprintf("%2d)  %-15s %6d", i + 1, top20[i], DiffPoints(i, levels)));
		}
	if (playerp(who)) {
	  if (myrank) who->eventPrint("You are ranked #" + myrank + ".");
	  else who->eventPrint("You require " + (levels[49] - FigureMyScore()) + " more points to be on the list!");
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
	foreach(string t in sort_mapping(towns)) {
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
	foreach(string t in sort_mapping(towns)) {
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
	foreach(string t in sort_mapping(towns)) {
		who->eventPrint(sprintf("There are %3d members of the %12s faith", towns[t], (t)));
		}
	return 1;
}

int eventSortClasses(object who) {
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
	    if (!Class) Class = "classless";
	    towns[Class]++;
	  }
	}
  who->eventPrint("Class Report for Haven's Mortal+ Population");
	foreach(string t in sort_mapping(towns)) {
		who->eventPrint(sprintf("There are %5d %-20s", towns[t], pluralize(t)));
		}
	return 1;
}


string GetHelp(string dir) {
	return "Syntax:    highscore <option>\n\n"
	       "With use of the options (players, religions, towns, races), you can see "
	       "which players are highest level, which religions, towns, and races have "
	       "the most followers.  Quite a fun but useless command.";
}
