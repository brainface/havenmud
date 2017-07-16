/*
  Gargoyle
  By: 
  Objective: Lower level evil
     summon for conjuring based
     summon spell.
*/

#include <lib.h>
#include <damage_types.h>
inherit LIB_NPC;

void eventBite();
void eventDostuff();
int Damage;
int SetDamageAmount(int damage);

static void create() {
  ::create();
  SetKeyName("gargoyle");
  SetShort("a massive stone gargoyle");
  SetAdjectives( ({"massive","stone"}) );
  SetLong(
    "Massive by an ogre's standard, this gargoyle had to have been "
    "carved from a massive monolith. Gigantic bat-like wings wrap "
    "around its body, creating an impression of terrifying impenetrability. "
    "Peering over the protective barrier of its wings, the gargoyle's "
    "massive stone head resembles that of a horned ape, snarling to reveal "
    "a horrifying set of fangs."
  );
  SetRace("gargoyle");
  SetClass("fighter");
  SetLevel(45);
  SetMorality(-350);
  SetAction(5, ({
    "!emote rustles its wings.",
    "!grin evilly"
  }) );
  SetCombatAction(25, (: eventDostuff :) );
}

void eventDostuff() {
  object garg = this_player();
  object target = GetCurrentEnemy();

  garg->eventBite(target);
}

int SetDamageAmount(int damage){
        return (Damage = damage);
}

void eventBite() {
  object target = GetCurrentEnemy();
  if(present(target)){

    send_messages( "bite",
      "%^BOLD%^BLACK%^With a horrifying roar, " + 
      "$agent_name $agent_verb $target_name causing severe damage!%^RESET%^",
      this_object(), target, environment(target) );
    target->AddPoison(15);    
    target->eventReceiveDamage(this_object(), PIERCE, Damage, 0);
  }
  return;
}
