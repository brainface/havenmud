/*  The Staff of Rath Khan */
#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;
int AttemptWield();

static void create() {
  item::create();
  SetKeyName("evil looking staff");
  SetShort("a long, evil looking staff");
  SetId( ({ "staff" }) );
  SetAdjectives( ({ "long", "evil", "looking", "evil looking" }) );
  SetWeaponType("pole");
  SetDamageType(BLUNT|COLD);
  SetLong("This evil looking staff has a certain uneasy aura to it "
          "which makes all but the stout at heart uncertain that they "
          "wish to touch it.");
  SetClass(45);
  SetMaterials( ({ "mithril" }) );
  SetRepairDifficulty(60);
  SetDamagePoints(2500);
  SetValue(6000);
  SetVendorType(VT_WEAPON);
  SetMass(180);
  SetWield( (: AttemptWield :) );
  SetProperty("magic", "This staff of evil can only be used by the most "
                       "evil of persons.");
  SetProperty("history", "This is the famed Staff of Rath Khan.");
}

int AttemptWield() {
  if (this_player()->GetMorality() > -500) {
    this_player()->eventReceiveDamage(this_object(), COLD, random(500), 0, this_player()->GetWieldingLimbs() );
    send_messages("are", 
          "$agent_name $agent_verb seared by a cold flash from the staff.", 
          this_player(), 0, environment(this_player()) );
   return 0;
   }
  send_messages("wield", "$agent_name $agent_verb an evil looking staff.", this_player(), 0, environment(this_player()) );
  return 1;
}

int eventStrike(object who) {
  if (random(40)) return item::eventStrike(who);
  else {
  message("staff action", "A chill aura eminates from the evil staff wielded by " +  environment()->GetCapName() + ".", environment(environment()) );
  who->SetParalyzed(2);
  who->eventCollapse();
  return (item::eventStrike(who) + 15);
  }
}
