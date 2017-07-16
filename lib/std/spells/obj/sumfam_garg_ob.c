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
  SetShort("a small stone gargoyle");
  SetAdjectives( ({ "small", "stone" }) );
  SetLong(
    "The slight cracks and deformations of this gargoyle "
    "show that it has, thus far, passed the test of time by "
    "little more than sheer luck and good fortune. With "
    "a snarling, fanged muzzle it looks much like a "
    "rabid dog, ready to take a bite out of the closest "
    "living thing. Patches of multicolored mold are "
    "spread across most of the gargoyle, especially "
    "concentrated on its sharp teeth."
  );
  SetRace("gargoyle");
  SetClass("fighter");
  SetLevel(30);
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
