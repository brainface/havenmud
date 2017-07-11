#include <lib.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
   item::create();
   SetKeyName("garnet cube");
   SetShort("a garnet cube");
   SetId( ({ "garnet cube","garnet","cube" }) );
   SetAdjectives( ({ "small" }) );
   SetLong("The small garnet is shaped as a cube, twinkling a deep "
           "red in the light.");
   SetMass(5);
   SetValue(77);
   SetVendorType(VT_GEM);
   SetMaterial( ({ "natural" }) );
   SetDamagePoints(89);
}