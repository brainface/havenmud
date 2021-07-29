// mahkefel 10 2011
// vampire bite!
#include <lib.h>
#include <damage_types.h>
#include <vision.h>
#include <conditions.h>
inherit LIB_ACTION;

static void create() {
  ::create();
  SetVerb("chomp");
  SetRules("LIV", "");
  SetHelp("You attempt to bite your foe and drink delicious bloodjuice "
    "from them. This is even more effective against bleeding foes, and "
"tends to cause bloodloss anyway due to the entire vampire business.");
  SetStaminaCost(50);
  SetRequiredWeapon("none");
  SetRequiredSkills( ([
    "vampirism" : 1,
    "melee combat" : 1,
    ]) );
  //SetCooldown(10);
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
  /*if (who->GetCooldown(GetVerb())) {
    return "You need a moment to work up some more spit.";
    }*/
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

mixed can_chomp() {
  if (!this_player()->GetInCombat()) { return "chomp who?"; }
  return CanAction(this_player());
}

mixed can_chomp_liv() {
  return CanAction(this_player());
}

mixed do_chomp_liv(object target) {
  return eventAction(this_player(), target);
}

mixed do_chomp() {
  return do_chomp_liv(this_player()->GetCurrentEnemy());
}

int eventAttack(object who, object target) {
  int result, damage;
  int blood;
  string limb = target->GetRandomLimb();
  object weapon = GetAnyWeapon(who);

  result = GetHit(who,target);

  send_messages( ({ "smile" }),
    "$agent_name%^RED%^ $agent_verb%^RESET%^ "
    "widely at $target_name, exposing fangs!",
    who, target, environment(who));
  if (result == -1) {
    send_messages( ({ "manage" }), "$agent_name somehow $agent_verb to%^BOLD%^ bite"
      "%^RESET%^ $agent_possessive tongue instead of $target_name!",
      who, target, environment(who));
    //who->eventCollapse();
    return 1;
  }
  if (result = 0) {
    send_messages( ({ "leap", "chomp" }), "$agent_possessive_noun teeth%^RED%^ snap%^RESET%^ "
  "together a hair's breadth from $target_possessive_noun body!",
      who, target, environment(who));
    return 1;
  }

  // blow has landed
    send_messages( ({ "leap", "chomp" }), "$agent_name%^BOLD%^RED%^ $agent_verb%^RESET%^ "
      "fang-first at $target_name and $agent_verb down into $target_possessive_noun " + limb +"!",
      who, target, environment(who));

  damage = GetLowDamage(who, weapon);
  if (who->GetTestChar()) debug("chomp damage: " + damage);
  damage = target->GetDamageInflicted(who, PIERCE, damage, 0, limb);
  if (who->GetTestChar())
    debug("chomp damage after GetDamageInflicted: " + damage);
  target->eventInflictDamage(who, PIERCE, damage, 0, limb);

  if (target->GetBleeding()) {
blood = target->GetBleeding();
    send_messages( ({ "slurp" }), "$agent_name noisily%^BOLD%^%^RED%^ $agent_verb%^RESET%^ "
  "up some blood.",
      who, target, environment(who));
who->AddDrink(blood*10);
who->AddFood(blood*10);
  }

  //BLEEEED for me.
  if (!target->GetBleeding()) {
    target->AddBleeding(random(who->GetStatLevel("durability")/60)+1, who);
    target->eventDisplayStatus(); // so they know they're bleeding
  }
  return 1;
}

