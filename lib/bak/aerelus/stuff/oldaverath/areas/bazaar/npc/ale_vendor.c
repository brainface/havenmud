/* Liquor vendor for Bazaar
   coded by Kilik */
#include <lib.h>
#include <vendor_types.h>
#include "../bazaar.h"
#include "../bazaar.h"

inherit LIB_VENDOR;
static void create() {
  vendor::create();
  SetKeyName("Mordaxt");
   SetId( ({ "mordaxt", "vendor", "mordaxt the ale vendor" }) );
   SetAdjectives( ({ "ale" }) );
   SetShort("Mordaxt the ale vendor");
   SetLong("Short and stocky, he stands at a solid meter high "
           "and weighs more than a full height "
           "man. He looks like he could easily rip any man in "
           "two. His hair is clean cut and black.");
   SetLevel(10);
   SetRace("human");
   SetClass("merchant");
   SetGender("male");
   SetAction(1, ({ "!say what would you like today?",   }) );
   SetLocalCurrency("ducats");
   SetCurrency("ducats",random(50));
   SetStorageRoom(BAZAAR_ROOM + "ale_store");
   SetMaxItems(40);
   SetMaxSingleItem(10);
   SetVendorType(VT_DRINK);
}
