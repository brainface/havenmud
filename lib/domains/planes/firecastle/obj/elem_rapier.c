//
// filename: elem_rapier
// Thoin@Haven 01-16-06
//

#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;
int AttemptWield();

static void create() {
  item::create();
  SetKeyName("elemental rapier");
  SetId( ({ "rapier" }) );
  SetAdjectives( ({ "sparkling" }) );
  SetShort("a sparkling rapier");
  SetLong("This medium sized rapier has a metal hilt but the blade is "
          "made of ice. The ice sparkles and glitters and smoke slowly "
          "ripples out from the blade. "
  );
  SetVendorType(VT_WEAPON);
  SetDamagePoints(2900);
  SetClass(35);
  SetValue(5000);
  SetMass(100);
  SetWeaponType("pierce");
  SetDestroyOnSell(1);
  SetMaterial( ({"metal"}) );
  SetRepairSkills( ([
     "metal working" : 40,
  ]) );
  SetRepairDifficulty(60);
  SetDamageType(PIERCE|COLD);
  SetWield( (: AttemptWield :) );
  SetProperty("magic", "The rapier will only allows those strong enough "
                       "to use it.");
}

int AttemptWield() {
  if (this_player()->GetLevel() < 150) {
       this_player()->eventReceiveDamage(this_object(), COLD, random(500), 0,
                                  this_player()->GetWieldingLimbs() );
    send_messages("are", 
                    "$agent_name $agent_verb seared by the cold of "
                    "the rapier.", this_player(), 0, environment(this_player()) );
  eventDestruct();
   return 0;
   }
  send_messages("wield", "$agent_name $agent_verb a sparkling rapier.",
                this_player(), 0, environment(this_player()) );
   return 1;
  }

int eventStrike(object who) {
  int amt;
  amt = random(50) + 20;
  if (random(25)) return item::eventStrike(who);
  else {
  message("rapier action",
    "A gust of %^BOLD%^WHITE%^freezing wind%^RESET%^ comes from the rapier wielded by " + 
     environment()->GetCapName() + ".", environment(environment()) );
  who->SetParalyzed(2);
  return (item::eventStrike(who) + amt);
  }
 }
