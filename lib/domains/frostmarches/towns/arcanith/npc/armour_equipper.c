#include <lib.h>
#include <vendor_types.h>
#include <domains.h>
#include <std.h>
#include "../ruins.h"

inherit LIB_EQUIPPER;

static void create() {
  ::create();
  SetKeyName("karris");
  SetId( ({ "karris", "arcanith_wander", "scavenger" }) );
  SetAdjectives( ({"karris","the"}) );
  SetShort("Karris the Scavenger");
  SetLong(
    "Karris is a sad little skaven exiled from Malveillant. He "
    "spends his days gathering snake and spider skins and crafting "
    "them into pitiful armour which he gives away for free to anyone "
    "that doesn't scare him too badly."
  );

  SetRace("skaven");
  SetGender("male");
  SetBaseLanguage("Koblich");
  SetTown("Arcanith");
  SetMorality(-100);
  SetClass("rogue");
  SetLevel(15);
  AddCurrency("senones", random(100)+5);

  // from original file
  SetLimit(1);
  SetWander(20);
  SetGender("male");

  SetAction(10, ({
    "!say Don't hurt me!",
    "!say I made something!",
    "!emote skitters about.",
    "!emote squints at you nervously.",
    "!say Do you want a glove?",
  }) );

  SetLevelLimit(10);
  SetLimit(1);
  SetFreeEquipment( ([
     "vest"   : STD_ARMOUR + "free_armour/small/oldvest",
     "pants"  : STD_ARMOUR + "free_armour/small/oldpants",
     "boots"  : STD_ARMOUR + "free_armour/small/oldboots",
     "glove"  : STD_ARMOUR + "free_armour/small/oldglove",
     "helmet" : STD_ARMOUR + "free_armour/small/oldhelmet",
   ]) );

}

