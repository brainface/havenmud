#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

int CheckWield();
static void create() {
  item::create();
  SetKeyName("zweihander");
  SetId( ({ "sword", "zweihander" }) );
  SetAdjectives( ({ "steel", "long" }) );
  SetShort("a long steel zweihander");
  SetLong(
    "This is a dramatically over-sized two-bladed sword."
    " It's grip is large enough to accomodate three hands,"
    " and the blade is nearly six feet in length."
  );
  SetClass(18);
  SetDamagePoints(1800);
  SetValue(1500);
  SetWeaponType("slash");
  SetDamageType(SLASH);  
  SetMass(200);
  SetMaterial( ({ "metal" }) );
  SetRepairSkills( ([
        "metal working" : 15,
        "weapon smithing" : 15,
        ]) );
  SetRepairDifficulty(35);
  SetVendorType(VT_WEAPON);
  SetHands(2);
  SetWield( (: CheckWield :) );
}


int CheckWield() {
  object who = this_player();
  if (who->GetStatLevel("strength") > 50) {
   send_messages("wield", 
    "$agent_name $agent_verb a long steel zweihander.", who, 0, environment(who) );
    return 1;
     }
   send_messages("fail", 
      "$agent_name $agent_verb to wield a long steel zweihander.",
        who, 0, environment(who) );
    return 0;
  }

int eventStrike(object who) {
  if (!random(20)) {
   send_messages( ({ "twirl", "slice" }),
     "$agent_name $agent_verb $agent_possessive zweihander over $agent_possessive " +
     "head and $agent_verb into $target_name!",
      environment(), who, environment(who) );
    return (item::eventStrike(who) + 35);
    }
  return item::eventStrike(who);
  }
