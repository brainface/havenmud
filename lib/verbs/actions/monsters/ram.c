#include <lib.h>
#include <damage_types.h>
#include <vision.h>
inherit LIB_ACTION;

static void create() {
  ::create();
  SetVerb("ram");
  SetRules("");
  SetHelp("Syntax: ram\n\n"
    "A big or goatlike creature rams their opponent. "
    "Only animals may do this, and only against their "
    "current opponent.\n"
  );
  SetStaminaCost(50);
  SetRequiredWeapon("melee");
  SetRequiredSkills( ([
    "melee combat" : 1,
    ]) );
}

mixed can_ram() {
  if ( !this_player()->GetInCombat()        ) return "You aren't fighting anyone!";
  if ( this_player()->GetClass() != "animal") return "You are not a goat!";
  return CanAction(this_player());
}

mixed do_ram() {
  return eventAction(this_player(), this_player()->GetCurrentEnemy());
}

int eventAttack(object who, object target) {
  int result, damage;
  object weapon = GetAnyWeapon(who);
  string limb = target->GetRandomLimb("right leg"); //laaaazy
  int damageType = 0;

  if (!weapon) {
    debug("Ram without a weapon, some bug in the code of " +
      who->GetKeyName() + " (unarmed should count as weaponized "
      "in this instance)" );
    return 0;
  }
  result = GetHit(who,target);

  send_messages( ({ "charge" }),
    "$agent_name%^BOLD%^GREEN%^ $agent_verb%^RESET%^ at $target_name!",
    who, target, environment(who));
  if (who->GetTestChar()) debug("cut result: " + result);
  if (result == -1 || result == 0) {
    send_messages( ({ "leap" }), "$target_name quickly%^GREEN%^ "
      "$target_verb%^RESET%^ out of the way!",
      who, target, environment(who));
    return 1;
  }

  if (who->GetTestChar()) debug("cut should be a success!");

  send_messages( "ram",
    "$agent_name%^BOLD%^GREEN%^ $agent_verb%^RESET%^ violently into "
    "$target_possessive_noun " + limb + "!", who, target, environment(who) );
  if (who->GetTestChar()) debug("Past funky sendmessage!");

  if (!damageType = weapon->GetDamageType()) {
    damageType = who->GetMeleeDamageType();
  }

  damage = GetLowDamage(who, weapon) / 2; // I really, really need to balance damage.
  if (who->GetTestChar()) debug("cut damage: " + damage);
  damage = target->GetDamageInflicted(who, damageType, damage, 0, limb);
  if (who->GetTestChar()) debug("cut damage after GetDamageInflicted: " + damage);
  target->eventInflictDamage(who, damageType, damage, 0, limb);

  if(!random(5)) {
    target->eventCollapse();
  }

  return 1;
}

