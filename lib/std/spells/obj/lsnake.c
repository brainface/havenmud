//Mahkefel@Haven
//2011
#include <lib.h>
#include <damage_types.h>
inherit LIB_NPC;

void eventSpecial();

static void create() {
  npc::create();
  SetKeyName("cobra");
  SetId( ({"cobra"}) );
  SetShort("a spitting cobra");
  SetAdjectives( ({ "spitting" }) );
  SetRace("snake");
  SetSkill("dodge",1);
  SetSkill("parry",1);
  SetClass("animal");
  SetLevel(10);
  SetGender("male");
  SetLong(
    "This hooded cobra is covered in black and red stripes. "
    "Milky venom drips from his fangs, and he stares up at you "
    "as if taking aim.");
  SetCombatAction(15, (: eventSpecial :) );
  SetAction(6, ({
     "!emote weaves back and forth.",
     "!emote hisses angrily.",
  }) );
}

void eventSpecial() {
  object who = this_object();
  object target = GetCurrentEnemy();
  send_messages("spit",
    "$agent_name%^YELLOW%^ $agent_verb%^RESET%^ poison at "
    "$target_possessive_noun face!", who, target, environment() );
  target->eventReceiveDamage(who, POISON, random(100), 0,
    target->GetRandomLimb("head") );
  target->eventBlind(1,2);
  return;
}

void eventMeleeAttack(object target, string limb) {
  npc::eventMeleeAttack(target, limb);
  if(!(random(10))) {
    target->AddPoison(5);
  message("system",
        "You feel the %^RED%^poison%^RESET%^ moving through your body.",
        target);
    message("system",
        capitalize(target->GetKeyName()) + " suddenly looks ill.",
        environment(target), target);
    }
  return;
}

