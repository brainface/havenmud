
#include <lib.h>
#include <damage_types.h>
#include <armour_class.h>
#include <size.h>
#include <armour_types.h>
#include <vendor_types.h>

inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("robe");
  SetId(( { "robe", "black robe" } ));
  SetShort("a thick black robe");
  SetLong("This robe is made of a thick black"
          " cloth. The hems are all done with"
          " a silver thread that compliments"
          " the silver lining of the sleeves."
          " Around the collar an overlapping"
          " geometric pattern has been sewn"
          " with silver thread.");
  SetMass(75);
  SetMaterial( ({ "textile" }) );
  SetRepairDifficulty(15);
  SetWarmth(40);
  SetValue(150);
  SetDamagePoints(600);
  SetArmourClass(ARMOUR_CLOTH);
  SetSize(SIZE_MEDIUM);
  SetArmourType(A_BODY_ARMOUR);
  SetVendorType(VT_TREASURE | VT_ARMOUR);
}



