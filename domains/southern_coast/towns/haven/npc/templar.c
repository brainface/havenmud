/*  Town Guard v 2.0 for the Zealot Patrol */
#include <lib.h>
#include "../haven.h"
inherit LIB_TOWNGUARD;
void ChatRes();
int CheckWanted();
#include "../wanted.h"

static void create() {
  ::create();
  SetKeyName("kylin templar");
  SetReligion("Kylin");
  SetFriends( ({ "guard", "nastarum", "rupert", "alhana", "annax",
                "ilian", "citizen", "tazza", "eustice", "manar",
                "damon", "yrslim", "brook", "naythen", "fidget", 
                "astara", "catharis", "dalahalus", "quelthon",
                "kylin templar", "parsenon", "kylin inquisitor",
                   "taylor", "child" }) );
  SetShort("a Templar of Kylin");
  SetRace("elf");
  SetTown("Haven");
  SetClass("cavalier");
  SetClass("priest");
  SetSkill("enchantment", GetLevel()*3, 1);
  //SetSkill("enchantment", 1, 1);
  //SetSkill("blunt combat", 1, 1);
  //SetSkill("healing", 1, 1);
  SetLevel(65);
  SetMorality(1000);
  SetGender("male");
  SetLong("This is a templar of Kylin. His large frame appears charged "
         "with the ability to do his job keenly. An aura of faith surrounds "
         "him as he goes about his duties.");
  SetInventory( ([
         H_OBJ + "guard_armour": "wear chainmail",
         H_OBJ + "mace" : "wield mace",
                  ]) );
  SetCurrency("imperials",random(1000));
  SetId( ({ "templar", "kylin templar", "haven_wander" }) );
  SetWander(5);
  
  SetCombatAction(4, ({
      "!cast wall of force",
      "!cast smite",
      "!cast wrath",
      "!yell TO ME, To Me!, to me!",
      }) );
  SetSpellBook( ([
      "smite" : 100,
      "cure disease" : 100,
      "wrath" : 100,
      "protect" : 100,
      "wall of force" : 100,
      ]) );
  SetLimit(5);
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
  if ( (this_player()->GetRace() == "dark-elf") &&  (this_player()->GetReligion() != "Kylin") ) {
      eventForce("speak You are not welcome here, dark-elf!");
      eventForce("attack " + this_player()->GetKeyName());
      return 1;
      }  
return 0;
 }

void heart_beat() {
  ::heart_beat();
  if (present("germ", this_object())) {
  eventForce("cast cure disease");
  }
}


object *CheckFriends() {
	object *tmp = ({ });
	
  tmp = all_inventory(environment());
  tmp = filter(tmp, (: $1->GetTown() == "Haven" :) );
	return tmp;
}
