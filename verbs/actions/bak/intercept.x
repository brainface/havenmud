#include <lib.h>
#include <damage_types.h>
#include <armour_types.h>
#include <vision.h>
inherit LIB_ACTION;

static void create() {
  ::create();
  SetVerb("intercept");
  SetRules("LIV", "");
  SetHelp("Not content to cower behind a gilded shield, a novice "
    "swashinterceptr can bash at his opponents weapon, attempting to "
    "shatter it. It is obviously difficult to perform this manuever "
    "without holding a shield in one of your hands.");
  SetStaminaCost(100);
  SetRequiredWeapon("shield"); //shield is not a weapon type. things should be overridden so this doesn't tgo fubar
  SetRequiredSkills( ([
    "sword slinging" : 50,
    ]) );
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


mixed can_intercept() {
  if (!this_player()->GetInCombat()) { return "intercept who?"; }
  return CanAction(this_player());
}

mixed can_intercept_liv() {
  return CanAction(this_player());
}

mixed do_intercept_liv(object target) {
  if (target->GetCurrentEnemy() == this_player()) {
    this_player()->eventPrint("You already have " +
      possessive(target->GetKeyName()) + " full attention!");
    return 0;
  }
  return eventAction(this_player(), target);
}

mixed do_intercept() {
  return do_intercept_liv(this_player()->GetCurrentEnemy());
}

int eventAttack(object who, object target) {
  int result, damage;
  object weapon,intercepter;
  object *pretties;
  if (who->GetTestChar()) debug("buckling");

  weapon = target->GetWielded( random(sizeof(target->GetWielded())) );
  if (who->GetTestChar()) debug("looping thru inventory for shield");
  pretties = who->GetWorn();

  // this check really should be in can_act or do_act, but that's hard and I'm lazy.
  foreach (object *limb in pretties) {
    foreach (object pretty in limb) {
      if (pretty->GetArmourType() == A_SHIELD) {
        if (pretty->GetWorn()[0]!="left arm" && pretty->GetWorn()[0]!="right arm") {
          intercepter = pretty;
        }
      }
    }
  }

  if (!intercepter) {
    if (who->GetTestChar()) debug("ain't no shield");
    who->eventPrint("You must have a shield in hand to do this!");
    send_messages( ({ "lurch","seem" }), "$agent_name%^YELLOW%^ $agent_verb%^RESET%^ "
      "menacingly towards $target_name, but $agent_verb to have forgotten something!",
      who, target, environment(who));
    return 0;
  }

  result = GetHit(who,target);

  if (who->GetTestChar()) debug("thrust sendmessage");
  send_messages( ({ "rush" }),
    "$agent_name%^BOLD%^YELLOW%^ $agent_verb%^RESET%^ between $target_name and "
      + target->GetCurrentEnemy()->GetKeyName() + "!",
    who, target, environment(who));

  if (result == -1) {
    if (who->GetTestChar()) debug("fumble sendmessage");
    send_messages( ({ "brace" }), "$target_name $target_verb for the charge, and"
      "%^YELLOW%^ $agent_verb%^RESET%^ into $agent_possessive_noun " + 
      intercepter->GetKeyName() + "!",
      who, target, environment(who));
    intercepter->eventDrop();
    return 1;
  }
  if (result = 0) {
  if (who->GetTestChar()) debug("miss sendmessage");
    send_messages( ({ "dance" }),
      "$target_name %^YELLOW%^$agent_verb%^RESET%^ out of the way of $agent_possessive_noun "
      "assault!",
      who, target, environment(who));
    return 1;
  }

  if (who->GetTestChar()) debug("hit sendmessage");
  // blow has landed
  send_messages("slam",
    "$agent_name%^BOLD%^YELLOW%^ $agent_verb%^RESET%^ violently into $target_name with "
    "$agent_possessive "+intercepter->GetKeyName()+"!",
    who, target, environment(who) );
  if(!random(4)){
    target->eventCollapse();
    "/verbs/actions/obj/bloodlust"->eventRage(who);
  }
  target->SetCurrentEnemy(who);
  return 1;
}

