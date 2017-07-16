/*  Portia  10-15-98
   A pair of royal leggings.
*/

#include <lib.h>
#include <damage_types.h>
#include <armour_class.h>
#include <size.h>
#include <armour_types.h>
#include <vendor_types.h>
inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("leggings");
 SetShort("a pair of fine leggings");
  SetId( ({"leggings"}) );
  SetAdjectives( ({"pair of", "pair" }) );
  SetLong("This pair of leggings looks rather expensive and definetly was not"
              "made for the"
         "commonperson.");
  SetMass(20);
  SetValue(60);
  SetSize(SIZE_MEDIUM);
  SetArmourClass(ARMOUR_CLOTH);
  SetMaterials( ({"textile"}) );
  SetWarmth(15);
  SetRepairSkills( ([
         "textile working" : 4,
              ]) );
  SetRepairDifficulty(15);
  SetArmourType(A_PANTS);
  SetVendorType(VT_CLOTHING);
  SetDamagePoints(500);
  }
