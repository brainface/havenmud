// Waterlily
// Davantalus 20040721

#include <lib.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
   SetKeyName("waterlily");
   SetId( ({ "blue waterlily" }) );
   SetAdjectives( ({ "light", "blue" }) );
   SetShort("a blue waterlily");
    SetLong(
      "The waterlily grows up from its root structure deep in the water, the blue petals "
      "and purple stamen have a gorgeous, sweet fragrance. Small drops of water bead "
      "on the surface of the leaves, repelled by their oily texture. The bloom "
      "is only slightly open right now because of the shade."
    );
   SetMass(1);
   SetValue(4);
   SetVendorType(VT_PLANT);
}
