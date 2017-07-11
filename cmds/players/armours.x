#include <lib.h>
#include <armour_class.h>
inherit LIB_DAEMON;
string GetArmourClass(int ac);

mixed cmd(string args) {
  object who;
  string targstr;

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

  foreach(string local in (who->GetLimbs())) {
    this_player()->eventPrint(local + ":");
   foreach(object thing in (who->GetWorn(local))) {
      this_player()->eventPrint("   (" + GetArmourClass(thing->GetArmourClass()) + ") " + thing->GetKeyName() + " (" + (thing->GetDeterioration() * 10) + "% damaged)");
      }
   }

  return 1;
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