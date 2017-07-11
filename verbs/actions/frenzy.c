// mahkefel 2011
// berserking combat action
//   exchanges health for stamina
#include <lib.h>
#include <damage_types.h>
#include <rounds.h>
#include <vision.h>
inherit LIB_ACTION;

int eventFrenzy(object who);
int eventAction(object who);

static void create() {
  ::create();
  SetVerb("frenzy");
  SetRules("LIV","");
  SetHelp("You work yourself into a frenzy, giving yourself additional "
    "stamina to continue the fight at an expense of living a healthy life."
  );
  SetStaminaCost(0);
  SetRequiredWeapon("none");
  SetRequiredSkills( ([
    "berserking" : 50,
  ]) );

}

// overridden for area effect
int eventAction(object who) {
  if(who->GetTestChar()) debug ("event action");
  eventFrenzy(who);
  return 1;
}

// overriding this to not require a weapon.
mixed CanAction(object who) {
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


mixed can_frenzy() {
  //if (!this_player()->GetInCombat()) { return "You fight no one, and have little to be upset about!"; }
  return CanAction(this_player());
}

mixed do_frenzy() {
  return eventAction(this_player());
}


int eventFrenzy(object who) {
  int result;
  int healthCost,staminaGain;

  if(who->GetTestChar()) debug ("invoke message");
  if (who->GetHealthPoints() < 250) {
    who->eventPrint("Some remaining thread of self-preservation prevents you from travelling further into rage!");
    return 0;
  }

  if (who->GetStaminaPoints() >= who->GetMaxStaminaPoints()) {
    who->eventPrint("Mad as you are, you are nontheless fully invigorated.");
    return 0;
  }

  send_messages( ({ "bleed","work" }),
    "$agent_name%^RED%^BOLD%^ $agent_verb%^RESET%^ from $agent_possessive "
    "eyes and mouth as $agent_possessive $agent_verb $agent_reflexive "
    "into a state of frenzy!",
    who, 0, environment(who));

  who->AddHealthPoints(-200);
  who->AddStaminaPoints(150);
 "/verbs/actions/obj/rage"->eventRage(who);
  return 1;
}

