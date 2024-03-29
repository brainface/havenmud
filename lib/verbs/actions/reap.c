#include <lib.h>
#include <damage_types.h>
#include <vision.h>
inherit LIB_ACTION;

static void create() {
  ::create();
  SetVerb("reap");
  SetRules("LIV", "");
  SetHelp("Syntax: reap, reap LIV\n\n"
    "All pretense of honor aside, you hack at a defenseless foe, "
    "ending them with one strike. If successful, your murderous "
    "attack invigorates you. This attack is much less effective "
    "against a struggling foe."
  );
  SetStaminaCost(100);
  SetRequiredWeapon("slash");
  SetRequiredSkills( ([
    "slash combat" : 150,
    "sword slinging" : 150,
    ]) );
}

mixed can_reap() {
  if (!this_player()->GetInCombat()) { return "reap who?"; }
  return CanAction(this_player());
}

mixed can_reap_liv() {
  return CanAction(this_player());
}

mixed do_reap_liv(object target) {
  return eventAction(this_player(), target);
}

mixed do_reap() {
  if (!this_player()->GetCurrentEnemy()) {
    this_player()->eventPrint("But you fight no one!");
    return 0;
  }
  return do_reap_liv(this_player()->GetCurrentEnemy());
}

int eventAttack(object who, object target) {
  int result, damage;
  object weapon = GetAnyWeapon(who);
  string limb = target->GetRandomLimb("head"); //laaaazy

  if (!weapon) {
    debug("Dude reap without a weapon. this should not be possible.");
    who->eventPrint("You appear to be mysteriously unarmed!");
    return 0;
  }

  result = GetHit(who,target);

  send_messages( ({ "raise" }),
    "$agent_name%^BOLD%^YELLOW%^ $agent_verb%^RESET%^ $agent_possessive "
    + weapon->GetKeyName() + " high above $agent_possessive head.",
    who, target, environment(who));
  if (who->GetTestChar()) debug("reap result: " + result);
  if (result == -1) {
    send_messages( ({ "stumble" }), "$target_name reflexively%^YELLOW%^ "
      "$target_verb%^RESET%^ out of the path of the blow!",
      who, target, environment(who));
    return 1;

  } else if (result == 0) {
    send_messages( ({ "flinch" }),
      "$target_name%^YELLOW%^ $target_verb%^RESET%^ fearfully "
      "from the scything blade!",
      who, target, environment(who));
    return 1;
  }

  if (who->GetTestChar()) debug("reap should be a success!");

  send_messages( ({"scythe"}),
    "$agent_name%^BOLD%^YELLOW%^ $agent_verb%^RESET%^ $agent_possessive " +
    weapon->GetKeyName() + " murderously into $target_possessive_noun defenseless form!",
    who, target, environment(who) );
  if (who->GetTestChar()) debug("Past funky sendmessage!");

  if (!target->GetParalyzed() && !target->GetBlind()) {
    damage = GetHighDamage(who, weapon);
  } else {
    damage = GetLowDamage(who, weapon)/3;    
  }

  if (who->GetTestChar()) debug("reap damage: " + damage);
  damage = target->GetDamageInflicted(who, weapon->GetDamageType(), damage, 0, limb);
  if (who->GetTestChar()) debug("reap damage after GetDamageInflicted: " + damage);
  target->eventInflictDamage(who, weapon->GetDamageType(), damage, 0, limb);

  if(target->GetDying()) {
    "/verbs/actions/obj/bloodlust"->eventRage(who);
    who->AddStaminaPoints(target->GetLevel() * 3); // slightly weaker than spirit call.
    send_messages( ({"invigorate"}),
      "The bloody carnage %^BOLD%^YELLOW%^invigorates%^RESET%^ $agent_name!",
    who, target, environment(who) ); 
  } else {
    send_messages( ({"overextend"}),
      "$agent_name%^BOLD%^YELLOW%^ $agent_verb%^RESET%^ $agent_reflexive with "
      "the wild blow, leaving $agent_objective open to attack!",
    who, target, environment(who) ); 
    who->AddParalyzed(random(2)+1);
  }
  return 1;
}

