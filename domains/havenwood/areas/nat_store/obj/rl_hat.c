// so apparently they used to make these.
// fancy hats with metal skullcaps.
///   They probably weren't cowboy hats though!
#include <lib.h>
#include <vendor_types.h>
#include <size.h>
#include <armour_class.h>
#include <armour_types.h>

inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("hat");
  SetId(( {"hat" } ));
  SetShort("a wide brimmed leather hat");
  SetAdjectives( ({"wide", "brimmed","leather"}) );
  SetLong(
    "This hat is made of fashionable black leather. The crown is creased "
    "stylishly, and the wide brim shades the wearer from the hot sun. "
    "A thick steel cap is hidden under the crown of the hat, providing "
    "some protection from surprise attacks to the skull without impeding "
    "aesthetics."
  );
  SetMass(50);
  SetVendorType(VT_ARMOUR);
  SetArmourClass(ARMOUR_REINFORCED);
  SetSize(SIZE_MEDIUM);
  SetMaterial( ({"metal","leather"}) );
  SetWarmth(5);
  SetRepairDifficulty(70);
  SetValue(2500);
  SetDamagePoints(25000);
  SetArmourType(A_HELMET);
  SetWear("The hat's skullcap isn't quite as well padded as it should be.");
}

