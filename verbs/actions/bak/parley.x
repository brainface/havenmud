// mahkefel 2011
// swashbuckling combat action, allows user to 'calm' people in the room fighting them.
#include <lib.h>
#include <damage_types.h>
#include <vision.h>
inherit LIB_ACTION;

int eventAttack(object who, object* targets);
int eventAction(object who, object* target);

static void create() {
  ::create();
  SetVerb("parley");
  SetRules("with LIV", "");
  SetHelp("Syntax: parley, parley with LIV\n\n"
    "You attempt to invoke parley, halting combat with your opponents.");
  SetStaminaCost(100);
  SetRequiredWeapon("none"); // might break stuff, makes help look right.
  SetRequiredSkills( ([
    "swashbuckling" : 25,
  ]) );
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


// overridden so that dudes don't always attack because you parley with them.
int eventAction(object who, object* targets) {
  if(who->GetTestChar()) debug ("event action");
  eventAttack(who,targets);
  who->AddStaminaPoints(-StaminaCost);
  return 1;
}

mixed can_parley() {
  debug("can parley");
  if (!this_player()->GetInCombat()) { return "But you fight no one!"; }
  return CanAction(this_player());
}

mixed can_parley_with_liv() {
  debug ("can parley liv");
  return CanAction(this_player());
}

mixed do_parley_with_liv(object target) {
  debug ("do parley liv");
  return eventAction(this_player(), ({target}) );
}

mixed do_parley() {
  debug ("do parley");
  return eventAction(this_player(), this_player()->GetEnemies() );
}

int eventAttack(object who, object* targets) {
  int result;

  debug("eventAttack");
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
  if (!sizeof(targets)) {
    who->eventPrint("But you fight no one!");
    return 0;
  }
 if(who->GetTestChar()) debug ("invoke message");
  send_messages( ({ "invoke" }),
    "$agent_name%^CYAN%^ $agent_verb%^RESET%^ the ancient rite of parley!",
    who, 0, environment(who));

  foreach (object target in targets) {
    int pro, con;

    if (target->GetStatLevel("intelligence") < 20) {
      send_messages("are","$target_name $target_verb too uncivilized to recognize "
        "parley!", who, target, environment(who) );
    } else if (target->GetClass()=="animal" ) {
      send_messages("are", "$target_name $target_verb a brute beast, and parley "
        "has no meaning for $target_objective", who, target, environment(who) );
    } else {

      pro = who->SetStatLevel("luck")/2;
      pro += who->GetStatLevel("charisma")/2;

      con += target->GetSkillLevel("combat rage");
      con += target->GetStatLevel("wisdom")/2;
      con += target->GetStatLevel("luck")/2;

      // difficulty approaches 0 as target is wounded. difficulty approaches 2* as user is wounded.
      con *= target->GetHealthPoints() / target->GetMaxHealthPoints()
        + ( who->GetMaxHealthPoints() - who->GetHealthPoints() ) / who->GetMaxHealthPoints() ;

      result = who->eventCheckSkill("swashbuckling", con, pro, 100);

      if (result > 0 ) {
        send_messages( ({"halt"}), "$agent_name%^BOLD%^CYAN%^ $agent_verb%^RESET%^ $agent_possessive assault to "
          "consider $target_possessive_noun offer of parley.", target, who, environment(who) );
        target->RemoveEnemy(who);
        who->RemoveEnemy(target);
        target->ResetCurrentEnemy();
        target->ResetCurrentEnemy(); // have it twice in some other file, copying that.
      } else {
        send_messages( ({"laugh"}), "$target_name%^CYAN%^ $target_verb%^CYAN%^ scornfully at $agent_possessive_noun "
          "plea for mercy!", who, target, environment(who) );
      }
    }
  }
  who->AddParalyzed(2); // prevent spamming, in certain cases it could lead to weird large 
                        // xp gains due to skill check. (certain cases = Bjorn)
  return 1;
}

