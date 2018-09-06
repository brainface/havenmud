// mahkefel 2011
// Dust, a dirty fighting combat action

// Invisible dude, meet bag of flour, bag of flour, invisible dude.
// success and invis is removed.
// On a fail, this will still reveal that "a shadow" is in the room.

#include <lib.h>
#include <damage_types.h>
#include <vision.h>
inherit LIB_ACTION;

int eventAttack(object who, object* targets);
int eventAction(object who, object* target);

static void create() {
  ::create();
  SetVerb("dust");
  SetRules("");
  SetHelp("Enchanters complacent in their magic can sometimes be foiled by "
    "the simplest of means. Many skulks and assassins carry a small bit of "
    "flour or ash around with them, so they can reveal anyone relying upon "
    "arcane methods of stealth.");
  SetStaminaCost(70);
  SetRequiredWeapon("none"); // might break stuff, makes help look right.
  SetRequiredSkills( ([
    "dirty tricks" : 50,
  ]) );
    SetCooldown(5);
}

// overriding this to not require a weapon.
mixed CanAction(object who) {
  if(who->GetTestChar()) debug ("can action");
  if (who->GetStaminaPoints() < StaminaCost) {
    return "You are too tired.";
  }
  if (who->GetParalyzed()) {
    return "You are paralyzed.";
  }
  if (who->GetSleeping()) {
    return "You are asleep.";
  }
  foreach(string s in keys(RequiredSkills)) {
    if (who->GetSkillLevel(s) < RequiredSkills[s]) {
      return "You are not proficient enough in " + s + " to perform that action.";
    }

  }
  return 1;
}

// overridden so that dudes don't always attack because you dust with them.
int eventAction(object who, object* targets) {
  if(who->GetTestChar()) debug ("event action");
  eventAttack(who,targets);
  who->AddStaminaPoints(-StaminaCost);
  return 1;
}

mixed can_dust() {
 // debug("can dust");
  //if (!this_player()->GetInCombat()) { return "But you fight no one!"; }
  return CanAction(this_player());
}

mixed do_dust() {
  object* hidden_people = ({ });
  object room;

  if (!environment(this_player())) {
    debug("dude trying to dust is no where: "+this_player()->GetKeyName());
    return 0;
  }
  room = environment(this_player());
  foreach (object person in all_inventory(room) ) {
    if (person->is_living()) {
      if(person->GetInvis() == 1) {
        hidden_people += ({ person });
      }
    }
  }
 // debug ("do dust");
  return eventAction(this_player(), hidden_people );
}

int eventAttack(object who, object* targets) {
  int result;

 // debug("eventAttack");

  if(who->GetTestChar()) debug ("invoke message");
  send_messages("toss","$agent_name%^BOLD%^BLACK%^ $agent_verb "
    "%^RESET%^a handful of fine white powder into the air around "
    "$agent_objective.",
    who, 0, environment());

  if (!sizeof(targets)) {
    send_messages("","The dust %^BOLD%^floats%^RESET%^ to the "
      "ground, coating everything in a thin layer of white flour.",
      who, 0, environment());
    who->AddParalyzed(2);
    return 0;
  }

  foreach (object target in targets) {
    int pro, con;

    pro = who->GetSkillLevel("dirty tricks")/4;
    pro = who->SetStatLevel("wisdom")/2;
    pro = who->SetStatLevel("luck")/2;

    con += target->GetSkillLevel("dodge")/2;
    con += target->GetSkillLevel("stealth")/2;
    con += target->GetStatLevel("agility")/2;
    con += target->GetStatLevel("luck")/2;

    result = who->eventCheckSkill("dirty tricks", con, pro, 100);

    if (result > 0 ) {
      send_messages( ({"verb"}), "The dust%^BOLD%^BLACK%^ "
        "settles%^RESET%^ around the faint form of $target_name.",
        who, target, environment(who) );
      target->SetInvis(0);
    } else {
      // can't find a messaging functnio that works right and doesn't reveal
      //   name.
      who->eventPrint("A shadow quietly%^BOLD%^ "
        "scitters%^RESET%^ away from the fine cloud of dust. It's unlikely "
        "anyone else heard.");
      target->eventPrint("You make a small noise as you stealthily move away "
        "from the cloud of dust.");
    }
  }
  return 1;
}

