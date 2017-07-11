//
// a pair of red tulips
// Created by Athalie
//
#include <lib.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
   SetKeyName("pair of tulips");
   SetId( ({ "tulips", "pair", "pair of tulips" }) );
   SetShort("a pair of tulips");
   SetLong("These two delicate red tulips are held together with a tasteful "
     "white ribbon."),
   SetMass(3);
   SetValue(8);
   SetVendorType(VT_PLANT);
}
