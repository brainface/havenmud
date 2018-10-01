#include <lib.h>
#include <damage_types.h>
#include <armour_class.h>
#include <armour_types.h>
#include <vendor_types.h>
#include <size.h>

inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("boot sock");
  SetId( ({ "sock" }) );
  SetAdjectives( ({ "lacey", "black", "boot" }) );
  SetShort("a lacey black boot sock");
  SetLong(
    "A fine garment of black lace, this sock fits snuggly around the feet, its "
    "threads tightly woven around the toes and heels. The thread is looser up "
    "the top and calf, revealing bits of skin in between an intricate pattern "
    "of black roses and flames. It ends just below the knee with a delicate "
    "lacey frill."
  );
  SetMass(20);
  SetValue(2000);
  SetWarmth(1);
  SetMaterial( ({ "textile" }) );
  SetArmourClass(ARMOUR_CLOTH);
  SetVendorType(VT_CLOTHING);
  SetArmourType(A_LONG_SOCK);
  SetRepairDifficulty(70);
  SetSize(SIZE_MEDIUM);
  SetDamagePoints(1000);
}

