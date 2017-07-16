#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("mithril hammer");
  SetId( ({ "hammer", }) );
  SetAdjectives( ({ "large", "mirthril" }) );
  SetShort("a large mithril hammer");
  SetLong(
    "Forged completely of mithril (haft, head and all), the "
    "war hammer looks as deadly as any hammer you have ever seen."
    );
  SetMaterial( ({ "mithril" }) );
  SetRepairSkills( ([
    "mithril working" : 12,
    "weapon smithing" : 15
    ]) );
  SetRepairDifficulty(60);
  SetMass(130);
  SetValue(2500);
  SetDamagePoints(4000);
  SetWeaponType("blunt");
  SetDamageType(BLUNT);
  SetClass(25);
  SetVendorType(VT_WEAPON);
  SetProperty("magic", "The material of the hammer itself glows with power.");
  SetProperty("history", "Forged in the legendary forge of Glimmerdin, the "
              "hammer has been in the church for generations.");
}

int eventStrike(object target) {
  
  if(random(10)) return item::eventStrike(target);
  send_messages( ({ "hit", }),
    "$agent_name%^BOLD%^MAGENTA%^ $agent_verb%^RESET%^ $target_name solidly "
    "with $agent_possessive mithril hammer!",
    this_player(), target, environment(target) );
  return item::eventStrike(target) + 40;
}
