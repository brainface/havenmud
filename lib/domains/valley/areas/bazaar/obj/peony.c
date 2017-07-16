//
// a pink peony
// Created by Athalie
//
#include <lib.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
   SetKeyName("bouquet of peonies");
   SetId ( ({ "peonies", "bouquet", "bouquet of peonies" }) );
   SetShort("a bouquet of peonies");
   SetLong("The bouquet is made up of several white, pink, and red peonies. "
     "They are held together by a pretty little white ribbon."),
   SetMass(2);
   SetValue(9);
   SetVendorType(VT_PLANT);
}
