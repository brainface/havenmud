//  a badass knife for a badass
//  this should probably have some ridiculously awesome emotes when used
//    like blood flowing... and opens a grievous wound.. blah blah
//  also can it be poisoned? :) because that would rock. even if it's just a little

// Mahkefel:
//  okay, so here's what this does. Bleeding was redundant with donnie's special, and
//  mel already made the awesome bleed dagger. So I ignored all that and made something cool
//
//  The dagger, when it "procs" about 1 hit in 10, adds 2 points to agility & coord, and
//   restores some stamina, as it DRAINS YOUR SOUL. The bonus stacks with itself up to
//   10. It also stacks with EVERYTHING, so I made it not go to high. So the more you
//   stab someone the more unholy agility you get.

#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

int CheckWield();

static void create() {
  item::create();
  SetKeyName( "dagger" );
  SetId( ({ "dagger" }) );
  SetAdjectives( ({ "runed" }) );
  SetShort( "a runed dagger" );
  SetLong(
     "Blood red runes etch into the hilt of this grievous looking "
     "dagger and down the blade itself, giving the appearance of the "
     "flow of blood from palm to tip. The blade itself is made from "
     "dark metals to help conceal it from an unobserving eye."
     );
  SetClass(30);
  SetDamagePoints(3000);
  SetValue(5000);
  SetWeaponType("knife");
  SetDamageType(PIERCE|MAGIC);
  SetMass(300);
  SetMaterial( ({ "metal" }) );
  SetVendorType(VT_WEAPON);
  SetHands(1);
  SetRepairDifficulty(50);
  SetProperty("history",
     "Popular belief is that that dagger was etched in runes through the magic "
     "of a powerful sea witch."
     );
  SetProperty("magic",
    "This weapon is affected by a rather cruel enchantment that channels the "
    "life force of the victim into the wielder, granting them increased "
    "mobility and greater reflexes."
    );
  SetProperty("statbonus",0);
}


int DoStatBonus() {

  //increment by 1 each time, to 10
  if (GetProperty("statbonus") < 10) {
    SetProperty("statbonus",GetProperty("statbonus") + 1);
    this_player()->eventPrint("You feel your %^RED%^blood%^RESET%^ start to "
      "race and your %^YELLOW%^vitality%^RESET%^ return to you!");
  }
  this_player()->AddStatBonus("coordination", (: CheckWield :) );
  this_player()->AddStatBonus("agility", (: CheckWield :) );
  this_player()->AddStaminaPoints(GetProperty("statbonus") * random(10)+10);
  this_player()->eventDisplayStatus();
  if (this_player()->GetTestChar()) debug("Someone gained a stat bonus: " +GetProperty("statbonus"));

  return 1;
}

int CheckWield() {
  return GetProperty("statbonus");
}

mixed eventUnequip(object who) {
  who->RemoveStatBonus("coordination", this_object());
  who->RemoveStatBonus("agility", this_object());
  if(GetProperty("statbonus") > 0) {
    send_messages(({"stumble","sheathe"}),
      "$agent_name%^YELLOW%^ $agent_verb clumsily%^RESET%^ as "
      "$agent_nominative $agent_verb " + GetShort() + ".",
      who, 0, environment(who) );
    SetProperty("statbonus",0);
  }
  if (who->GetTestChar()) debug("Unwielding dagger, bonus should be lost");
  item::eventUnequip(who);
}

int eventStrike(object who) {
  int nolive = who->GetUndead();
  int amount = random(50)+5;
  object wielder = environment();

  if (!random(10)) {
    if (nolive == 0) { // if not a zombie thing
      send_messages("howl","$agent_possessive_noun $agent_verb with glee as "
        "%^BOLD%^BLACK%^sickly tendrils of magic %^RESET%^%^RED%^flow%^RESET%^ "
        "from the wound and into $agent_possessive dagger!",
        wielder,who,environment(who) );
       if (wielder->GetTestChar()) debug("dagger proc'd");
       DoStatBonus();
       return (item::eventStrike(who) + amount);
    }
  }
  return (item::eventStrike(who));
}

