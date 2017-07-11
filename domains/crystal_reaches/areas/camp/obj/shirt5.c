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
  SetShort("a green cotton shirt");
  SetId( ({"shirt"}) );
  SetAdjectives( ({"green","cotton"}) );
  SetLong("The cotton shirt is tightly fitted, yet "
          "comfortable.  The sleeves are short and "
          "tight. The shirt laces up and is "
          "dark green in color.");
  SetVendorType(VT_ARMOUR);
  SetArmourType(A_SHIRT);
  SetArmourClass(ARMOUR_CLOTH);
  SetMass(20);
  SetValue(25);
  SetDamagePoints(20);
  SetSize(SIZE_MEDIUM);
  SetMaterial("textile");
  SetRepairDifficulty(5);  
  SetRepairSkills( ([
       "textile working" : 1,
  ]) );
}
