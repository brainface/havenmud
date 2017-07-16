#include <lib.h>
#include "../soleil.h"
inherit LIB_SENTIENT;
void ChatRes();
int CheckWanted();
#include "../wanted.h"

static void create() {
  sentient::create();
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
  SetLevel(random(20)+30);
  SetClass("cavalier");
  SetGender("male");
  SetLong("This fellow is a burly elven warrior charged with \n"
          "keeping the peace in Haven Town.  He looks quite \n"
          "capable of doing his job.");
  SetInventory( ([
         S_OBJ + "guard_armour": "wear chainmail",
         S_OBJ + "rapier" : "wield first rapier",
                  ]) );
  SetCurrency("imperials",random(100));
  SetId( ({ "guard", "haven_wander", "town guard" }) );
  SetAdjectives( ({ "haven", "town" }) );
  SetWander(5);
 SetEncounter( (: CheckWanted :) );
  SetAction(1, ({
    "!speak Glory to Haven Town, death to the heathen!",
    "!speak Our eyes are turned towards our light of the heavens!",
   }) );
  SetCombatAction(4, "!impale");
 }

int CheckWanted() {
  if (this_player()->GetInvis()) return 0;
  if (!userp(this_player())) return 0;
/*   if ( (this_player()->GetTown() != "Haven") &&
   (this_player()->GetReligion() != "Kylin") ) {
      eventForce("speak You are not welcome here!");
      eventForce("attack " + this_player()->GetKeyName());
      return 1;
      }  */
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
