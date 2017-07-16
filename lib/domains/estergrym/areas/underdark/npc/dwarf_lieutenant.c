#include <lib.h>
#include "../underdark.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("lieutenant");
  SetId( ({ "lieutenant", "dwarf", "dwarven lieutenant" }) );
  SetShort("a Dwarven Lieutenant");
  SetLong(
    "A Dwarven Lieutenant. He is a battle hardened vetran. "
    "And looks to have every intention of living to enjoy his "
    "pension."
  );
  SetRace("dwarf"); 
  SetClass("fighter");
  SetLevel(25);
  SetGender("male");
   
  SetCurrency("imperials", 85);
  SetMorality(250);
  SetAction(3, ({ 
    "!speak Have no doubt, we will drive those foul things back into the "
    "depths from whence they came.",
    "!speak If you go any deeper you will be beset by the foul things "
    "in the depths." 
  }) );
  SetCombatAction(10, ({
  	"!speak Attack men! Kill the intruder!",
    "The dwarf blocks and parries your every attack."
  }) );
  SetInventory( ([ 
    U_OBJ + "1h_axe" : "wield axe in right hand",
    U_OBJ + "scale_mail" : "wear armour" 
  ]) );
  }
