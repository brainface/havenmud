/* Mahkefel 2017
 * hey look flax
 *
 */

#include <lib.h>
#include <meal_types.h>
#include <vendor_types.h>

inherit LIB_MEAL;

static void create() {
  ::create();
  SetKeyName("flax");
  SetShort("a stalk of flax");
  SetId( ({ "flax", "stalk" }) );
  SetAdjectives( ({"stalk","of" }) );
  SetPortions(1);
  SetLong("An uprooted flax plant, valued both for its seeds and fiberous stalk.");
  SetMass(5);
  SetStrength(10);
  SetValue(50);
  SetMealMessages( ({
    "You chew on some oily flax seeds.",
    "$N chews some oily flax seeds.",
  }) );

  SetVendorType(VT_FOOD|VT_PLANT);
  SetMaterials( ({ "textile" }) );
  
  // allows it to be spun into thread.
  SetProperty("craft_fiber", 1);
}

direct_attach_obj_to_obj() {
  return 1;
}

