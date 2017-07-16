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
   SetKeyName("gloves");
   SetShort("a pair of leather gloves");
   SetId( ({ "gloves" }) );
   SetAdjectives( ({ "pair of","leather" }) );
   SetLong("Softened and wrinkled from age, the black leather gloves "
           "are thin to allow full dexterity during use.");
   SetVendorType(VT_ARMOUR);
   SetArmourType(A_GLOVE);
   SetArmourClass(ARMOUR_LEATHER);
   SetMass(1);
   SetValue(50);
   SetProperty("multiples",1);
   SetDamagePoints(300);
   SetSize(SIZE_MEDIUM);
}
