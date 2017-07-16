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
   SetKeyName("glove");
   SetShort("a black knit glove");
   SetId( ({ "glove" }) );
   SetAdjectives( ({ "black","knit" }) );
   SetLong("Surrounded by an aura of black fuzz, the gloves were lovingly "
           "knit using thick black yarn.");
   SetVendorType(VT_ARMOUR);
   SetArmourType(A_GLOVE);
   SetArmourClass(ARMOUR_CLOTH);
   SetMass(1);
   SetValue(10);
   SetDamagePoints(200);
   SetSize(SIZE_MEDIUM);
}
