#include <lib.h>
#include <armour_types.h>
#include <size.h>
#include <armour_class.h>
#include <damage_types.h>
#include <vendor_types.h>
#include <size.h>

inherit LIB_ARMOUR;

static void create() {
    armour::create();
    SetKeyName("studded leather pants");
    SetMaterial( ({ "leather" }) );
    SetRepairDifficulty(10);
    SetId( ({ "pants" }) );
    SetAdjectives( ({ "studded", "leather", "pair of" }) );
    SetShort("a pair of studded leather pants");
    SetLong(
      "Pieces of iron reinforce the hardened leather in these "
      "pants, which appear to be of a small size."
      );
    SetVendorType(VT_ARMOUR);
    SetArmourClass(ARMOUR_REINFORCED);
    SetSize(SIZE_SMALL);
    SetMass(70);
    SetWarmth(20);
    SetValue(150);
    SetDamagePoints(250);
    SetArmourType(A_PANTS);
  }
