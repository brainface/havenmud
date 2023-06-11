// Small boots for the fisherbear
// Copypasta from Leatherstore but damage points 300 not 800
// Mass 65 not 80
// Urien@Haven 11JUN2023

#include <lib.h>
#include <damage_types.h>
#include <armour_class.h>
#include <armour_types.h>
#include <vendor_types.h>
#include <size.h>

inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("leather boots");
  SetId( ({ "boots" }) );
  SetAdjectives( ({ "rugged", "leather" }) );
  SetShort("a pair of rugged boots");
  SetLong(
    "This rugged boot has seen much use over time illustrated "
    "by its current stature. The outside shell of the leather "
    "boots has various scuff marks and abrasions. A single string "
    "of leather has been weaved throughout the insides to allow "
    "adjustments to a small creatures paw or feet. It is "
    "modified and latched along the outside rings where the "
    "outer ankles of the wearer, exposing natural skin only "
    "slightly. "       
  );
  SetMass(65);
  SetMaterial( ({ "leather" }) );
  SetValue(1);
  SetProperty("multiples", 1);
  SetArmourClass(ARMOUR_LEATHER);
  SetVendorType(VT_ARMOUR);
  SetProtectionBonus(PIERCE, 1);
  SetProtectionBonus(BLUNT, -1);  
  SetArmourType(A_BOOT);
  SetSize(SIZE_SMALL);
  SetDamagePoints(300);
}
