/* Clefting, a hack attack combat style */
#include <lib.h>
inherit LIB_COMBATSTYLE;

static void create() {
  ::create();
  SetStyleName("clefting");
  SetTrainingPointCost(14);
  SetStaminaCost(2);
  SetSkills( ([
      "hack attack" : 10,
  ]) );
  SetHelp("Clefting is the art of overhand weapon attacks, "
          "specifically hack-style weapons, which can be used "
          "by someone properly trained to deadly effectiveness."
          );
}

int eventStyle(object who, int level, mixed target) {
  object *weapons = who->GetWielded();
  int amount = 0;
  string limb;

  if (arrayp(target)) target = target[0];
  if (!target) { return 0; }
  if (!sizeof(weapons)) {
    message("system",
       "You must be wielding only hack weapons to use clefting!",
       who);
    return 1;
    }
  foreach(object weapon in weapons) {
    if (weapon->GetWeaponType() != "hack") {
      message("system",
         "You must be wielding only hack weapons to use clefting!", 
         who);
      return 1;
      }
    }
  amount = 25;
  if (!target) { return 1; }
  if(random(100) < level) {
    switch(random(200)) {
      case 0:
        limb = target->GetRandomLimb();
        send_messages( ({ "scream", "hack" }),
          "$agent_name $agent_verb and%^RED%^BOLD%^ $agent_verb into "
          "$target_possessive_noun " + limb + ", doing severe "
          "damage!%^RESET%^",
          who, target, environment(who) );
        target->eventReceiveDamage(who, weapons[0]->GetDamageType(),
          weapons[0]->eventStrike(target) + who->GetStatLevel("strength"),
          0, limb);
        amount = 200;
        break;          
      case 1..100:
        send_messages( ({ "swing", "slam" }),
          "$agent_name%^BLUE%^BOLD%^ $agent_verb with a huge arc "
          "%^RESET%^and $agent_verb into $target_name deeply!",
          who, target, environment(who) );
        target->eventReceiveDamage(who, weapons[0]->GetDamageType(),
          weapons[0]->eventStrike(target) + 20, 0, target->GetTorso() );
        amount = 100;
        break;
      default:
        send_messages( ({ "make", "get" }),
          "$agent_name $agent_verb a quick motion, and "
          "$agent_verb in an %^RED%^BOLD%^extra attack!%^RESET%^",
          who, target, environment(who));
        who->eventWeaponRound(target, weapons);
        amount = 50;
        break;
      }
   }
  who->eventTrainCombatStyle("clefting", amount);
  who->eventWeaponRound(target, weapons);
  return 1;
}
