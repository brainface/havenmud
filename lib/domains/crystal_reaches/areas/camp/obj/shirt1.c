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
  SetKeyName("shirt");
  SetShort("a white cotton shirt");
  SetId( ({"shirt"}) );
  SetAdjectives( ({"white","cotton"}) );
  SetLong("The loose cotton shirt is easy to move "
          "in.  The cuffs are fitted to ensure they don't "
          "get caught on sharp objects."
          "  The shirt is open to mid-chest.");
  SetVendorType(VT_ARMOUR);
  SetArmourType(A_SHIRT);
  SetArmourClass(ARMOUR_CLOTH);
  SetMass(30);
  SetValue(35);
  SetDamagePoints(20);
  SetSize(SIZE_MEDIUM);
  SetMaterial("textile");
  SetWarmth(15);
  SetRepairDifficulty(5);  
  SetRepairSkills( ([
       "textile working" : 1,
  ]) );
}
