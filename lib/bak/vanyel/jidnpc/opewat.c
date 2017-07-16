//
// Opewat, the Storekeeper
// Created by Zaxan@Haven
//

#include <lib.h>
#include <vendor_types.h>
#include "../jidoor.h"

inherit LIB_VENDOR;

static void create() {
   vendor::create();
   SetKeyName("opewat");
   SetId( ({ "opewat", "vendor", "storekeeper" }) );
   SetShort("Opewat the Storekeeper");
   SetLong("This large man sits behind the counter waiting for "
           "someone that may need him.");
   SetLevel(20);
   SetRace("sprite");
   SetMorality(25);
   SetClass("fighter");
   SetGender("male");
   SetAction(1, ({ 
      "!speak Are you going to buy something?",
   }) );
   SetLocalCurrency("rupies");
   SetStorageRoom(JID_ROOM "/misc_buildings/genstorage");
   SetMaxItems(50);
   SetMaxSingleItem(10);
   SetVendorType(VT_ALL);
}
