// Amelia
#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
#include <armour_types.h>
#include <armour_class.h>
#include <size.h>

inherit LIB_ARMOUR;

static void create() {
   ::create();
   SetKeyName("pants");
   SetShort("a pair of black leather pants");
   SetId( ({ "pants","pair" }) );
  SetMaterials( ({ "leather" }) );
   SetAdjectives( ({ "pair of","leather","black" }) );
   SetLong("The black leather pants are thick and clumsily crafted, "
           "with rough stitching creating an odd fit for the wearer.");
   SetVendorType(VT_ARMOUR);
   SetArmourType(A_PANTS);
   SetArmourClass(ARMOUR_LEATHER);
   SetMass(5);
   SetValue(75);
   SetDamagePoints(350);
   SetProperty("multiples",1);
   SetSize(SIZE_MEDIUM);
}
