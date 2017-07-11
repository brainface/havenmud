//
// filename: elem_staff
// Thoin@Haven 01-16-06
//

#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;
int AttemptWield();

static void create() {
  item::create();
  SetKeyName("elemental staff");
  SetId( ({ "staff" }) );
  SetAdjectives( ({ "elemental", "flaming" }) );
  SetShort("a flaming elemental staff");
  SetLong("This large two-handed staff is entirely made of fire wrapping around "
          "a metal of some kind. The flames surge with great strength and power "
          "but it looks like one could wield the staff without injury."
  );
  SetVendorType(VT_WEAPON);
  SetDamagePoints(2900);
  SetClass(35);
  SetValue(5000);
  SetMass(100);
  SetWeaponType("pole");
  SetHands(2);
  SetDestroyOnSell(1);
  SetMaterial( ({"metal"}) );
  SetRepairSkills( ([
     "metal working" : 40,
  ]) );
  SetRepairDifficulty(60);
  SetDamageType(BLUNT|HEAT);
  SetWield( (: AttemptWield :) );
  SetProperty("magic", "The staff will only allows those strong enough "
                       "to use it.");
}

int AttemptWield() {
  if (this_player()->GetLevel() < 150) {
       this_player()->eventReceiveDamage(this_object(), HEAT, random(500), 0,
                                  this_player()->GetWieldingLimbs() );
    send_messages("are", 
                    "$agent_name $agent_verb burned by a flash of heat from "
                    "the staff.", this_player(), 0, environment(this_player()) );
  eventDestruct();
   return 0;
   }
  send_messages("wield", "$agent_name $agent_verb a flaming elemental staff.",
                this_player(), 0, environment(this_player()) );
   return 1;
  }

int eventStrike(object who) {
  int amt;
  amt = random(50) + 20;
  if (random(25)) return item::eventStrike(who);
  else {
  message("staff action",
    "A %^BOLD%^WHITE%^flash of light%^RESET%^ comes from the staff wielded by " + 
     environment()->GetCapName() + ".", environment(environment()) );
  who->eventBlind(5);
  return (item::eventStrike(who) + amt);
  }
 }
