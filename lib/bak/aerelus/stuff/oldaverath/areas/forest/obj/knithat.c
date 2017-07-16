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
   SetKeyName("hat");
   SetShort("a thick black hat");
   SetId( ({ "hat" }) );
   SetAdjectives( ({ "thick","black" }) );
   SetLong("A dark fuzz forms an aura around the outside of the "
           "hat, knit using thick black yarn.");
   SetVendorType(VT_ARMOUR);
   SetArmourType(A_HELMET);
   SetArmourClass(ARMOUR_CLOTH);
   SetMass(1);
   SetValue(15);
   SetDamagePoints(220);
   SetSize(SIZE_MEDIUM);
}
