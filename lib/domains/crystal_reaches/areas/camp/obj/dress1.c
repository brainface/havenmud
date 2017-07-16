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
  SetShort("a red dress");
  SetId( ({"dress"}) );
  SetAdjectives( ({"red","simple","silk"}) );
  SetLong("Made to flatter every curve, the red silk "
        "dress is the perfect dress for a dancer.  It has a low "
        "neckline, tight-fitting bodice and long skirt.  "
        "The skirt flares out perfectly when the wearer "
        "twirls.");
  SetVendorType(VT_ARMOUR);
  SetArmourType(A_BODY_ARMOUR);
  SetArmourClass(ARMOUR_CLOTH);
  SetMass(30);
  SetValue(50);
  SetDamagePoints(30);
  SetSize(SIZE_MEDIUM);
  SetMaterial("textile");
  SetWarmth(20);
  SetRepairDifficulty(5);  
  SetRepairSkills( ([
       "textile working" : 1,
  ]) );
}
