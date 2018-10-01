//std/clothing/body/black_robe.c

#include <lib.h>
#include <damage_types.h>
#include <armour_class.h>
#include <armour_types.h>
#include <vendor_types.h>
#include <size.h>

inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetVendorType(VT_ARMOUR);
  SetArmourType(A_BODY_ARMOUR);
  SetKeyName("a black robe");
  SetId( ({ "robe","garment","clothing" }) );
  SetShort("a black robe");
  SetAdjectives( ({ "black","heavy"}) );
  SetLong(
    "This heavy black robe has seen better days. It is a fairly "
    "well made article of clothing. Embroidered on the trim of "
    "the collar, the cuffs and the back of the robe are red "
    "equilateral triangles, consisting of three overlapping lines, "
    "with one of the points facing down, which one of the symbols "
    "of Melchezidek. This garment would likely offer a protection "
    "against the cold."
    );
  SetWarmth(30);
  SetRepairSkills( ([ 
    "textile working" : 15,
    ]) );
  SetMaterial( ({ "textile" }) );
  SetRepairDifficulty(40);
  SetMass(80);
  SetValue(100);
  SetDamagePoints(650);
  SetArmourClass(ARMOUR_CLOTH);
  SetSize(SIZE_MEDIUM);
}
