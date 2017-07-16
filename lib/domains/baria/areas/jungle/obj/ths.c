/*  A two handed sword */
#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;
int WieldMe();

static void create() {
  item::create();
  SetKeyName("two-handed sword");
  SetShort("a large two-handed sword");
  SetHands(2);
  SetClass(20);
  SetMass(300);
  SetValue(500);
  SetWeaponType("slash");
  SetDamageType(SLASH);
  SetId( ({ "sword" }) );
  SetAdjectives( ({ "two-handed" }) );
  SetDamagePoints(1900);
  SetLong(
     "This large piece of metal is a two handed sword. It "
     "looks to have been forged out of one solid slab of iron, "
     "allowing it added durability and usefulness in battle. The "
     "blade looks to be about five feet long, and almost six "
     "including the hilt. This sword looks as though it could add "
     "an extra punch if wielded by a person of sufficient strength. "
  );
  SetVendorType(VT_WEAPON);
  SetMaterial( ({ "metal" }) );
  SetRepairSkills( ([
     "metal working" : 8,
     "weapon smithing" : 8,
  ]) );
  SetRepairDifficulty(20);
  SetWield( (: WieldMe :) );
 }

int WieldMe() {
  object who = this_player();
  if (!userp(who)) { return 1; }
  if (who->GetStatLevel("strength") > 50) {
   send_messages("wield", 
    "$agent_name $agent_verb a two-handed sword.", who, 0, environment(who) );
    return 1;
     }
   send_messages("fail", 
      "$agent_name $agent_verb to wield a two-handed sword.",
        who, 0, environment(who) );
    return 0;
  }

int eventStrike(object who) {
  if (!random(20)) {
   send_messages( ({ "heft", "swing" }),
     "$agent_name $agent_verb $agent_possessive two-handed sword " +
     "and $agent_verb with a cleaving blow!",
      environment(), who, environment(who) );
    return (item::eventStrike(who) + 20);
    }
  return item::eventStrike(who);
  }
