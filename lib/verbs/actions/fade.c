// mahkefel 2011
// dirty fighting combat action, allows user to vanish and leave combat.

#include <lib.h>
#include <damage_types.h>
#include <vision.h>
inherit LIB_ACTION;

int eventAttack(object who, object* targets);
int eventAction(object who, object* target);

static void create() {
  ::create();
  SetVerb("fade");
  SetRules("");
  SetHelp("Sensing a fair fight, you attempt to fade into the shadows "
    "in preperation for a hasty retreat.");
  SetStaminaCost(100);
  SetRequiredWeapon("none"); // might break stuff, makes help look right.
  SetRequiredSkills( ([
    "dirty tricks" : 100,
    "stealth" : 100,
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

// overridden so that dudes don't always attack because you fade with them.
int eventAction(object who, object* targets) {
  if(who->GetTestChar()) debug ("event action");
  eventAttack(who,targets);
  who->AddStaminaPoints(-StaminaCost);
  return 1;
}

mixed can_fade() {
  if (!this_player()->GetInCombat()) { return "But you fight no one!"; }
  return CanAction(this_player());
}

mixed can_fade_liv() {
  return CanAction(this_player());
}

mixed do_fade_liv(object target) {
  return eventAction(this_player(), ({target}) );
}

mixed do_fade() {
  return eventAction(this_player(), this_player()->GetEnemies() );
}

int eventAttack(object who, object* targets) {
  int result;

  // try to make sure targets are actually in the room
  foreach (object target in targets) {
    if (environment(target) != environment(who) ) {
      if(who->GetTestChar()) debug ("enemy not in room");
      targets -= ({target});
    }
    if (member_array(who,target->GetEnemies()) == -1) {
      if(who->GetTestChar()) debug ("target is not an enemey");
      targets -= ({target});
    }
  }

 if(who->GetTestChar()) debug ("invoke message");
  send_messages("fade","$agent_name%^BOLD%^BLACK%^ $agent_verb "
    "%^RESET%^into the shadows",
    who, 0, environment());

  foreach (object target in targets) {
    int pro, con;
    pro = who->GetSkillLevel("dirty tricks")/4;
    pro = who->SetStatLevel("agility")/2;
    pro = who->SetStatLevel("luck")/2;

    con = target->GetSkillLevel("accuracy");
    con += target->GetStatLevel("wisdom")/2;
    con += target->GetStatLevel("luck")/2;

    result = who->eventCheckSkill("stealth", con, pro, 100);

    if (result > 0 ) {
      send_messages( ({"blink"}), "$agent_name%^BOLD%^BLACK%^ "
        "$agent_verb%^RESET%^ in confusion "
        "as $agent_nominative loses sight of $target_name!",
        target, who, environment(who) );
      target->RemoveEnemy(who);
      who->RemoveEnemy(target);

      target->ResetCurrentEnemy();
      target->ResetCurrentEnemy(); // have it twice in some other file, copying that.
    } else {
      send_messages( ({"spy","continue"}), "$target_name%^BOLD%^ $target_verb%^RESET%^ "
        "$agent_possessive stealthy retreat and continues $target_possessive assault!",
        who, target, environment(who) );
    }
  }
  who->SetHiding(1); //actually go invisible.
  return 1;
}

