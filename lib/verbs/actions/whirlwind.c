// mahkefel 2011
// swordlinging combat action, just an area effect. lowish damage,
// mid-level. Adds bloodlust on kill.
#include <lib.h>
#include <damage_types.h>
#include <rounds.h>
#include <vision.h>
inherit LIB_ACTION;

int eventAttack(object who, object* targets);
int eventAction(object who, object* target);

static void create() {
  ::create();
  SetVerb("whirlwind");
  SetRules("LIV","");
  SetHelp("You slash around with your blade at all enemies, trying "
    "to cut down all around you in an exhausting manuever."
  );
  SetStaminaCost(150);
  SetRequiredWeapon("slash");
  SetRequiredSkills( ([
    "sword slinging" : 300,
    "slash combat" : 300,
  ]) );

}

// overridden for area effect
int eventAction(object who, object* targets) {
  if(who->GetTestChar()) debug ("event action");
  who->SetAttack(targets, (: eventAttack, who, targets :), ROUND_OTHER);
  who->AddStaminaPoints(-StaminaCost);
  return 1;
}

mixed can_whirlwind() {
  if (!this_player()->GetInCombat()) { return "But you fight no one!"; }
  return CanAction(this_player());
}

mixed can_whirlwind_liv() {
  return CanAction(this_player());
}

mixed do_whirlwind_liv(object target) {
  return eventAction(this_player(), ({target}) );
}

mixed do_whirlwind() {
  return eventAction(this_player(), this_player()->GetEnemies() );
}


int eventAttack(object who, object* targets) {
  int result, damage;
  string limb;

  // stupid temporary stuff to make one message work right.
  int weapons = sizeof( GetWeapons(who) );
  string word = "blade";

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

  if (weapons > 1) word = "blades";
  send_messages( ({ "burst" }),
    "$agent_name%^YELLOW%^BOLD%^ $agent_verb%^RESET%^ intro a whirlwind of motion!",
    who, 0, environment(who));

  foreach (object target in targets) {
    object weapon = GetAnyWeapon(who);
    result = GetHit(who,target);
    if (who->GetTestChar()) debug("whirlwind result: " + result);
    //FUMBLE!
    if (result == -1) {
      send_messages( ({ "misjudge","strike" }), "$agent_name%^YELLOW%^ "
        "$agent_verb%^RESET%^ $target_possessive_noun movements, and $agent_verb "
        "at empty air!",
        who, target, environment(who));
    // normal miss
    } else if (result == 0) {
      send_messages( ({ "trim" }),
      "$agent_name%^YELLOW%^ $agent_verb%^RESET%^ a bit of unneeded hair from "
      "from $target_possessive_noun head!",
      who, target, environment(who));
    // hit
    } else {
      if (!weapon) {
        who->eventPrint("You appear to be mysteriously unarmed!");
        return 0;
      }

      limb = target->GetRandomLimb();
      send_messages( ({"cut"}),
        "$agent_name%^BOLD%^%^YELLOW%^ $agent_verb%^RESET%^ a deep gash into "
        "$target_possessive_noun " + limb + " with a quick slice of $agent_possessive "+
        weapon->GetKeyName() + "!",
        who, target, environment(who) );
      damage = GetLowDamage(who, weapon);
      if (who->GetTestChar()) debug("whirlwind damage: " + damage);
      damage = target->GetDamageInflicted(who, weapon->GetDamageType(), damage, 0, limb);
      if (who->GetTestChar()) debug("whirlwind damage after GetDamageInflicted: " + damage);
      target->eventInflictDamage(who, weapon->GetDamageType(), damage, 0, limb);

      if(target->GetDying()) {
        //He like columbus, he get murderous on purpose.
        // does this syntax work?
        "/verbs/actions/obj/bloodlust"->eventRage(who);
      }
    }
  }
  //
  return 1;
}

