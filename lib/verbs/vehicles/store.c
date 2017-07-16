// Mahkefel 2013
// store.c
// stores a fish in the ships supply.
//   Allowing it to go fruther because: REASONS.
//   Mostly to give a use for fishing, and to allow sailors to be better
//   at something sailor related than enchanters.

#include <lib.h>
inherit LIB_VERB;

static void create() {
  ::create();
  SetVerb("store");
  SetRules("OBJ");
  SetErrorMessage("store what in the hold?");
  SetHelp("Syntax:    store <FISH>\n"
    "An experienced fisherman can attempt to resupply a ship at sea, \n"
    "feeding the crew with sharks and guppies and so on. \n"
    "Novice anglers are likely to store fish improperly and waste them. \n"
    "See also: help ships");
}

mixed can_store_obj(object fish) {
 object ship = environment(this_player());
 object who = this_player();

 if (!vehiclep(ship)) {
   return "But you are not in a ship!";
 }
 if (who->GetSleeping()) return "You dream of succulent shark.";
 if (who->GetParalyzed()) return "You cannot move!";
 if (who->GetStaminaPoints() < 50) return "You are too tired.";

 return 1;
}

mixed do_store_obj(object fish) {
  object who = this_player();
  object ship = environment(who);
  object target;
  object pilot;
  int pro, difficulty, cost, result, multiplier, stores;

  if (!environment(who)) {
    who->eventPrint("Something gone bad wrong.");
    return 1;
  }

  if(!environment(ship)) {
    who->eventPrint("Your ship seems to have abandoned you.");
    return 1;
  }

  if (!ship->GetVehicleSize()) {
    who->eventPrint("There's something wrong with this ship!");
    return 1;
  }

  if (ship->GetKeyName() == "dinghy") {
    who->eventPrint("There's no point storing something on a ship with this many holes in it.");
    return 1;
  }
  
  if (!fish) {
    who->eventPrint("That slippery fish got away somehow.");
    return 1;
  }

  if ( member_array("fish",fish->GetId()) == -1 ) {
    who->eventPrint("That's no fish!");
    return 1;
  }

  if (!fish->GetStrength()) {
    who->eventPrint("There's something funky with this fish.");
    return 1;
  }

  switch(who->GetSkillLevel("fishing")) {
    case 0..20:
      cost = 50;
      break;
    case 21..40:
      cost = 40;
      break;
    case 41..80:
      cost = 30;
      break;
    case 81..160:
      cost = 20;
      break;
    case 161..999:
      cost = 10;
      break;
    case 1000..10000:
      cost = 1;
      break;
    default:
      cost = 50;
      break;
    }

  switch(who->GetSkillLevel("fishing")) {
    case 0..25:
      multiplier = 1;
      break;
    case 26..50:
      multiplier = 2;
      break;
    case 51..200:
      multiplier = 4;
      break;
    case 201..500:
      multiplier = 6;
      break;
    case 501..750:
      multiplier = 8;
      break;
    default:
      multiplier = 10;
      break;
    }

// mahk: due to supply/launch changes, multiplying this # by 10
    multiplier *= 10;
    if (ship->GetCrystals()) {
      if(ship->GetCrystals() > 50000) {
        who->eventPrint("That's... probably enough fish for now.");
      }
    } else {
      who->eventPrint("There's something wrong with the hold of this ship!");
    }

    // needs variables.
    stores = multiplier * fish->GetStrength() / ship->GetVehicleSize();
    // eh, safety limits.
    if (stores < 1) stores = 1;
    if (stores > 200) stores = 200;

    difficulty = fish->GetStrength() * ship->GetSize();

    send_messages("drag",
      "$agent_name $agent_verb a " + fish->GetKeyName() + " across the deck.",
      who, target,  ship );

    who->AddStaminaPoints(-cost);

    result = who->eventCheckSkill("fishing", difficulty, 0, 100);

    // any success
    if (result > 0) {
      send_messages("stowe",
        "$agent_name $agent_verb a " + fish->GetKeyName() + " safely below decks.",
      who, target,  ship );
    // failure
    } else {
      send_messages("drop",
        "$agent_name $agent_verb a " + fish->GetKeyName() + " on the deck like "
        "an idiot and it slides overboard.",
      who, target,  ship );
      return 1;
    }

    ship->AddCrystals(stores);
    fish->eventDestruct();

    return 1;
}


