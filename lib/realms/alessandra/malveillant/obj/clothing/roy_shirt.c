/*  Portia  10-19-98
    A shirt for royalty.
*/

#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <size.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("shirt");
  SetShort("a finely made shirt");
  SetId( ({"shirt"}) );
  SetAdjectives( ({"finely made", "finely", "made"}) );
  SetLong("This shirt is definetly worth quite a bit, and was obviously made for someone "
        "of great importance.");
  SetMass(25);
  SetValue(60);
  SetSize(SIZE_MEDIUM);
  SetArmourClass(ARMOUR_CLOTH);
  SetMaterials( ({"textile"}) );
  SetWarmth(15);
  SetArmourType(A_SHIRT);
  SetVendorType(VT_CLOTHING);
  SetDamagePoints(400);
  SetRepairSkills( ([
          "textile working" : 5,
             ]) );
  SetRepairDifficulty(20);
  }
