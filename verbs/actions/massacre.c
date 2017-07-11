// mahkefel 2011
// berserking combat action, just an area effect. highish damage,
// highish level.
#include <lib.h>
#include <damage_types.h>
#include <rounds.h>
#include <vision.h>
inherit LIB_ACTION;

int eventAttack(object who, object* targets);
int eventAction(object who, object* target);

static void create() {
  ::create();
  SetVerb("massacre");
  SetRules("LIV","");
  SetHelp("No mere novice with a hatchet, you exhaust yourself hewing about "
    "in deadly strokes that carve through platemail or daemon-hide as if it "
    "were papyrus."
  );
  SetStaminaCost(500);
  SetRequiredWeapon("hack");
  SetRequiredSkills( ([
    "hack combat" : 300,
    "berserking" : 300,
  ]) );

}

// overridden for area effect
int eventAction(object who, object* targets) {
  if(who->GetTestChar()) debug ("event action");
  who->SetAttack(targets, (: eventAttack, who, targets :), ROUND_OTHER);
  who->AddStaminaPoints(-StaminaCost);
  return 1;
}

mixed can_massacre() {
  if (!this_player()->GetInCombat()) { return "But you fight no one!"; }
  return CanAction(this_player());
}

mixed can_massacre_liv() {
  return CanAction(this_player());
}

mixed do_massacre_liv(object target) {
  return eventAction(this_player(), ({target}) );
}

mixed do_massacre() {
  return eventAction(this_player(), this_player()->GetEnemies() );
}


int eventAttack(object who, object* targets) {
  int result, damage;
  string limb;

  // stupid temporary stuff to make one message work right.
  int weapons = sizeof( GetWeapons(who) );
  string word = "axe";

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

  if (weapons > 1) word = "axes";
  send_messages( ({ "hurl" }),
    "$agent_name%^RED%^BOLD%^ $agent_verb%^RESET%^ $agent_possessive " + word +
    " around in a wide circle of death!",
    who, 0, environment(who));

  foreach (object target in targets) {
    object weapon = GetAnyWeapon(who);
    result = GetHit(who,target);
    if (who->GetTestChar()) debug("massacre result: " + result);
    //FUMBLE!
    if (result == -1) {
      send_messages( ({ "duck" }), "$target_name%^RED%^ "
        "$target_verb%^RESET%^ beneath $agent_possessive_noun "
        "unstoppable swing!",
        who, target, environment(who));
    // normal miss
    } else if (result == 0) {
      send_messages( ({ "carve" }),
      "$agent_possessive_noun axe%^RED%^ carves%^RESET%^ a furrowed "
        "line into $target_possessive_noun flesh!",
        who, target, environment(who));
      target->AddBleeding(1,10);
    // hit
    } else {

      if (!weapon) {
        debug("Dude massacred without a weapon. this should not be possible.");
        who->eventPrint("You appear to be mysteriously unarmed!");
        return 0;
      }

      limb = target->GetRandomLimb();
      send_messages( ({"hack"}),
        "$agent_name%^BOLD%^%^RED%^ $agent_verb%^RESET%^ through "
        "$target_possessive_noun " + limb + " with "
        "$agent_possessive " + weapon->GetKeyName() + "!",
        who, target, environment(who) );
      
      damage = GetHighDamage(who, weapon);
      if (who->GetTestChar()) debug("massacre damage: " + damage);
      damage = target->GetDamageInflicted(who, weapon->GetDamageType(), damage, 0, limb);
      if (who->GetTestChar()) debug("massacre damage after GetDamageInflicted: " + damage);
      target->eventInflictDamage(who, weapon->GetDamageType(), damage, 0, limb);

      //He like columbus, he get murderous on purpose.
      "/verbs/actions/obj/rage"->eventRage(who);
      "/verbs/actions/obj/rage"->eventRage(who);
    }
  }
  //
  return 1;
}
