#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;
int AttemptWield();

static void create() {
  item::create();
  SetKeyName("frost covered blade");
  SetShort("A frost covered blade");
  SetId( ({ "blade" }) );
  SetAdjectives( ({ "frost", "covered", "frost encased" }) );
  SetWeaponType("knife");
  SetDamageType(SLASH|COLD|MAGIC);
  SetLong("This frost encased blade makes a very slight crackling sound. "
          "It has a very bright blue hue that explodes out the blade. It "
          "appears that it continues to frost over itself constantly. "
          "The thought of wielding this item sends a vicious chill down "
          "even the strongest warrior's spine. ");
  SetClass(45);
  SetMaterials( ({ "metal" }) );
  SetRepairDifficulty(60);
  SetRepairSkills( (["natural working" : 100,
                     "metal working" : 100,
                     "weapon smithing" : 100, ]) );
  SetDamagePoints(3000);
  SetValue(15000);
  SetVendorType(VT_WEAPON);
  SetMass(90);
  SetWield( (: AttemptWield :) );
  SetProperty("magic", "This particular blade can only be controlled by "
                       "an individual strong enough to overcome its frozen "
                       "hilt. ");
  SetProperty("history", "This blade was found by the warriors of the "
                         "early days of this land. It is rumored to have "
                         "been found smashed frozen solid between two "
                         "massive ice bergs. They say however that when "
                         "it was finally removed it, it was warm to the "
                         "touch. ");
}

int AttemptWield() {
  if (this_player()->GetLevel() < 125) {
    this_player()->eventReceiveDamage(this_object(), COLD, random(500), 0,
this_player()->GetWieldingLimbs() );
    send_messages("are", 
          "$agent_name $agent_verb %^BOLD%^%^RED%^scorched%^RESET%^ by a unbearably cold rush from "
          "the blade.", 
          this_player(), 0, environment(this_player()) );
   return 0;
   }
  send_messages("wield", "$agent_name $agent_verb the %^BOLD%^%^BLUE%^frost%^RESET%^ covered blade.",
this_player(), 0, environment(this_player()) );
  return 1;
}

int eventStrike(object who) {
  if (random(30)) return item::eventStrike(who);
  else {
  message("blade action", "A cloud of snow %^BOLD%^%^WHITE%^erupts%^RESET%^ into the air from the frost covered blade ",
          "wielded by " +  environment()->GetCapName() + ".", environment(environment()) );
  who->SetParalyzed(3);
  who->eventCollapse();
  return (item::eventStrike(who) + 15);
  }
}
