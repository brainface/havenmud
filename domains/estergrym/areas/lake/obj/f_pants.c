// Coded by Tassadar
#include <armour_types.h>
#include <vendor_types.h>
#include <armour_class.h>
#include <size.h>
#include <lib.h>
inherit LIB_ARMOUR;

static void create() {
  ::create();
  SetValue(5);
  SetArmourType(A_PANTS);
  SetVendorType(VT_CLOTHING);
  SetKeyName("fishing pants");
  SetSize(SIZE_MEDIUM);
  SetArmourClass(ARMOUR_CLOTH);
  SetDamagePoints(250);
  SetRepairSkills( ([
    "textile working" : 1,
    ]) );
  SetRepairDifficulty(2);
  SetShort("a pair of old fishing pants");
  SetId( ({ "pants" }) );
  SetAdjectives( ({ "old","fishing" }) );
  SetMaterial( ({ "textile" }) );
  SetWarmth(15);
  SetLong("This is a pair of old fishing pants. They are in foul "
          "shape, but they keep one warm and dry.");
  SetMass(40);
  }
