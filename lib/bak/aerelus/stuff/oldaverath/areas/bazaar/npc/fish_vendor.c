/* Fish vendor for Bazaar
   coded by Kilik */
#include <lib.h>
#include <vendor_types.h>
#include "../bazaar.h"
#include "../bazaar.h"

inherit LIB_VENDOR;
static void create() {
  vendor::create();
  SetKeyName("kelna");
  SetId( ({ "kelna", "provisioner" }) );
  SetAdjectives( ({ }) );
  SetShort("Kelna the Provisioner of the Bazaar");
   SetLong("Kelna is tall with a lean build. Her hair is long "
           "and black, and her eyes are blue and dreamy. She "
           "has rather dirty hands that are covered in fish entrails.");
   SetLevel(8);
   SetRace("human");
   SetClass("merchant");
   SetGender("female");
   SetAction(1, ({ "!emote sighs heavily.", 
                   "!say if only I could leave.",
                   "!emote searches the horizon.", }) );
   SetLocalCurrency("ducats");
   SetCurrency("ducats",random(50));
   SetStorageRoom(BAZAAR_ROOM + "fish_store");
   SetMaxItems(40);
   SetMaxSingleItem(10);
   SetVendorType(VT_FOOD);
}
