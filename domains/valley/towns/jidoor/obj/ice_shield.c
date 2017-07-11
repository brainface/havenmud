/* ----------------------------------------------------------------------- */
// Area Title: City of Jidoor
// Filename: ice_shield.c
// Author: Matt Moran
// Immortal: Aagar@Haven
// Creation Date: Unknown
// Abstract: The ice shield of Aagron
/* ----------------------------------------------------------------------- */

#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include <vendor_types.h>
#include <armour_class.h>

inherit LIB_ARMOUR;

static void create() {
    armour::create();

  SetKeyName("ice shield");
  SetId( ({ "shield" }) );
  SetAdjectives( ({ "ice" }) );
  SetShort("an ice shield");
  SetLong(
    "The power of the Lord of Elemental Energies "
      "has formed a shield by freezing elemental "
    "water.  It's face is smooth and is marked with the symbol of "
    "water.  The cold that radiates from the shield chills to the "
    "bone.");

  SetDamagePoints(10000);
  SetVendorType(VT_ARMOUR);
  SetArmourClass(ARMOUR_PLATE);
  SetMass(2000);
  SetProperty("laoise flag", 1);
  SetValue(2000);
  SetArmourType(A_SHIELD);
  SetProtectionBonus(COLD|WATER,5);

  SetMaterial( ({ "natural" }) );

  SetProperty("history","The shield provides "
    "divine protection by the power of the Lord of Elemental "
    "Energies.");
  SetProperty("magic","It seems to resist cold and water.");

}

