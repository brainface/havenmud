
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
  SetKeyName("thobe");
  SetId(( { "thobe", "white thobe", "cotton thobe", 
    "white cotton thobe" } ));
  SetShort("a white cotton thobe");
  SetLong("The thobe is a traditional garment worn by the"
  " Desert Kylin men. Made of a light cotton fabric,"
          " this thobe is a long, hoodless robe that spans"
  " the length of the body from neck to ankles. Very"
  " simple and elegant, the collar is about an inch"
  " in height and fits snugly around the neck.");
  SetMass(60);
  SetMaterial( ({ "textile" }) );
  SetRepairDifficulty(15);
  SetWarmth(20);
  SetValue(100);
  SetDamagePoints(400);
  SetArmourClass(ARMOUR_CLOTH);
  SetSize(SIZE_MEDIUM);
  SetArmourType(A_BODY_ARMOUR);
  SetVendorType(VT_TREASURE | VT_ARMOUR);
}
