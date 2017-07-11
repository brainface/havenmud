#include <lib.h>
#include <damage_types.h>
#include <armour_types.h>
#include <vision.h>
#include <std.h>
#include <conditions.h>
inherit LIB_ACTION;

static void create() {
  ::create();
  SetVerb("hock");
  SetRules("on LIV", "");
  SetHelp("Syntax: hock, hock on LIV\n\n"
    "Calling upon the ancient and secret lost arts of "
    "... No, seriously, you just spit in someone's eye.");
  SetStaminaCost(45);
  SetRequiredWeapon("none"); //override to require nothing.
  SetRequiredSkills( ([
    "dirty tricks" : 25,
    ]) );
  SetCooldown(5);
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
  if (who->GetConditionFlag(CONDITION_PREVENT_TALK)) {
    return "Something's wrong with your throat."; 
  }
  if (who->GetConditionFlag(CONDITION_PREVENT_COMBAT)) {
    return "You can't work up the will to fight."; 
  }
  foreach(string s in keys(RequiredSkills)) {
    if (who->GetSkillLevel(s) < RequiredSkills[s]) {
      return "You are not proficient enough in " + s + " to perform that action.";
    }
  }

  return 1;
}

mixed can_hock() {
  if (!this_player()->GetInCombat()) { return "hock who?"; }
  return CanAction(this_player());
}

mixed can_hock_on_liv() {
  return CanAction(this_player());
}

mixed do_hock_on_liv(object target) {
  return eventAction(this_player(), target);
}

mixed do_hock() {
  return do_hock_on_liv(this_player()->GetCurrentEnemy());
}

int eventAttack(object who, object target) {
  int result, duration, pro, con;

  if (who->GetTestChar()) debug("hockting!");

  pro = who->SetStatLevel("luck")/2;
  pro += who->GetStatLevel("coordination")/2;

  con += target->GetSkillLevel("dodge");
  con += target->GetStatLevel("agility")/2;
  con += target->GetStatLevel("luck")/2;

  result = who->eventCheckSkill("dirty tricks", con, pro, 100);

  if (who->GetTestChar()) debug("thrust sendmessage");
  send_messages( ({ "hock","wink" }),
    "$agent_name%^BOLD%^BLACK%^ $agent_verb%^RESET%^ disgustingly and $agent_verb "
    "at $target_name.",
    who, target, environment(who));

  if (result > 0 ) {
    send_messages( ({ "spew" }),
      "$agent_name%^BOLD%^BLACK%^ $agent_verb%^RESET%^ a nasty stream of spittle which "
      "strikes $target_name squarely in the eye!",
      who, target, environment(who));
    duration = 10 + who->GetSkillLevel("dirty tricks") /25;
    if(duration > 20) duration = 20;
    if (who->getTestChar()) debug("hock blind duration: " + duration);
    target->eventBlind(duration);
  "/verbs/actions/obj/moxie"->eventRage(who);

    //LOL
    if ( random(target->GetStatLevel("durability")) < 20 ) {
      if (who->getTestChar()) debug("some sunovabitch just got pink-eye");
      STD_GERMS "pink_eye"->eventInfect(target);
    }
  } else {
    send_messages( ({ "spit" }), "$agent_name%^BOLD%^ $agent_verb%^RESET%^ "
      "against the wind, "
      "and a horrible loogie strikes $agent_objective in the face.",
      who, target, environment(who));
    who->eventBlind(3);
  }

  return 1;
}

