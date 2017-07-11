/* ----------------------------------------------------------------------- */
// Area Title: standard clothing
// Filename: sash.c
// Author: Derek Noble
// Angel: dylanthalus@haven
// Creation Date: December 17th, 1998
// Abstract: a standard sash for a robe
// Revision History: 
/* ----------------------------------------------------------------------- */

#include <lib.h>
#include <damage_types.h>
#include <armour_types.h>
#include <armour_class.h>
#include <vendor_types.h>

inherit LIB_ARMOUR;

static void create() {
  armour::create(); SetArmourClass(ARMOUR_CLOTH); SetMaterials( ({ "textile" }) ); 
  SetKeyName("sash");
  SetShort("a sash");
  SetId( ({ "sash" }) );
  SetLong("This is a nice piece of cloth that can be used as sash used to "
          "tied up one's robes.");
  SetMass(2);
  SetValue(10);
  SetWarmth(2);
  SetVendorType(VT_ARMOUR);
  SetArmourType(A_BELT);
  SetDamagePoints(50);
  SetRepairSkills( ([ "textile working" : 1,]) );
  SetMaterial( ({ "textile" }) );
  SetRepairDifficulty(10);
}
