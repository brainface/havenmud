#include <lib.h>
#include <damage_types.h>
#include <armour_class.h>
#include <size.h>
#include <armour_types.h>
#include <vendor_types.h>

inherit LIB_ARMOUR;

static void create()
{
  armour::create();
  SetKeyName("cap");
  SetId(( { "hat", "black hat", "pointed hat", 
    "black pointed hat" } ));
  SetShort("a black pointed hat");
  SetLong("This black hat is about eight inches tall"
          " and is conically shaped. Soft and"
          " well-crafted, this cap looks very"
          " comfortable. The hem has been decorated"
          " with an overlapping geometric pattern in"
          " silver thread.");
  SetMass(60);
  SetMaterial( ({ "textile" }) );
  SetRepairDifficulty(15);
  SetWarmth(20);
  SetValue(120);
  SetDamagePoints(400);
  SetArmourClass(ARMOUR_CLOTH);
  SetSize(SIZE_MEDIUM);
  SetArmourType(A_HELMET);
  SetVendorType(VT_TREASURE | VT_ARMOUR);
}
