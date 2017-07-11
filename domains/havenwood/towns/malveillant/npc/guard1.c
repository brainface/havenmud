#include <lib.h>
#include "../mal.h"
inherit LIB_TOWNGUARD;

static void create() {
  ::create();
  SetShort("a tough-looking guard");
  SetKeyName("guard");
  SetId( ({"guard"}) );
  SetAdjectives( ({"tough", "tough-looking"}) );
  SetLong("This tough guard looks very menacing. His demeanor "
          "suggests he takes his job very seriously and will not "
          "let anyone get away with breaking the laws of Malveillant.");
  SetRace("dark-elf"); 
  SetTown("Malveillant");
  SetReligion("Soirin");
  SetMorality(-200);
  SetGender("male");
  SetClass("fighter");
  SetLevel(65 + random(15));
  SetCurrency("roni",random(10) + 20);
  SetFriends("prince marikian");
  SetFriends("guard");
  SetSkill("disarm", 200, 1);
  SetInventory( ([
      MAL_OBJ + "/clothing/g_breastplate" : "wear plate",
      MAL_OBJ + "/clothing/g_boots"       : "wear boots",
     MAL_OBJ + "/clothing/fight_medallion" : "wear medallion",
      MAL_OBJ + "/clothing/g_pants"       : "wear pants",
      MAL_OBJ + "/weapons/g_sword"        : "wield sword",
     ]) );
  SetAction(7, ({
      "!emote glances at you suspiciously.",
      "!say Move along, citizen.",
      "!emote hefts his sword.",
    }) );
  SetCombatAction(10, ({
  	  "!disarm",
  	  "!disorient",
  	}) );
  }
