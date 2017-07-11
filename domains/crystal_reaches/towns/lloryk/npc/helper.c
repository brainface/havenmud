#include <lib.h>
#include <std.h>
#include "../path.h"
inherit LIB_EQUIPPER;

static void create() {
  ::create();
  SetKeyName("merri");
  SetShort("Merri the Giver");
  SetRace("halfling");
  SetGender("female");
  SetId( ({ "merry", "giver" }) );
  SetAdjectives( ({ }) );
  SetLong("Merri the Giver is the most generous of halflings, "
          "even in a race known for being open and helpful to "
          "each other. Simply asking her for many goods usually "
          "results in her giving them out without any qualms.");
  
  SetMorality(1000);
  SetSkill("knife combat", 1, 1);
  SetLevel(15);
  SetCurrency("rounds", 75);
  SetInventory( ([
    STD_WEAPON "knife/hunting_knife" : "wield knife",
    ]) );
  SetFreeEquipment( ([
    "shoes" : STD_CLOTHING "small_shoes",
    "pants" : STD_CLOTHING "small_pants",
    "shirt" : STD_CLOTHING "small_shirt",
    "hoe"   : LLORYK "obj/hoe",
    "bread" : STD_MEAL "food/bread",
    "knife" : STD_WEAPON "knife/freeknife",
    ]) );
}
  
