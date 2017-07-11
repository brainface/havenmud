//
// A small pony carved from wood
// Created by Athalie
//
#include <lib.h>
#include <vendor_types.h>
#include "../bazaar.h"
inherit LIB_ITEM;

static void create() {
  item::create();
   SetKeyName("figurine");
   SetId( ({ "figurine" }) );
   SetAdjectives( ({ "wooden", "pony" }) );
   SetShort("a wooden figurine");
   SetLong("This detailed wooden pony was hand carved and sanded. "
     "The little figurine is good for little else than collecting.");
   SetMass(50);
   SetValue(60);
   SetVendorType(VT_TREASURE);
}
