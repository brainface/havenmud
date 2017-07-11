/*  Town Guard v 2.0 for the Zealot Patrol */
#include <lib.h>
#include "../haven.h"
inherit LIB_SENTIENT;
void ChatRes();
int CheckWanted();
#include "../wanted.h"

static void create() {
  sentient::create();
  SetKeyName("kylin templar");
  SetReligion("Kylin");
  SetShort("a Templar of Kylin");
  SetRace("elf");
  SetFriends( ({ "kylin templar", "kylin inquisitor" }) );
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
  SetCurrency("imperials",random(1000));
  SetId( ({ "templar", "kylin templar", "haven_wander" }) );
  AddTalkResponse("to me", (: eventForce, "go out" :) );
  SetEncounter( (: CheckWanted :) );
  SetCombatAction(4, ({
       "!cast wall of force",
       "!cast smite",
       "!cast wrath",
       }) );
  SetSpellBook( ([
     "smite" : 100,
     "wrath" : 100,
     "wall of force" : 100,
     ]) );
 }

int CheckWanted() {
  if (this_player()->GetInvis()) return 0;
  if (member_array(this_player()->GetKeyName(), keys(Crimes)) != -1) {
    eventForce("follow " + this_player()->GetKeyName());
    eventForce("yell You'll die now criminal!");
     SetAttack(this_player());
    return 1;
   }
  if(this_player()->GetProperty("invader")) {
     SetAttack(this_player());
     return 1;
   }
  return 0;
 }
