#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include <armour_class.h>
#include <vendor_types.h>
#include <size.h>

inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("kylin tabard");
  SetId( ({ "tabard" }) );
  SetAdjectives( ({ "intricate", "bright", "white", "kylin" }) );
  SetShort("an intricate bright white tabard");
  SetLong(
    "The symbol of the Kylin religion (a balance with a dragon wrapped around "
    "it) is woven into this tabard. Its soft white color is not meant to detract "
    "from its religious value."
    );
  SetVendorType(VT_CLOTHING);
  SetMass(15);
  SetArmourClass(ARMOUR_CLOTH);
  SetSize(SIZE_SMALL);
  SetValue(15);
  SetMaterial( ({ "textile" }) );
  SetWarmth(10);
  SetRepairSkills( ([
    "textile working" : 4,
    ]) );
  SetRepairDifficulty(10);
  SetDamagePoints(8000);
  // SetProtection(HEAT,   2);
  // SetProtection(MAGIC, 10);
  // SetProtection(COLD,   4);
  SetArmourType(A_CLOAK);
}
