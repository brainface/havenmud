// Written by Vanyel
#include <lib.h>
#include "ice.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("ice mage");
  SetShort("an ice mage");
  SetLong("His cold gaze calmly assessing the strength of his "
    "prospective opponents, this mage "
    "is extremely pale, with a slight blueish tint.  Although he looks "
    "young, with his magic, he could be any age.");
  SetId( ({ "mage", "magician" }) );
  SetAdjectives( ({ "ice" }) );
  SetRace("human");
  SetClass("enchanter");
  SetSkill("ice magic", 1, 2);
  SetLevel(random(5)+20);
  SetEncounter(40);
  SetMorality(250);
  SetGender("male");
  SetSpellBook( ([
     "aura" : 100,
     "ice ball" : 100,
     ]) );
  SetInventory( ([
     ICE_OBJ + "/icerobes.c" : "wear ice robes",
     ICE_OBJ + "/icerod" : "wield rod",
     ]) );
  SetCurrency("imperials", random(100));
  SetCombatAction(85, ({
       "!cast ice ball",
       "!cast aura"
    }) );
//  SetWander(2);
}
