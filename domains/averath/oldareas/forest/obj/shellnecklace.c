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
   SetKeyName("necklace");
   SetShort("a shell necklace");
   SetId( ({ "necklace" }) );
   SetAdjectives( ({ "shell" }) );
   SetLong("The shell necklace was formed using a piece of thick string and "
           "many tiny shells, mostly small conical shells like hermit crabs and "
           "snails occupy.");
   SetVendorType(VT_ARMOUR);
   SetArmourType(A_AMULET);
   SetArmourClass(ARMOUR_NATURAL);
   SetMass(1);
   SetValue(70);
   SetDamagePoints(50);
   SetSize(SIZE_MEDIUM);
}
