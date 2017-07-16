

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
  SetShort("a pair of black pants");
  SetId( ({"pants"}) ); 
  SetAdjectives( ({"a pair of", "black"}) );
  SetLong(
    "These black pants are comfortable and durable and look "
    "designed to be worn for running around and playing. They are "
    "cuffed at the bottom, to avoid trailing in the dirt."
  );
  SetVendorType(VT_ARMOUR);
  SetArmourType(A_PANTS);
  SetArmourClass(ARMOUR_CLOTH);
  SetMass(5);
  SetValue(5);
  SetDamagePoints(10);
  SetSize(SIZE_MEDIUM);
  SetMaterial("textile");
  SetWarmth(10);
  SetRepairDifficulty(4);   
  SetRepairSkills( ([
       "textile working" : 1,
  ]) );
}


