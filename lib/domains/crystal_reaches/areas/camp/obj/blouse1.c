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
  SetKeyName("blouse");
  SetShort("a peasant blouse");
  SetId( ({"blouse"}) );
  SetAdjectives( ({"silk","teal"}) );
  SetLong("The teal silk peasant's blouse "
          "is off the shoulder and very loose.  There "
          "are ruffles along the neck and cuffs.");
  SetVendorType(VT_ARMOUR);
  SetArmourType(A_SHIRT);
  SetArmourClass(ARMOUR_CLOTH);
  SetMass(30);
  SetValue(50);
  SetDamagePoints(25);
  SetSize(SIZE_MEDIUM);
  SetMaterial("textile");
  SetWarmth(10);
  SetRepairDifficulty(5);   
  SetRepairSkills( ([
       "textile working" : 1,
  ]) );
}
