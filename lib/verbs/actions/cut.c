#include <lib.h>
#include <damage_types.h>
#include <vision.h>
inherit LIB_ACTION;

static void create() {
  ::create();
  SetVerb("cut");
  SetRules("LIV down", "down");
  SetHelp("Syntax: cut down, cut LIV down\n\n"
    "You hack with your blade at your opponent's legs, "
    "trying to cut them to the ground."
  );
  SetStaminaCost(300);
  SetCooldown(10);
  SetRequiredWeapon("slash");
  SetRequiredSkills( ([
    "slash combat" : 100,
    "sword slinging" : 100,
    ]) );
}

mixed can_cut_down() {
  if (!this_player()->GetInCombat()) { return "cut who down?"; }
  return CanAction(this_player());
}

mixed can_cut_liv_down() {
  return CanAction(this_player());
}

mixed do_cut_liv_down(object target) {
  return eventAction(this_player(), target);
}

mixed do_cut_down() {
  return do_cut_liv_down(this_player()->GetCurrentEnemy());
}

int eventAttack(object who, object target) {
  int result, damage;
  object weapon = GetAnyWeapon(who);
  string limb = target->GetRandomLimb("right leg"); //laaaazy

  if (!weapon) {
    debug("Dude cut without a weapon. this should not be possible.");
    who->eventPrint("You appear to be mysteriously unarmed!");
    return 0;
  }

  result = GetHit(who,target);

  send_messages( ({ "swing" }),
    "$agent_name%^BOLD%^YELLOW%^ $agent_verb%^RESET%^ $agent_possessive "
    + weapon->GetKeyName() + " low in a smooth arc.",
    who, target, environment(who));
  if (who->GetTestChar()) debug("cut result: " + result);
  if (result == -1) {
    send_messages( ({ "stomp" }), "$target_name quickly%^YELLOW%^ "
      "$target_verb%^RESET%^ on $agent_possessive_noun "
      + weapon->GetKeyName() + ", knocking it to the ground!",
      who, target, environment(who));

    weapon->eventUnequip(who);
    weapon->eventDrop(who);
    return 1;

  } else if (result == 0) {
    send_messages( ({ "hop" }),
      "$target_name%^YELLOW%^ $target_verb%^RESET%^ over "
      "the swinging blade!",
      who, target, environment(who));
    return 1;
  }

  if (who->GetTestChar()) debug("cut should be a success!");

  
  
  send_messages( ({"slice","collapse"}),
    "$agent_name%^BOLD%^YELLOW%^ $agent_verb%^RESET%^ deeply into "
    "$target_possessive_noun " + limb + ", and $target_nominative%^BOLD%^YELLOW%^ "
    "$target_verb%^RESET%^ from the pain!",
    who, target, environment(who) );
  if (who->GetTestChar()) debug("Past funky sendmessage!");

  damage = GetLowDamage(who, weapon);
  if (who->GetTestChar()) debug("cut damage: " + damage);
  damage = target->GetDamageInflicted(who, weapon->GetDamageType(), damage, 0, limb);
  if (who->GetTestChar()) debug("cut damage after GetDamageInflicted: " + damage);
  target->eventInflictDamage(who, weapon->GetDamageType(), damage, 0, limb);

  //if(!random(3)) {
  target->eventCollapse();
  //}

  if(target->GetDying()) {
    "/verbs/actions/obj/bloodlust"->eventRage(who);
  }
  return 1;
}

