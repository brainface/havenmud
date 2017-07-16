/* ----------------------------------------------------------------------- */
// Area Title: City of Jidoor
// Filename: air_helm.c
// Author: Matt Moran
// Immortal: Aagar@Haven
// Creation Date: Unknown
// Abstract: Helm for Aagron
/* ----------------------------------------------------------------------- */

#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <vendor_types.h>
#include <size.h>
#include <damage_types.h>
inherit LIB_ARMOUR;

static void create()    {
  ::create();
  SetKeyName ("air helm");
  SetId ( ({"helm"}) );
  SetAdjectives ( ({"air"}) );
  SetShort ("an air helm");
  SetLong (
    "This godly helm has been formed by the "
   "Lord of Elemental Energies from the ethereal mists. "
    "Marked with the symbol of air, it has no distict form, but rather "
    "shifts from form to form.  First it is open face, then full, then "
    "again a cap with dragon wing decorations."  );
  SetMass (1000);
  SetValue (4000);
  SetArmourClass(ARMOUR_PLATE);
  SetVendorType (VT_ARMOUR);
  SetDamagePoints (7500);
  SetProperty("laoise flag", 1);
  SetArmourType (A_HELMET);
  SetMaterial ( ({ "natural" }) );
  SetSize(SIZE_LARGE);

  SetProtectionBonus(SHOCK,5);
  SetProperty("history","The helm provides "
    "divine protection by the power of the Lord of Elemental "
    "Energies.");
  SetProperty("magic","It seems to resist lightning");
}


