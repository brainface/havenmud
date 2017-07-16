#include <lib.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
   item::create();
   SetKeyName("black feather");
   SetShort("a black feather");
   SetId( ({ "feather" }) );
   SetAdjectives( ({ "black" }) );
   SetLong("The feather is pure black. The edges are very worn "
           "and tattered.");
   SetMass(1);
   SetValue(10);
   SetVendorType(VT_TREASURE);
   SetDamagePoints(5);
   SetMaterial( ({ "natural" }) );
}
