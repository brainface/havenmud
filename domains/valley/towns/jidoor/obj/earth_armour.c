/* ----------------------------------------------------------------------- */
// Area Title: City of Jidoor
// Filename: earth_armour.c
// Author: Matt Moran
// Immortal: Aagar@Haven
// Creation Date: Unknown
// Abstract: Earth Armour for Aagron
/* ----------------------------------------------------------------------- */

#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <damage_types.h>
#include <size.h>
#include <vendor_types.h>

inherit LIB_ARMOUR;

static void create() {
    armour::create();

  SetKeyName("earthen armour");
  SetId ( ({ "armour" }) );
  SetAdjectives( ({ "earthen","suit","of","full","body" }) );
  SetShort ("an earthen suit of full body armour");
  SetLong (
    "This blessed armour has been moulded by "
    "the Lord of Elemental Energies from pure stone. "
    "It completely covers the body, encapsulating it solid rock. "
    "By the power of Aagar the stone is as flexible as its wearer, "
    "bending easily in any direction.  It's surface is smooth and marked "
    "with the symbol of earth.");
  SetVendorType(VT_ARMOUR);
  //SetProperty("multiples", 1);
  SetArmourType (A_BODY_ARMOUR);
  SetMass(5500);
  SetValue(4000);
  SetSize(SIZE_LARGE);
  SetArmourClass(ARMOUR_PLATE);
  SetProperty("laoise flag", 1);
  SetDamagePoints(20000);
  SetProtectionBonus(ALL_PHYSICAL,3);// really low matters for plate

  SetMaterial ( ({"natural"}) );
  SetProperty("history", "The armour provides "
    "divine protection by the power of the Lord of Elemental "
    "Energies.");
  SetProperty("magic","The armour is endowed with spells "
    "protecting it from most mundane forms of attack.");
}

