// Torak jan 2012 taken directly from ninja_tower //
// Urien 12.30.12 Goden wear socks on their tails
//                due to unknown tail size difference with Lizardman wrap?
//                Made the vendor unique as it might
//                be linked to other places
#include <lib.h>
#include <armour_types.h>
#include <vendor_types.h>
#include <armour_class.h>
#include <size.h>

inherit LIB_ARMOUR;

static void create() {
  ::create();
  SetKeyName("tail wrap");
  SetShort("a cloth tail wrap");
  SetId( ({ "wrap" }) );
  SetAdjectives( ({ "cloth", "tail" }) );
  SetLong("This cloth tail wrap is laced with string and "
    "when worn around the tail is tied together for a nice "
    "fit. It is slender in size, enough to fit a Goden easily.");
  SetValue(200);
  SetMass(20);
  SetSize(SIZE_MEDIUM);
  SetWarmth(2);
  SetMaterial( ({ "textile" }) );
  SetArmourClass(ARMOUR_CLOTH);
  SetArmourType(A_SOCK);
  SetRestrictLimbs( ({ "tail" }) );
  SetDamagePoints(450);
  SetVendorType(VT_ARMOUR);
  SetRepairDifficulty(15);
}
