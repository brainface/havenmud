// Amelia
#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
#include <armour_types.h>
#include <armour_class.h>
#include <size.h>

inherit LIB_ARMOUR;
inherit LIB_SMELL;

static void create() {
   ::create();
   SetRadiantLight(3);
   SetKeyName("pendant");
   SetShort("a gleaming pendant");
   SetId( ({ "pendant" }) );
   SetAdjectives( ({ "gleaming" }) );
   SetLong("Hanging on a simple metal chain, the pendant glows "
           "forest green.  Its feminine shape wields a knife in "
           "one hand and holds a deciduous branch in the other.");
   SetArmourType(A_AMULET);
   SetVendorType(VT_ARMOUR|VT_TREASURE);
   SetArmourClass(ARMOUR_CHAIN);
   SetMass(0.25);
   SetValue(200);
   SetDamagePoints(150);
   SetSize(SIZE_MEDIUM);
   SetSmell("The odors of rot and decay permeate the object.");
}
