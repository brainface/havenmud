/*   Portia  10-14-98
   A dress for my female elves.
*/

#include <lib.h>
#include <vendor_types.h>
#include <size.h>
#include <armour_class.h>
#include <armour_types.h>
#include <damage_types.h>
inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("dress");
  SetShort("a fitted dress");
  SetId( ({"dress"}) );
  SetAdjectives( ({"fitted"}) );
  SetLong("This dress is very pretty and looks as though it was made specifically for the owner.");
  SetValue(30);
  SetMass(45);
  SetMaterials( ({"textile"}) );
  SetWarmth(20);
  SetDamagePoints(500);
  SetSize(SIZE_MEDIUM);
  SetArmourClass(ARMOUR_CLOTH);
  SetRepairSkills( ([
          "textile working" : 6,
             ]) );
  SetRepairDifficulty(30);
  SetVendorType(VT_CLOTHING);
  SetArmourType(A_BODY_ARMOUR);
  }


/* Approved by Duuktsaryth on Mon Nov 16 23:32:55 1998. */
