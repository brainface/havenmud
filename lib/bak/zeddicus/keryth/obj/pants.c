#include <armour_types.h>
#include <vendor_types.h>
#include <lib.h>
inherit LIB_ARMOUR;

static void create() {
  ::create();
  SetValue(25);
  SetArmourType(A_PANTS);
  SetVendorType(VT_CLOTHING);
  SetKeyName("black pants");
  SetDamagePoints(300);
  SetRepairSkills( ([
    "textile working" : 1,
  ]) );
  SetRepairDifficulty(2);
  SetShort("a pair of black pants");
  SetId( ({ "pants" }) );
  SetAdjectives( ({ "black" }) );
  SetMaterial( ({ "textile" }) );
  SetLong("These black pants have seen much use, but are still quite "
          "sturdy.");
  SetMass(40);
  SetMaterial("textile");
  SetWarmth(15);
}
