//
// filename: elem_sword
// Thoin@Haven 01-16-06
//

#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;
int AttemptWield();

static void create() {
  item::create();
  SetKeyName("elemental sword");
  SetId( ({ "sword" }) );
  SetAdjectives( ({ "elemental", "flaming" }) );
  SetShort("a flaming elemental sword");
  SetLong("This medium sized knife has a metal hilt but the blade is "
          "consumed in flames. The flames flicker and glow with intense "
          "strength and power. "
  );
  SetVendorType(VT_WEAPON);
  SetDamagePoints(2900);
  SetClass(35);
  SetValue(5000);
  SetMass(100);
  SetWeaponType("slash");
  SetDestroyOnSell(1);
  SetMaterial( ({"metal"}) );
  SetRepairSkills( ([
     "metal working" : 40,
  ]) );
  SetRepairDifficulty(60);
  SetDamageType(SLASH|HEAT);
  SetWield( (: AttemptWield :) );
  SetProperty("magic", "The sword will only allows those strong enough "
                       "to use it.");
}

int AttemptWield() {
  if (this_player()->GetLevel() < 150) {
       this_player()->eventReceiveDamage(this_object(), HEAT, random(500), 0,
                                  this_player()->GetWieldingLimbs() );
    send_messages("are", 
                    "$agent_name $agent_verb burned by a flash of heat from "
                    "the sword.", this_player(), 0, environment(this_player()) );
  eventDestruct();
   return 0;
   }
  send_messages("wield", "$agent_name $agent_verb a flaming elemental sword.",
                this_player(), 0, environment(this_player()) );
   return 1;
  }

int eventStrike(object who) {
  int amt;
  amt = random(50) + 20;
  if (random(25)) return item::eventStrike(who);
  else {
  message("sword action",
    "A %^BOLD%^WHITE%^flash of light%^RESET%^ comes from the sword wielded by " + 
     environment()->GetCapName() + ".", environment(environment()) );
  who->eventBlind(1, 5);
  return (item::eventStrike(who) + amt);
  }
 }
