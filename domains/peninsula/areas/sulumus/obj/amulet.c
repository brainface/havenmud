// Proximo@Via Imperialis
// 06/02/2003

#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <vendor_types.h>
#include <damage_types.h>
#include <size.h>

inherit LIB_ARMOUR;

static void create() {
  ::create();
  SetKeyName("amulet");
  SetId( ({ "amulet" }) );
  SetAdjectives( ({ "fancy","looking","silver" }) );
  SetShort("a fancy-looking silver amulet");
  SetLong(
     "This amulet looks to have been made from a finely polished silver, "
     "giving it an expensive and fancy look. The amulet is in the shape of "
     "a teardrop, with a strange symbol engraved upon it. "
  	 );
  SetVendorType(VT_TREASURE);
  SetMass(30);
  SetValue(160);
  SetArmourClass(ARMOUR_CHAIN);
  SetMaterial( ({ "metal" }) );
  SetDamagePoints(1000);
  SetArmourType(A_AMULET);
  // SetProtection(SHOCK, 2);
}
