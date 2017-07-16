#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("lube");
  SetMaterial( ({ "metal", "mithril" ]) );
  SetShort("a fancy bottle of lubricant");
  SetId( ({ "lube", "bottle" }) );
  SetAdjectives( ({ "fancy" }) );
  SetLong(
      "This container is a mithril laden and carefully crafted bottle. There appears to be a "
     "viscous liquid contained within. The tip of the bottle has a pouring spout that looks " 
     "like an applicator to portion out careful amounts of the contents within. "
  );
  SetStrength(9001);
  SetDamagePoints(9001);
  SetDamageType(BLUNT);
  SetWeaponType("blunt");
  SetMass(1);
  SetValue(9001);
  SetRepairDifficulty(9001);
  }
