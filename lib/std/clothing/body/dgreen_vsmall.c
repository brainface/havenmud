/* ----------------------------------------------------------------------- */
// Area Title: standard clothing
// Filename: dgreen_robe.c
// Author: Derek Noble
// Angel: dylanthalus@haven
// Creation Date: December 17th, 1998
// Abstract: just a standard dark green robe of not too much extravagence.
// Revision History: 
/* ----------------------------------------------------------------------- */

#include <lib.h>
#include <damage_types.h>
#include <armour_types.h>
#include <armour_class.h>
#include <vendor_types.h>
#include <size.h>

inherit LIB_ARMOUR;

static void create() {
  armour::create(); SetArmourClass(ARMOUR_CLOTH); SetMaterials( ({ "textile" }) ); 
  SetVendorType(VT_ARMOUR);
  SetArmourType(A_BODY_ARMOUR);
  SetKeyName("dark green robe");
  SetId( ({ "robe" }) );
  SetShort("a dark green robe");
  SetAdjectives( ({ "green","dark" }) );
  SetLong("The dark green robe is nothing out of the ordinary, but it is "
          "a fairly well made article of clothing.  The robe is rather "
          "bulky and heavy as well. A small amount of embroidery is "
          "visible around the trim of the collar, the cuffs and the "
          "brocade. It is a long flowing garment and would likely offer a "
          "slight amount of protection against the cold.");
  SetRepairSkills( ([ "textile working" : 8,]) );
  SetMaterial( ({ "textile" }) );
  SetWarmth(25);
  SetRepairDifficulty(10);
  SetMass(80);
  SetSize(SIZE_VERY_SMALL);
  SetValue(75);
  SetDamagePoints(400);
  //COLD, 2);
  }
