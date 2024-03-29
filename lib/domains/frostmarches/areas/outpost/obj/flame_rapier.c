#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>

inherit LIB_ITEM;

int AttemptWield();

static void create() {
  item::create();
  SetKeyName("mithril rapier");
  SetShort("a mithril rapier");
  SetId( ({ "rapier", "sword" }) );
  SetAdjectives( ({ "mithril" }) );
  SetClass(45);
  SetMass(40);
  SetValue(5000);
  SetDamagePoints(5000);
  SetVendorType(VT_WEAPON);
  SetWeaponType("pierce");
  SetMaterial( ({ "mithril" }) );
  SetRepairDifficulty(80);
  SetDamageType(PIERCE|HEAT);
  SetWield( (: AttemptWield :) );
  SetLong(
    "The rapier is forged completely out of mithril with the hilt "
    "looking like a dragon with ruby eyes and its wings protecting "
    "the wielder's hand. The blade is long and slender with "
    "mystic symbols on the base of the blade. A flame from the "
    "dragon's mouth encases the blade without burning the wielder." );
  SetProperty("magic", 
              "This rapier was created for the Grand Master Inquisitor "
              "by dwarven armourers and given its flame attack by Kylin "
              "enchanters and priests.");
}


int AttemptWield() {
  if((this_player()->GetReligion() != "Kylin")){
    if(this_player()->GetMorality() < 1000) {
      this_player()->eventReceiveDamage(this_object(), HEAT, random(500), 0,
                                        this_player()->GetWieldingLimbs() );
      send_messages("are", "$agent_name $agent_verb incerated by a flame from "
                    "the blade.", this_player(), 0, environment(this_player()) );
     return 0;
    }
  }
  send_messages("wield", "$agent_name $agent_verb a mithril rapier.",
                this_player(), 0, environment(this_player()) );
  return 1;
}

int eventStrike(object target) {
  int amt;
  amt = random(20);
  if (!(random(5))) {
  switch (amt) {
    case 0..15:
      message("environment",
        "%^BOLD%^%^RED%^The blade glows a little brighter from the dragon's flame.%^RESET%^",
        environment(target));
     amt += 20;
     break;
    case 16..20:
      message("environment",
        "%^RED%^The dragon on the hilt open his mouth breathing an incinerating flame towards " 
        + target->GetCapName() + ". %^RESET%^",environment(target));
      amt += 40;
      if(environment(this_object())->GetSkill("fire magic"))
        amt +=  (environment(this_object())->GetSkillLevel("fire magic"))/25;
    
      break;
    }
  return item::eventStrike(target) + amt;
  }
  return item::eventStrike(target);
 }


