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
   SetShort("a royal blue sock");
   SetId( ({ "sock" }) );
   SetAdjectives( ({ "royal","blue"}) );
   SetLong("Knit using thin, coarse yarn, the royal blue sock "
           "has a halo of fuzz around it.");
   SetVendorType(VT_ARMOUR);
   SetArmourType(A_SOCK);
  SetMaterial( ({ "textile" }) );
   SetArmourClass(ARMOUR_CLOTH);
   SetMass(1);
   SetValue(3);
   SetDamagePoints(175);
   SetSize(SIZE_MEDIUM);
}
