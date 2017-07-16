// mahkefel 2011
// berserking combat action
//   exchanges health for stamina
#include <lib.h>
#include <damage_types.h>
#include <rounds.h>
#include <vision.h>
#include <position.h>
inherit LIB_ACTION;

int eventJolt(object who);
int eventAction(object who);

static void create() {
  ::create();
  SetVerb("jolt");
  SetRules("LIV","");
  SetHelp("Fearing calamity, an old hand can jolt awake at a moment's "
    "notice, so long as they're not in deepest sleep."
  );
  SetStaminaCost(50);
  SetRequiredWeapon("none");
  SetRequiredSkills( ([
    "dirty tricks" : 300,
  ]) );

}

// overridden for area effect
int eventAction(object who) {
  if(who->GetTestChar()) debug ("event action");
  eventJolt(who);
  return 1;
}

// overriding this to not require a weapon.
mixed CanAction(object who) {
  if (who->GetStaminaPoints() < StaminaCost*2) {
    return "You are too tired.";
  }
  if (who->GetParalyzed()) {
    return "You are paralyzed.";
  }
  if (!who->GetSleeping()) {
    return "You are already awake!";
  }
  foreach(string s in keys(RequiredSkills)) {
    if (who->GetSkillLevel(s) < RequiredSkills[s]) {
      return "You are not proficient enough in " + s + " to perform that action.";
    }
  }
  return 1;
}


mixed can_jolt() {
  //if (!this_player()->GetInCombat()) { return "You fight no one, and have little to be upset about!"; }
  return CanAction(this_player());
}

mixed do_jolt() {
  return eventAction(this_player());
}


int eventJolt(object who) {
  int result;
  int healthCost,staminaGain;

  if(who->GetTestChar()) debug ("invoke message");

  who->SetSleeping(0);
  who->SetPosition(POSITION_STANDING);  
  
  send_messages( ({ "jolt","spring" }),
    "$agent_name%^BLACK%^BOLD%^ $agent_verb%^RESET%^ awake "
    "and%^BLACK%^BOLD%^ $agent_verb%^RESET%^ to $agent_possessive "
    "feet, ready for a fight!",
    who, 0, environment(who)); 

  return 1;
}

