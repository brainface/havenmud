#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("staff");
  SetShort("a long, redwood staff");
  SetLong("It is a long, redwood staff.  It looks like a highly effective "
          "weapon.");
  SetHands(2);
  SetId( ({ "staff" }) );
  SetAdjectives( ({ "long", "redwood" }) );
  SetClass(22);
  SetWeaponType("pole");
  SetDamageType(BLUNT);
  SetDamagePoints(900);
  SetValue(500);
  SetMass(225);
  SetMaterials( ({ "wood" }) );
  SetRepairDifficulty(12);
  SetRepairSkills( ([
     "wood working" : 10,
     "weapon smithing" : 10,
     ]) );
 }

