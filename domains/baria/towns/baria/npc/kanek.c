/*
// Summary: a sub-class leader to hold half of Creb's spells
// Created by: Rhakz@Haven - Angel Cazares
// For: Baria
// Date: 12/07/98
// 
   Modified by Zalbar 11/24/07
   made to newbie helper

*/
#include <lib.h>
#include <std.h>
#include "../jungle.h"
inherit LIB_EQUIPPER;

static void create() {
  ::create();
  SetKeyName("Kanek");
  SetShort("Kanek the Adept Shaman");
  SetId( ({"kanek","kanek the adept shaman","shaman","adept shaman",
           "adept"}) );
  SetLong("Kanek is a young shaman who helps young villagers become "
          "prepared to go outside of Barian village.  Since Creb appointed "
          "Kanek to this helpful position, Kanek has proven himself dutiful.  "
          "He looks strong and knowledgeable in his faith and magic to be "
          "appointed to such a position."
         );
  SetAdjectives( ({"young","strong","powerful"}) );

  SetRace("human");
  SetGender("male");
  SetClass("shaman");
  SetSkill("fire magic",1,2);
  SetLevel(30);
  SetReligion("Kuthar", "Kuthar");
  SetTown("Baria");
  SetMorality(-250);
  RemoveLanguage("Enlan");
  SetLanguage("Barian", 100 , 1);
  SetFriends( ({"barian kid","native"}) );
  SetCombatAction (75, ({
     "!cast fireball",
     "!cast ancestral protection",
     "!cast sphere",
     }) );
  SetSpellBook( ([
     "fireball"              : 100,
     "ancestral protection"  : 100,
     "sphere"                : 100,
     ]) );
   SetFirstCommands( ({
   	 "cast ancestral protection",
   	 "cast sphere",
   	 "cast sphere",
   	 }) );
   SetLevelLimit(10);
   SetFreeEquipment( ([
    "shirt"  : STD_CLOTHING "shirt",
    "shoes"  : STD_CLOTHING "shoes",
    "pants"  : STD_CLOTHING "pants",
    "coat"   : STD_CLOTHING "coat",
    "vest"   : BARIA_OBJ "vest",
    "leather pants" : STD_ARMOUR "/free_armour/medium/oldpants",
    "leather boots" : STD_ARMOUR "/free_armour/medium/oldboots",
    "glove"  : STD_ARMOUR "/free_armour/medium/oldglove",
    "helmet" : STD_ARMOUR "/free_armour/medium/oldhelmet",
    "fishing pole" : STD_OBJ "fishing/pole",
    "shovel" : STD_OBJ "digging/shovel",
    "sword"  : STD_WEAPON "slash/shortsword",
    "axe"    : STD_WEAPON "hack/stone_axe",
    "club"   : BARIA_OBJ "club",
    "spear"  : BARIA_OBJ "spear",
    "knife"  : STD_WEAPON "small_knife",
    "staff"  : BARIA_OBJ "staff",
    "bola"   : STD_WEAPON "projectile/bola", 
    ]) );
  
}
