//
// Kelsey the accessories vendor
// Created by Athalie
//

#include <lib.h>
#include "../bazaar.h"
#include <vendor_types.h>
inherit LIB_VENDOR;

static void create() {
  vendor::create();
   SetKeyName("kelsey");
   SetId( ({ "kelsey", "vendor", "kelsey the accessories vendor" }) );
   SetShort("Kelsey the accessories vendor");
   SetLong("Kelsey deals in the wares of accessories. He will buy some "
     "clothing articles, too, but his best items for sale are his beautiful "
     "specialties. He is a thin little man, with his hair pulled back into "
     "a tight ponytail and wide grey eyes.");
   SetRace("gelfling");
   SetClass("merchant");
   SetLevel(13);
   
   SetGender("male");
   SetAction(2, ({
     "!speak You won't find goods like these anywhere else in Kailie.",
     "!emote eyes you over carefully.",
   }) );
   SetLocalCurrency("rupies");
   SetStorageRoom(BAZAAR_ROOM + "accstore");
   SetMaxItems(50);
   SetMaxSingleItem(5);
   SetVendorType(VT_CLOTHING | VT_ARMOUR);
}

