/*  Town Guard v 2.0 for the Zealot Patrol */
#include <lib.h>
#include "../haven.h"
inherit LIB_SENTIENT;
void ChatRes();
int CheckWanted();
#include "../wanted.h"

static void create() {
  ::create();
  SetKeyName("kylin templar");
  SetReligion("Kylin");
  SetFriends( ({ "kylin templar", "kylin inquisitor" }) );
  SetShort("a Templar of Kylin");
  SetRace("elf");
  SetTown("Haven");
  SetClass("cavalier");
  SetClass("priest");
  SetLevel(65);
  SetMorality(1000);
  SetSkill("enchantment", GetLevel()*3, 1);
  //SetSkill("enchantment", 1, 1);
  //SetSkill("blunt combat", 1, 1);
  //SetSkill("blunt combat", 1, 1);
  SetGender("male");
  SetLong("This is a templar of Kylin. His large frame appears charged "
          "with the ability to do his job keenly. An aura of faith surrounds "
          "him as he goes about his duties.");
  SetInventory( ([
         H_OBJ + "guard_armour": "wear chainmail",
         H_OBJ + "mace" : "wield mace",
         ]) );
  SetCurrency("imperials",random(1000)+1);
  SetId( ({ "templar", "kylin templar", "haven_wander" }) );
  SetWander(0);
  
  SetCombatAction(4, ({
       "!cast wall of force",
       "!cast smite",
       "!cast wrath",
       }) );
  SetAction(4, ({
      "!speak Glory be to Duuk on high!",
      "!cast wall of force",
      "!speak Power to the Church in all its glory!",
    }) );
  SetSpellBook( ([
     "smite" : 100,
     "wrath" : 100,
     "wall of force" : 100,
    ]) );
/*
  call_out((: eventForce, "cast wall of force" :), 5 );
*/
 }

int CheckWanted() {
  if (this_player()->GetInvis()) return 0;
  if (member_array(this_player()->GetKeyName(), keys(Crimes)) != -1) {
    eventForce("follow " + this_player()->GetKeyName());
     SetAttack(this_player());
    return 1;
   }
  if(this_player()->GetProperty("invader")) {
     load_object(H_ROOM + "misc_buildings/guardhouse");
     eventForce("yell Invaders!  To me, to me!");
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
