/*  Portia  10-26-98
   A generic woman for the town.
*/

#include <lib.h>
#include "../mal.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("woman");
  SetShort("a slender woman");
  SetId( ({"woman"}) );
  SetAdjectives( ({  "slender"}) );
  SetLong("With her long, straight, black hair flowing to the middle of "
          "her back this woman is very attractive. Her black eyes sparkle "
         "with a yearning for something and her hands are constantly playing "
         "with the medallion that hangs around her neck.");
  SetRace("dark-elf"); 
  SetMorality(-1000);
  SetGender("female");
  SetClass("priest");
  SetReligion("Soirin", "Soirin");
  SetLevel(20);
  SetInventory( ([
      MAL_OBJ + "/clothing/elf_dress" : "wear dress",
      MAL_OBJ + "/clothing/elf_medallion" : "wear medallion",
      ]) );
  SetAction(6,
     "!emote looks down at you with disdain.");
  SetSpellBook( ([
     "poison arrow"      : 100,
     "cloak of darkness" : 100,
     "asphyxiation"			 : 100,
     "shockwave"         : 100,
     ]) );
  SetCombatAction(80, ({
      "!cast poison arrow",
      "!cast cloak of darkness",
      "!cast shockwave",
      "!cast asphyxiation",
      }) );
  }
