#include <armour_types.h>
#include <vendor_types.h>
#include <lib.h>

inherit LIB_ARMOUR;

static void create() {
  ::create();
  SetValue(30);
  SetArmourType(A_PANTS);
  SetVendorType(VT_CLOTHING);
  SetKeyName("dark pants");
  SetDamagePoints(350);
  SetRepairSkills( ([
    "textile working" : 2,
  ]) );
  SetRepairDifficulty(3);
  SetShort("a common pair of dark pants");
  SetId( ({ "pants" }) );
  SetAdjectives( ({ "common", "dark" }) );
  SetMaterial( ({ "textile" }) );
  SetLong("These pants are made of a sturdy, dark fabric and are a popular "
          "choice of clothing by the citizens of Keryth.");
  SetMass(40);
  SetWarmth(20);
}
