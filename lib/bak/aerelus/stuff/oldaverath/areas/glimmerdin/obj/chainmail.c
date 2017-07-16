#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include <vendor_types.h>
#include <armour_class.h>
#include <size.h>

inherit LIB_ARMOUR;


static void create() {
    armour::create();
    SetKeyName("chainmail");
   SetId( ({ "chainmail" }) );
  SetAdjectives( ({ "dwarven", "sturdy", "suit of" }) );
    SetShort("a suit of sturdy dwarven chainmail");
    SetLong("This suit of dwarven chainmail is composed of a thick "
      "and extremely durable steel mesh.  It has tremendous resilience "
      "because it was forged by a great dwarven smith specifically "
      "for the dwarven body shape.");
    SetVendorType(VT_ARMOUR);
    SetArmourType(A_BODY_ARMOUR);
    SetArmourClass(ARMOUR_CHAIN);
    SetMass(650);
    SetValue(450);
    SetDamagePoints(1500);
    SetSize(SIZE_SMALL);
}

