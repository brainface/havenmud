//
// filename: eknife2
// Thoin@Haven 01-16-06
//

#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;
int AttemptWield();

static void create() {
  item::create();
  SetKeyName("elemental knife");
  SetId( ({ "knife" }) );
  SetAdjectives( ({ "elemental", "shimmering" }) );
  SetShort("a shimmering elemental knife");
  SetLong("This medium sized knife has a metal hilt but the blade is "
          "consumed in a bright light. The flames flicker and glow with intense "
          "strength and power. "
  );
  SetVendorType(VT_WEAPON);
  SetDamagePoints(2900);
  SetClass(50);
  SetValue(10000);
  SetMass(100);
  SetWeaponType("knife");
  SetDestroyOnSell(1);
  SetMaterial( ({"metal"}) );
  SetRepairSkills( ([
     "metal working" : 40,
  ]) );
  SetRepairDifficulty(60);
  SetDamageType(SLASH|HEAT|MAGIC);
  SetWield( (: AttemptWield :) );
  SetProperty("magic", "The knife will only allows those strong enough "
                       "and without knowledge of evil to use it.");
}

int AttemptWield() {
  if (this_player()->GetLevel() < 200) {
       this_player()->eventReceiveDamage(this_object(), HEAT, 500, 0,
                                  this_player()->GetWieldingLimbs() );
    send_messages("are", 
                    "$agent_name $agent_verb burned by a flash of heat from "
                    "the knife.", this_player(), 0, environment(this_player()) );
  eventDestruct();
   return 0;
   }
  send_messages("wield", "$agent_name $agent_verb a shimmering elemental knife.",
                this_player(), 0, environment(this_player()) );
   return 1;
  }

int eventStrike(object who) {
  int amt;
  int amount = random(20);
  amt = random(50) + 100;
  if (random(15)) return item::eventStrike(who);
  else {
  message("knife action",
    "An explosion of %^BOLD%^%^WHITE%^light%^RESET%^ comes from the knife wielded by " + 
     environment()->GetCapName() + ".", environment(environment()) );
  who->AddStaminaPoints(-amount);
  environment()->AddStaminaPoints(amount);
  environment()->eventWeaponRound(who, environment()->GetWielded());
  return (item::eventStrike(who) + amt);
  }
 }
