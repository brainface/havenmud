
#include <lib.h>
#include <std.h>
#include "../durgoroth.h"
inherit LIB_BARKEEP;

static void create() {
  barkeep::create();
  SetKeyName("Chilotl");
  SetShort("Chilotl the Hollow Inn's barkeep");
  SetId( ({ "chilotl", "durg_nocombat" }) );
  SetTown("Durgoroth");
  SetAdjectives( ({ }) );
  SetLong("Chilotl has taken refuge in the Hollow"
          " Inn as an entrepreneur. She found her"
          " niche in the collection and sale of"
          " various blood types. As far as daemon's"
          " go, she is quite small, but has taken"
          " measures to ensure her safety within"
          " the inn.");
  SetGender("female");
  SetRace("daemon");
  SetClass("merchant");
  SetSkill("melee combat",1,1);
  SetSkill("disarm",1,1);
  SetLevel(190);
  SetLocalCurrency("crystals");
  SetMenuItems( ([
    "sprite blood"  : DURG_FOOD "sprite_blood",
    "dwarven blood" : DURG_FOOD "dwarven_blood",
    "goden blood"   : DURG_FOOD "goden_blood",
     ]) );
  SetMorality(-1250);
  SetInventory( ([
     STD_ARMOUR "cloak/cape_randomcolor_large" : "wear cape",
     STD_ARMOUR "shirt/vest_leather_large"     : "wear vest",
     ]) );
  SetAction(15, ({ 
    "!speak Thirsty? I've got just what you need!",
    "!speak Three types to choose from, pick your poison!",
    "!emote ruffles her wings slightly.",
     }) );
  SetCombatAction(10, ({ 
    "!disarm",
    }) );
}
