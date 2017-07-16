
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
  SetKeyName("skirt");
  SetShort("a black silk skirt");
  SetId( ({"skirt"}) );
  SetAdjectives( ({"silk","black","ankle-length","full"}) );
  SetLong("The full, ankle-length skirt is made of fine "
          "black silk.  It is tight around the waist and flares "
          "out at the bottom.");
  SetVendorType(VT_ARMOUR);
  SetArmourType(A_PANTS);
  SetArmourClass(ARMOUR_CLOTH);
  SetMass(30);
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

