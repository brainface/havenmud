#include <lib.h>
#include <damage_types.h>
#include <armour_class.h>
#include <size.h>
#include <armour_types.h>
#include <vendor_types.h>

inherit LIB_ARMOUR;

static void create()
{
  armour::create();
  SetKeyName("pants");
  SetId(( { "leather pants","pair of pants","pair of leather pants"} ));
  SetShort("a pair of leather pants");
  SetLong("These leather pants look well worn.");
  SetMass(150);
  SetMaterial("leather");
  SetRepairDifficulty(10);
  SetWarmth(15);
  SetArmourClass(ARMOUR_LEATHER);
  SetSize(SIZE_MEDIUM);
  SetValue(150);
  SetDamagePoints(500);
  // SetProtection(SLASH,5);
  // SetProtection(PIERCE,5);
  // SetProtection(COLD,10);
  // SetProtection(HEAT,4);
  // SetProtection(ACID,7);
  SetArmourType(A_PANTS);
}

