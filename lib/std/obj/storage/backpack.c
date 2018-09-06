// Mahkefel@haven
// quick smallish backpack for noobs
#include <lib.h>
#include <size.h>
#include <armour_class.h>
#include <armour_types.h>
#include <vendor_types.h>

inherit LIB_WORN_STORAGE;

static void create()
{
  ::create();
  SetKeyName("backpack");
  SetId( ({ "backpack" }) );
  SetAdjectives( ({ "cheap","canvas"}) );
  SetShort("a cheap canvas backpack");
  SetLong("Little more than a canvas bag stretched across "
    "a light wooden frame, this inexpensive backpack could "
    "be of great use to a young traveller.");
  SetMass(1);
  SetMaterials( ({ "textile" }) );
  SetValue(100);
  SetMaxCarry(500);
  SetVendorType(VT_CLOTHING);
  SetArmourType(A_VEST);
  SetArmourClass(ARMOUR_CLOTH);
  SetDamagePoints(700);
}

