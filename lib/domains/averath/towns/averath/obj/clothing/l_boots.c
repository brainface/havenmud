#include <lib.h>
#include <vendor_types.h>
#include <size.h>
#include <armour_class.h>
#include <armour_types.h>

inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("boots");
  SetId(( {"boots" } ));
  SetShort("a pair of laced leather boots");
  SetAdjectives( ({"pair","of","laced","leather"}) );
  SetLong(
    "This pair of dark leather boots rises halfway to the knee, with black "
    "laces threaded through brass eyelets. The soles are a hard boiled leather."
  );
  SetProperty("multiples", 1);
  SetMass(125);
  SetVendorType(VT_ARMOUR);
  SetArmourClass(ARMOUR_REINFORCED);
  SetSize(SIZE_MEDIUM);
  SetMaterial( ({"leather"}) );
  SetWarmth(5);
  SetRepairDifficulty(70);
  SetValue(1500);
  SetDamagePoints(15000);
  SetArmourType(A_BOOT);
  SetWear("You lace your boots tight.");
}

