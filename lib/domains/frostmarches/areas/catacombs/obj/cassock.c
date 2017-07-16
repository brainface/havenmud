#include <lib.h>
#include <damage_types.h>
#include <armour_class.h>
#include <size.h>
#include <armour_types.h>
#include <vendor_types.h>

inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("cassock");
  SetId(( { "cassock" } ));
  SetAdjectives( ({ "long", "double-breasted", "black" }) );
  SetShort("a long double-breasted black cassock");
  SetLong("This cassock is a long, black close fitting"
          " robe worn by priests and other holy people."
          " It flares out towares the bottom allowing the"
          " wearer more freedom of movement with their"
          " legs. The collar is about one inch in height."
          " Full sleeves and black buttons complete the"
          " garment.");
  SetMass(60);
  SetMaterial( ({ "textile" }) );
  SetRepairDifficulty(15);
  SetWarmth(20);
  SetValue(700);
  SetDamagePoints(400);
  SetArmourClass(ARMOUR_CLOTH);
  SetSize(SIZE_MEDIUM);
  SetArmourType(A_BODY_ARMOUR);
  SetVendorType(VT_TREASURE | VT_ARMOUR);
}
