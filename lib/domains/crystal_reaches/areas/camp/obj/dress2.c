
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
  SetShort("a purple dress");
  SetId( ({"dress"}) );
  SetAdjectives( ({"purple","simple","cotton"}) );
  SetLong("Small enough for a human child, this simple "
        "purple dress is made of thin cotton. ");
  SetVendorType(VT_ARMOUR);
  SetArmourType(A_BODY_ARMOUR);
  SetArmourClass(ARMOUR_CLOTH);
  SetMass(5);
  SetValue(5);
  SetDamagePoints(10);
  SetSize(SIZE_MEDIUM);
  SetMaterial("textile");
  SetWarmth(5);
  SetRepairDifficulty(4);   
  SetRepairSkills( ([
       "textile working" : 1,
  ]) );
}


