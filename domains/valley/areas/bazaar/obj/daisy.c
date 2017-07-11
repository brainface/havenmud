//
//
// a white daisy
// Created by Athalie
//
#include <lib.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
   SetKeyName("white daisy");
   SetId( ({ "daisy" }) );
   SetAdjectives( ({ "white" }) );
   SetShort("a white daisy");
   SetLong("This pretty white daisy has a round yellow center. It would "
     "be the perfect thing to give to a friend.");
   SetMass(1);
   SetValue(7);
   SetVendorType(VT_PLANT);
}
