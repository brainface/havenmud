#include <lib.h>
#include <armour_class.h>
#include <armour_types.h>
#include <damage_types.h>
#include <vendor_types.h>
#include <size.h>
#include "../camp.h"
inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("dress");
  SetShort("a yellow dress");
  SetId( ({"dress"}) );
  SetAdjectives( ({"yellow","simple","cotton"}) );
  SetLong("This yellow cotton dress is of a simple, "
        "form-fitting cut and is ballerina length.  "
        "It has a scoop neck and short sleeves. ");
  SetVendorType(VT_ARMOUR);
  SetArmourType(A_BODY_ARMOUR);
  SetArmourClass(ARMOUR_CLOTH);
  SetMass(30);
  SetValue(40);
  SetDamagePoints(30);
  SetSize(SIZE_MEDIUM);
  SetMaterial("textile");
  SetWarmth(20);
  SetRepairDifficulty(5);  
  SetRepairSkills( ([
       "textile working" : 1,
  ]) );
}
