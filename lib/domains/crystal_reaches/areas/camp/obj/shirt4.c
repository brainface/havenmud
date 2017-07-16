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
  SetShort("a small cotton shirt");
  SetId( ({"shirt"}) );
  SetAdjectives( ({"cotton","small"}) );
  SetLong("Small enough for a child, the shirt is made of "
          "a dark green cotton.  It is simple, comfortable, and "
          "durable.");
  SetVendorType(VT_ARMOUR);
  SetArmourType(A_SHIRT);
  SetArmourClass(ARMOUR_CLOTH);
  SetMass(20);
  SetValue(20);
  SetDamagePoints(15);
  SetSize(SIZE_MEDIUM);
  SetMaterial("textile");
  SetWarmth(10);
  SetRepairDifficulty(4);   
  SetRepairSkills( ([
       "textile working" : 1,
  ]) );
}
