#include <lib.h>
#include <std.h>
#include "../durgoroth.h"

inherit LIB_BARKEEP;

static void create() {
  barkeep::create();
  SetKeyName("Xructl");
  SetShort("Xructl the Carrion Peddler");
  SetId( ({ "xructl", "durg_nocombat" }) );
  SetTown("Durgoroth");
  SetAdjectives( ({ }) );
  SetLong("Xructl is an enterprising daemon who has"
          " found a niche at the Killing Pit selling"
          " the remains of other daemons for food."
          " Her ability to survive in the pit without"
          " becoming a victim erself is proof"
          " of her strength and prowess as a warrior.");
  SetGender("female");
  SetRace("daemon");
  SetClass("merchant");
  SetSkill("melee combat",1,1);
  SetSkill("disarm",1,1);
  SetLevel(190);
  SetLocalCurrency("crystals");
  SetMenuItems( ([
    "daemon arms"    : DURG_FOOD "arm",
    "daemon legs"    : DURG_FOOD "leg",
    "daemon heads"   : DURG_FOOD "head",
    "daemon torsos"  : DURG_FOOD "torso",
    "daemon claws"   : DURG_FOOD "claws",
    "daemon hooves"  : DURG_FOOD "hooves",
     ]) );
  SetMorality(-1250);
  SetInventory( ([
     STD_ARMOUR "cloak/cape_randomcolor_large" : "wear cape",
     STD_ARMOUR "shirt/vest_leather_large"     : "wear vest",
     ]) );
  SetAction(15, ({ 
    "!speak Come get your fresh limbs!",
    "!speak I've got limbs here! New Kills! Good deals!",
    "!speak Recently departed daemon bodies for sale!",
     }) );
  SetCombatAction(10, ({ 
    "!speak You fool! Now you shall be sold as scraps!",
    "!disarm",
    }) );
}
