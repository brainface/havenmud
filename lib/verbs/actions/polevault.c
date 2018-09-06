#include <lib.h>
#include <damage_types.h>
#include <vision.h>
#include <armour_class.h>
#include <damage_types.h>
inherit LIB_ACTION;

static void create() {
  ::create();
  SetVerb("polevault");
  SetRules("LIV", "");
  SetHelp("Syntax: polevault, polevault LIV\n\n"
  	"Sometimes you want to kick someone, but they're just too far away. With "
  	"this technique, you solve that ancient dilema by using your quarterstaff "
  	"to shove off the ground and get your feet closer to their face. Making "
  	"contact is devastating to your opponent, but you lose all momentum."
    "\nYou cannot perform acrobatics in heavy armour."
  );
  SetStaminaCost(300);
  SetRequiredWeapon("pole");
  SetRequiredSkills( ([
    "acrobatics" : 150,
    "melee combat" : 150,
    "pole combat" : 150,
    ]) );
  SetCooldown(10);
  SetHands(2);
  SetRage("/verbs/actions/obj/momentum");
  SetMaxArmourClass(ARMOUR_REINFORCED);
}

mixed can_polevault() {
  if (!this_player()->GetInCombat()) { return "polevault who?"; }
  return CanAction(this_player());
}

mixed can_polevault_liv() {
  return CanAction(this_player());
}

mixed do_polevault_liv(object target) {
  return eventAction(this_player(), target);
}

mixed do_polevault() {
  return do_polevault_liv(this_player()->GetCurrentEnemy());
}

int eventAttack(object who, object target) {
  int result, damage;
  object weapon = GetAnyWeapon(who);
  string limb = target->GetRandomLimb("head");

  if (!weapon) {
    debug("Dude polevaultbed without a weapon. this should not be possible.");
    who->eventPrint("You appear to be mysteriously unarmed!");
    return 0;
  }

  result = GetHit(who,target);
  // announce attack to room
  send_messages( ({ "run", "plant" }),
    "$agent_name $agent_verb and%^BOLD%^MAGENTA%^ $agent_verb%^RESET%^ "
    "$agent_possessive_noun " + weapon->GetKeyName() + "into the ground in "
    "front of $agent_objective!",
    who, target, environment(who));
  if (who->GetTestChar()) debug("polevault result: " + result);

  // drop weapon on a fumble
  if (result == -1) {
  	send_messages( ({ "fumble" }), "$agent_name%^BOLD%^RED%^ $agent_verb%^RESET%^ "
      "the vault, leaping "
      "gracelessly into thin air beside $target_name and losing $agent_possessive "
      "grip on " + weapon->GetKeyName() + "!",
      who, target, environment(who) );
    weapon->eventUnequip(who);
    weapon->eventDrop(who);
    GetRage()->eventEndRage();
    return 1;
    
  // miss on a miss
  } else if (result == 0) {
    send_messages( ({ "lean" }),
      "$target_name%^YELLOW%^ $target_verb%^RESET%^ to the side, narrowly dodging the blade!",
      who, target, environment(who));
    // add momentum
    GetRage()->eventRage(who);
    return 1;
  }

  if (who->GetTestChar()) debug("polevault should be a success!");

  // this is a kick, use melee damage calcs.
  weapon = who;

  // success message
  send_messages( ({"polevault"}),
    "$agent_name%^BOLD%^MAGENTA%^ $agent_verb%^RESET%^ forward into $target_possessive_noun "
    + limb + ", kicking forward with both feet!",
    who, target, environment(who) );
  if (who->GetTestChar()) debug("Past funky sendmessage!");

  // apply damage
  damage = GetHighDamage(who, weapon);
  if (who->GetTestChar()) debug("polevault damage: " + damage);
  damage = target->GetDamageInflicted(who, who->GetMeleeDamageType(), damage, 0, limb);
  if (who->GetTestChar()) debug("polevault damage after GetDamageInflicted: " + damage);
  target->eventInflictDamage(who, who->GetMeleeDamageType(), damage, 0, limb);

  // knockdown target
  target->eventCollapse();
  
  // end momentum
  GetRage()->eventEndRage(who);
  
  return 1;
}

