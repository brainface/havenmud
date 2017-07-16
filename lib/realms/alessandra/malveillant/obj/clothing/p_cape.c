/*  Portia   10-19-98
    A cape for the prince.
*/

#include <lib.h>
#include <damage_types.h>
#include <size.h>
#include <armour_class.h>
#include <vendor_types.h>
#include <armour_types.h>
inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("cape");
  SetShort("a princely cape");
  SetId( ({"cape"}) );
  SetAdjectives( ({"princely"}) );
  SetLong("This cape seems to belong to someone very special. It is adorned with many "
      "precious gems.");
  SetMass(80);
  SetMaterials( ({"textile"}) );
  SetWarmth(20);
  SetRepairSkills( ([
            "textile working" : 9,
            ]) );
  SetRepairDifficulty(100);
  SetValue(200);
  SetSize(SIZE_MEDIUM);
  SetArmourClass(ARMOUR_PLATE);
  SetDamagePoints(1000);
  SetVendorType(VT_CLOTHING);
  SetArmourType(A_CLOAK);
  }
