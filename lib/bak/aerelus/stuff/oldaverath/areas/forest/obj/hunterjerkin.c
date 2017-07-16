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
   SetKeyName("jerkin");
   SetShort("a leather jerkin");
   SetId( ({ "jerkin" }) );
   SetAdjectives( ({ "brown","leather" }) );
   SetLong("This close-fitting, collarless jacket lacks sleeves, yet "
           "its tough leather would protect a torso from physical attacks.");
   SetArmourType(A_VEST);
   SetVendorType(VT_ARMOUR);
   SetArmourClass(ARMOUR_LEATHER);
   SetMass(4);
   SetValue(350);
   SetDamagePoints(450);
   SetSize(SIZE_MEDIUM);
}
