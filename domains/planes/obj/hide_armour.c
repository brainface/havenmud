
#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <vendor_types.h>
#include <damage_types.h>
#include <size.h>

inherit LIB_ARMOUR;

static void create() {
  ::create();
  SetKeyName("charred hide armour");
  SetId( ({ "armour" }) );
  SetAdjectives( ({ "charred", "hide" }) );
  SetShort("a charred hide armour");
  SetLong(
    "This armour is crafted from the cured hide of some "
    "squamous beast. Thick pieces of hide sewn together with "
    "coarse thread cover the torso and arms. A multitude of char "
    "marks and scratches covering the armour attest to its "
    "durabilty."
  );
  SetArmourClass(ARMOUR_LEATHER);
  SetArmourType(A_BODY_ARMOUR);
  SetDamagePoints(2800);
  SetMass(200);
  SetMaterial( ({ "leather" }) );
  SetSize(SIZE_LARGE);
  SetValue(400);
  SetVendorType(VT_ARMOUR);
  SetWarmth(5);
}

