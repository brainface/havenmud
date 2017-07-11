
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
  SetKeyName("pants");
  SetShort("a pair of red silk pants");
  SetId( ({"pants"}) ); 
  SetAdjectives( ({"a pair of","red","silk"}) );
  SetLong("The billowy red pants are made of "
        "fine silk. They are very easy to move in "
        "and are comfortable.");
  SetVendorType(VT_ARMOUR);
  SetArmourType(A_PANTS);
  SetArmourClass(ARMOUR_CLOTH);
  SetMass(20);
  SetValue(20);
  SetDamagePoints(30);
  SetSize(SIZE_MEDIUM);
  SetMaterial("textile");
  SetWarmth(15);
  SetRepairDifficulty(5);   
  SetRepairSkills( ([
       "textile working" : 1,
  ]) );
}


