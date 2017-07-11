#include <lib.h>
#include "haven.h"
inherit LIB_TOWNGUARD;
void ChatRes();
int CheckWanted();
#include "../wanted.h"

static void create() {
  ::create();
  SetKeyName("Haven Town Guard");
  SetFriends( ({ "guard", "nastarum", "rupert", "alhana", "annax",
                "ilian", "citizen", "tazza", "eustice", "manar",
                "damon", "yrslim", "brook", "naythen", "fidget", 
                "astara", "catharis", "dalahalus", "quelthon",
                "taylor", "student", "evoker", "necromancer",
                "diviner", "enchanter", "templar", "child" 
                 }) );
  SetShort("a member of the Haven Town Guard");
  SetRace("elf");
  SetTown("Haven");
  SetClass("cavalier");
  SetLevel(50);
  SetCurrency("imperials",random(100)+1);
  SetGender("male");
  SetMorality(500);
  SetLong("This fellow is a burly elven warrior charged with \n"
          "keeping the peace in Haven Town.  He looks quite \n"
          "capable of doing his job.");
  SetInventory( ([
         H_OBJ + "guard_armour": "wear chainmail",
         H_OBJ + "rapier" : "wield first rapier",
                  ]) );
  SetId( ({ "guard", "haven_wander", "town guard" }) );
  SetAdjectives( ({ "haven", "town" }) );
  SetWander(5);
  SetAction(1, ({
    "!speak Glory to Haven Town, death to the heathen!",
    "!speak Our eyes are turned towards our light of the heavens!",
   }) );
  SetCombatAction(4, "!impale");
  SetLimit(6);
}

int CheckWanted() {
  if (this_player()->GetInvis()) return 0;
  if (member_array(this_player()->GetKeyName(), keys(Crimes)) != -1) {
    eventForce("follow " + this_player()->GetKeyName());
    eventForce("yell A criminal!  To me, to me!");
     SetAttack(this_player());
    return 1;
   }
  if(this_player()->GetProperty("invader")) {
     eventForce("yell Invaders!");
     SetAttack(this_player());
     return 1;
   }
  return 0;
 }



object *CheckFriends() {
	object *tmp = ({ });
	
  tmp = all_inventory(environment());
  tmp = filter(tmp, (: $1->GetTown() == "Haven" :) );
	return tmp;
}
