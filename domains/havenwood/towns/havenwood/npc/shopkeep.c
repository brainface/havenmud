#include <lib.h>
#include <vendor_types.h>
#include "../wood.h"
inherit LIB_VENDOR;

static void create() {
  vendor::create();
  SetKeyName("fizzilgig");
  SetVendorType(VT_ALL);
  SetShort("Fizzilgig Festelbaum the Shopkeep");
  SetId( ({ "vendor", "shopkeep", "fizzilgig", "festelbaum" }) );
  SetAdjectives( ({ "fizzilgig" }) );
  SetStorageRoom(HWD_ROOM + "/gen_stor");
  SetRace("wild-elf");
  SetGender("male");
  SetClass("rogue");
  SetSkill("bargaining", 1, 2);
  SetLevel(25);
  SetCurrency("imperials", random(50) + 1);
  SetLong(
    "Fizzilgig Festelbaum is the shopkeep here in the Havenwood. He sells items "
    "that have come into his possession from all over the world of Kailie. While "
    "he may not give the best prices, he does offer the advantage of being settled "
    "close to home."
    );
  SetLocalCurrency("imperials");
  SetLimit(1);
  SetProperty("no bump", 1);
}
