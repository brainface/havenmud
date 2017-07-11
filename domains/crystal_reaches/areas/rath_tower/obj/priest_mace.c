#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("iron mace");
  SetProperty("magic",
    "This mace has an evil presence of its own.");
  SetShort("a dark iron mace");
  SetId( ({ "mace" }) );
  SetAdjectives( ({ "dark", "iron" }) );
  SetVendorType(VT_WEAPON);
  SetMaterial( ({ "metal" }) );
  SetRepairDifficulty(20);
  SetLong("This large mace is a culmination of evil.  Its handle is "
          "inscribed with symbols of evil and worship of Rath Khan.");
  SetClass(18);
  SetMass(120);
  SetValue(1260);
  SetDamagePoints(3600);
  SetWeaponType("blunt");
  SetDamageType(BLUNT|MAGIC);
  }

int eventStrike(object target) {
   if (!random(6)) {
    send_messages( "", 
      "Something evil %^RED%^glitters%^RESET%^ from $agent_possessive_noun mace as it strikes $target_name!",
      environment(), target, environment(environment()));
    return (item::eventStrike(target) * 2);
    }
  return (item::eventStrike(target));
}
