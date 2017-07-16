/*
  Griffon
  By: 
  Objective: Lower level good
     summon for conjuring based
     summon spell.
*/

#include <lib.h>
#include <damage_types.h>
inherit LIB_NPC;

void eventTail();
void eventBreath();
void eventDostuff();
int Damage;
int SetDamageAmount(int damage);

static void create() {
  ::create();
  SetKeyName("griffin");
  SetShort("a small golden griffin");
  SetAdjectives( ({"small","golden"}) );
  SetLong(
    "Truly magnificent, even for its small size, "
    "this griffon sports a nearly nine foot wing "
    "span. Her golden feathers mesh beautifully with "
    "her silver claws. The most prominent feature of "
    "her face is a razor-sharp beak which looks equally "
    "capable of cutting flesh or breaking bone. An "
    "inner fire seems to flicker within her intelligent "
    "eyes."
  );
  SetRace("griffin");
  SetGender("female");
  SetClass("fighter");
  SetLevel(30);
  SetMorality(350);
  SetAction(5, ({
    "!emote rustles its wings.",
    "!emote chirps slightly."
  }) );
  SetCombatAction(25, (: eventDostuff :) );
}

void eventDostuff() {
  object garg = this_player();
  object target = GetCurrentEnemy();

  switch(random(32)) {
    case 1..19:
      garg->eventTail(target);
    break;
    case 20..32:
      garg->eventBite(target);
    break;
  }
}

void eventBite() {
  object target = GetCurrentEnemy();
  if(present(target)){

    send_messages( "bite",
      "%^BOLD%^YELLOW%^With a resounding roar, " + 
      "$agent_name $agent_verb $target_name causing severe damage!%^RESET%^",
      this_object(), target, environment(target) );
    target->eventReceiveDamage(this_object(), PIERCE, Damage, 0);
  }
  return;
}

int SetDamageAmount(int damage){
        return (Damage = damage);
}

void eventTail() {
  object target = GetCurrentEnemy();
  if(present(target)){

    send_messages( "swing",
      "%^BOLD%^BLACK%^With a flap of $agent_possessive_noun wings, " + 
      "$agent_name $agent_verb $agent_possessive_noun body at $target_name "
      "striking at them viciously with $agent_possessive claws!%^RESET%^",
      this_object(), target, environment(target) );
    target->eventReceiveDamage(this_object(), SLASH, Damage, 0);
  }
  return;
}
