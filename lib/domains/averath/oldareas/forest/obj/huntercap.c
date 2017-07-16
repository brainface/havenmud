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
   SetKeyName("cap");
   SetShort("a leather cap");
   SetId( ({ "cap" }) );
   SetAdjectives( ({ "brown","leather" }) );
   SetLong("Dusty brown in color and rough to touch, this leather cap has "
           "the ability to protect a head.");
   SetArmourType(A_HELMET);
  SetMaterials(({"leather"}));
   SetVendorType(VT_ARMOUR);
   SetArmourClass(ARMOUR_LEATHER);
   SetMass(1);
   SetValue(50);
   SetDamagePoints(450);
   SetSize(SIZE_MEDIUM);
}
