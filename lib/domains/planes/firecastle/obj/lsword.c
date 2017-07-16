//
// filename: lsword
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
  SetId( ({ "sword", "spell binder" }) );
  SetAdjectives( ({ "elemental", "glowing" }) );
  SetShort("a glowing elemental sword");
  SetLong("This medium sized sword has a metal hilt but the blade is "
          "consumed in flames. The flames flicker and glow with intense "
          "strength and power. "
  );
  SetVendorType(VT_WEAPON);
  SetDamagePoints(2900);
  SetClass(50);
  SetValue(10000);
  SetMass(100);
  SetWeaponType("slash");
  SetDestroyOnSell(1);
  SetMaterial( ({"metal"}) );
  SetRepairSkills( ([
     "metal working" : 40,
  ]) );
  SetRepairDifficulty(60);
  SetDamageType(SLASH|HEAT|MAGIC);
  SetWield( (: AttemptWield :) );
  SetProperty("magic", "The sword will only allows those strong enough "
                       "to use it. The name of the sword is Spell Binder "
                       "it was given such a name for its ability to strip "
                       "others of magic.");
}

int AttemptWield() {
  if (this_player()->GetLevel() < 200) {
       this_player()->eventReceiveDamage(this_object(), HEAT, 500, 0,
                                  this_player()->GetWieldingLimbs() );
    send_messages("are", 
                    "$agent_name $agent_verb burned by a flash of heat from "
                    "the sword.", this_player(), 0, environment(this_player()) );
  eventDestruct();
   return 0;
   }
  send_messages("wield", "$agent_name $agent_verb a glowing elemental sword.",
                this_player(), 0, environment(this_player()) );
   return 1;
  }

int eventStrike(object who) {
  int amt;
  int amount = random(20);
  amt = random(50) + 50;
  if (random(15)) return item::eventStrike(who);
  else {
  message("sword action",
    "A spark of %^BLUE%^light%^RESET%^ comes from the sword wielded by " + 
     environment()->GetCapName() + ".", environment(environment()) );
  who->AddStaminaPoints(-amount);
  environment()->AddStaminaPoints(amount);
  if (sizeof(who->GetMagicProtection()) > 1) {
  who->RemoveMagicProtection(1);
  }
  return (item::eventStrike(who) + amt);
  }
 }
