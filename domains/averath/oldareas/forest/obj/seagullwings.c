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
   SetKeyName("wings");
   SetShort("a set of seagull wings");
   SetId( ({ "wings","set" }) );
   SetAdjectives( ({ "set of","seagull" }) );
   SetLong("Plain white with tinges of a dull grey, the set of seagull wings could "
           "be fastened to one's back like a vest.");
   SetVendorType(VT_TREASURE);
   SetArmourType(A_VEST);
   SetArmourClass(ARMOUR_NATURAL);
   SetMass(1);
   SetValue(50);
   SetDamagePoints(100);
   SetProperty("multiples",1);
   SetSize(SIZE_VERY_SMALL);
}
