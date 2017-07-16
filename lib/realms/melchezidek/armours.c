#include <lib.h>
#include <armour_class.h>
inherit LIB_DAEMON;
string GetArmourClass(int ac);
string BuildPrint(string var, string limb, object who);

mixed cmd(string args) {
  object who;
  string targstr;
  array limbs;
  string ret;
	string arms;
	string torso;
	string head;
	string legs;
	string other;

  if (creatorp(this_player()) && (!args)) {
    return "You must specify a target.";
   }
  if (!creatorp(this_player())) { who = this_player(); }
  else { who = find_living(args); }
  if (!who) {
    return "No such person.";
    }
  if (who == this_player()) { targstr = "You are "; }
     else { targstr = who->GetCapName() + " is "; }

  limbs = sort_array(who->GetLimbs(), 1);
  foreach(string local in limbs) {
	if(who->GetLimbClass(local) == 1 && sizeof(who->GetLimbChildren(local)) > 1) {
		torso = local + ":\n"; //this is my main limb
		if(sizeof(who->GetWorn(local))) torso += BuildPrint(torso, local, who);
		foreach(string limb in sort_array(who->GetLimbChildren(local), 1)) {
			if(regexp(limb, "^head$")) {
				head = limb + ":\n";
				if(sizeof(who->GetWorn(limb))) head += BuildPrint(head, limb, who);
			}
			if(regexp(limb,  "arm$")) { 
				if(arms) {
					arms += limb + ":\n";
					if(sizeof(who->GetWorn(limb))) arms += BuildPrint(arms, limb, who);
				} else {
					arms = limb + ":\n";
                    if(sizeof(who->GetWorn(limb))) arms += BuildPrint(arms, limb, who); 
				}
				foreach(string subchild in who->GetLimbChildren(limb)) {
					arms += subchild + ":\n";
					if(sizeof(who->GetWorn(subchild))) arms += BuildPrint(arms, subchild, who);
				}
			}
            if(regexp(limb,  "leg$")) { 
                if(legs) {
                    legs += limb + ":\n";
                    if(sizeof(who->GetWorn(limb))) legs += BuildPrint(legs, limb, who);
                } else {
                    legs = limb + ":\n";
                    if(sizeof(who->GetWorn(limb))) legs += BuildPrint(legs, limb, who);        
                }
            	foreach(string subchild in who->GetLimbChildren(limb)) {
               		 legs += subchild + ":\n";
               		 if(sizeof(who->GetWorn(subchild))) legs += BuildPrint(legs, subchild, who);
            	}
            }
			// Other limbs done here -> tail/wings/etc
			if(!regexp(limb, "(leg$|arm$|^head$|^torso$)")) {
				if(!other) {
					other = limb + ":\n";
					if(sizeof(who->GetWorn(limb))) other += BuildPrint(other, limb, who);
				} else {
					other += limb + ":\n";
					if(sizeof(who->GetWorn(limb))) other += BuildPrint(other, limb, who);
				}
                foreach(string subchild in who->GetLimbChildren(limb)) { //this is probably unnecessary but
                     other += subchild + ":\n";                          //added for good measure
                     if(sizeof(who->GetWorn(subchild))) other += BuildPrint(legs, subchild, who);
                }

			} 
		}
	
		ret = head + torso; 
		if(arms) ret = ret + arms; 
		if(legs) ret = ret + legs;
		if(other) ret = ret + other; 
		this_player()->eventPrint(ret);
	}

	}   
	return 1;
}

string BuildPrint(string var, string limb, object who) {
	string x;
	
    foreach(object thing in (who->GetWorn(limb))) {
		if(!x) {
	    	x = "   (" + GetArmourClass(thing->GetArmourClass()) + ") " + thing->GetKeyName() + " (" + (thing->GetDeterioration() * 10) + "% damaged)\n";
		} else {
		x += "   (" + GetArmourClass(thing->GetArmourClass()) + ") " + thing->GetKeyName() + " (" + (thing->GetDeterioration() * 10) + "% damaged)\n";
		}
	}
	return x;
}

string GetArmourClass(int ac) {
  string a_type;
   if (!ac)                      a_type = "Non-Armour";
   if (ac == ARMOUR_CLOTH      ) a_type = "T1 cloth";           
   if (ac == ARMOUR_LEATHER    ) a_type = "T2 leather";     
   if (ac == ARMOUR_REINFORCED ) a_type = "T3 reinforced"; 
   if (ac == ARMOUR_NATURAL    ) a_type = "T4 natural";
   if (ac == ARMOUR_CHAIN      ) a_type = "T5 chain";         
   if (ac == ARMOUR_PLATE      ) a_type = "T6 plate";         
   if (ac == ARMOUR_HEAVY_PLATE) a_type = "T7 heavy plate";   
   return a_type;
}

string GetHelp(string s) {
  return "Syntax:   armours \n"
         "Displays a list of all equipped armour, including current status and armour type. \n"
         "Armour types are ranked tier 1 thru 7 depending on protection value of armour.";
}         
