#include <lib.h>
#include <std.h>
#include "../keryth.h"

inherit LIB_EQUIPPER;

static void create() {
  ::create();
  SetKeyName("ansgar"); 
  SetShort("Ansgar the Impoverished Merchant");
  SetId( ({ "ansgar", "merchant", "equipper" }) );
  SetAdjectives( ({"impoverished"}) );
  SetLong("Ansgar the Impoverished Merchant is a tall dark furred "
          "Goden.  He is well dressed for one who is not good at "
          "his trade.  He is having a hard time selling his leather "
          "goods to Huram.  He may give them away if you ask him.");
  SetRace("goden");
  SetClass("merchant");
  SetTown("Keryth");
  SetGender("male");
  SetLevel(10);
  SetCurrency("senones", 1);
  SetLevelLimit(10);
  SetFreeEquipment( ([
    "pants" : STD_ARMOUR "free_armour/medium/oldpants",
    "helmet" : STD_ARMOUR "free_armour/medium/oldhelmet",
    "boots" : STD_ARMOUR "free_armour/medium/oldboots",
    "glove" : STD_ARMOUR "free_armour/medium/oldglove",
    "vest" : STD_ARMOUR "free_armour/medium/oldvest",
    ]) );
  SetAction(5, ({
  	"!say Please Huram buy my goods!",
  	"!say I should just give them away!",
    }) );
  SetInventory( ([
    STD_ARMOUR "pants/leggings" : "wear leggings",
    STD_CLOTHING "shirt/warrior_shirt" : "wear shirt",
    STD_CLOTHING "cloak/velvet_cape" : "wear cape on torso and head",
    ]) );
  SetMorality(-250);

}
