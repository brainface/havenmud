//Selket@Haven
//2006
#include <armour_class.h>
#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
#include <armour_types.h>
inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("amulet");
  SetShort("a scorpion amulet");
  SetId( ({"amulet"}) );
  SetAdjectives( ({"scorpion"}) );
  SetLong(
    "The amulet is fashioned of a semi-precious dark stone, and "
    "represents a scorpion, ready to strike. It is a symbol of "
    "Selket, the Giver of Breath, the Taker of Souls. ");
  SetMass(5);
  SetWarmth(0);
  SetArmourClass(ARMOUR_CLOTH);
  SetValue(400);
  SetDamagePoints(1000);
  SetVendorType(VT_CLOTHING);
  SetArmourType(A_AMULET);
  SetMaterials( ({"natural"}) );
}
