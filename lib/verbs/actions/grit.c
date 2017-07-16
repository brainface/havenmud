// mahkefel 2011
// swashbuckling combat action
//   cures poison, gives stamina->health (75% ratio)
#include <lib.h>
#include <damage_types.h>
#include <rounds.h>
#include <vision.h>
inherit LIB_ACTION;

int eventGrit(object who);
int eventAction(object who);

static void create() {
  ::create();
  SetVerb("grit");
  SetRules("");
  SetHelp(
    "You're no mere sellsword, to idly succumb to a few wounds or "
    "a poisoned arrow. When wounded, you can force yourself to continue "
    "on through sheer force of will."
  );
  SetStaminaCost(200);
  SetRequiredWeapon("none");
  SetRequiredSkills( ([
    "sword slinging" : 100,
  ]) );

}

// overridden for area effect
int eventAction(object who) {
  if( who->GetProperty("action_debug") ) debug ("event action");
  eventGrit(who);
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


mixed can_grit() {
  if(this_player()->GetHealthPoints() > this_player()->GetMaxHealthPoints() * 3 / 4) {
    return "Your injuries are minor, and you have no need to push yourself!";
  }
  return CanAction(this_player());
}

mixed do_grit() {
  return eventAction(this_player());
}

int eventGrit(object who) {
  int result;
  int healthCost,staminaGain;
  string fightOrWalk = "fight";
  string painOrPoison = "pain";

  if( !who->GetInCombat() ) fightOrWalk = "walk";

  if( who->GetProperty("action_debug") ) debug ("invoke message");

  if (who->GetPoison()) {
    who->AddPoison(-who->GetSkillLevel("sword slinging")/20);
    painOrPoison = "poison burning through $agent_possessive veins";
  }

  send_messages( ({ "grit","continue" }),
    "$agent_name%^YELLOW%^BOLD%^ $agent_verb%^RESET%^ $agent_possessive teeth and "
    "$agent_verb to "+fightOrWalk+" on despite the "+painOrPoison+"!",
    who, 0, environment(who));

  who->AddStaminaPoints(-200);
  who->AddHealthPoints(150);
  who->eventDisplayStatus();

  return 1;
}

