// amelia
#include <lib.h>
#include <damage_types.h>
#include <armour_types.h>
#include <vendor_types.h>
#include <armour_class.h>
#include <size.h>

inherit LIB_ARMOUR;

static void create() {
   ::create();
   SetKeyName("sock");
   SetShort("a forest green sock");
   SetId( ({ "sock" }) );
   SetAdjectives( ({ "forest","green"}) );
   SetLong("Knit using thick, coarse yarn, the forest green sock "
           "has a halo of fuzz around it.");
   SetVendorType(VT_ARMOUR);
   SetArmourType(A_SOCK);
   SetArmourClass(ARMOUR_CLOTH);
  SetMaterial( ({ "textile" }) );
   SetMass(1);
   SetValue(5);
   SetDamagePoints(200);
   SetSize(SIZE_MEDIUM);
}
