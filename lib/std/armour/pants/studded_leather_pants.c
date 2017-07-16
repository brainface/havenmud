#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include <vendor_types.h>
#include <armour_class.h>
#include <size.h>

inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("studded leather pants");
  SetId( ({ "pants" }) );
  SetAdjectives( ({ "studded", "leather", "pair of" }) );
  SetMaterials( ({ "leather" }) );
  SetRepairDifficulty(10);
  
  SetShort("a pair of studded leather pants");
  SetLong("Pieces of iron reinforce the hardened leather in these "
          "pants.");
  SetVendorType(VT_ARMOUR);
  SetArmourClass(ARMOUR_REINFORCED);
  SetSize(SIZE_MEDIUM);
  SetMass(70);
  SetWarmth(20);
  SetValue(150);
  SetDamagePoints(250);
  SetArmourType(A_PANTS);
  }
