// Black Abashani
// Demon Invasion of Soleil
// Coded by: Unknown
// Rewritten: Laoise, 2005

#include <lib.h>
#include <damage_types.h>
inherit LIB_INVADER;
inherit LIB_FEAR;
void eventSpecial();
int CheckSoleil();

static void create() {
  invader::create();
  SetKeyName("black abashai");
  SetShort("a black abashai");
  SetId( ({ "abashai", "devil", "demon_inv" }) );
  SetAdjectives( ({ "black" }) );
  SetLong(
    "An abashai is a fearsome devil which looks vaguely "
    "like a lizard except for his powerful wings. The black "
    "variety are the weakest, but should not be underestimated."
  );
  SetRace("devil");
  AddLimb("tail", "torso", 4);
  AddLimb("left wing", "torso", 4);
  AddLimb("right wing", "torso", 4);
  SetGender("male");
  SetClass("fighter");
  SetLevel(18);
  SetMorality(-100);
  SetResistLevel(12);
  SetFearType("devil fear");
  SetFearLength(10);
  SetMeleeAttackString("claws");
  SetMeleeDamageType(SLASH);
  SetCombatAction(15, (: eventSpecial :) );
  SetEncounter( (: CheckSoleil :) );
  SetFriends( ({ "demon_inv" }) );
  SetWanderSpeed(5);
  SetWanderPath( ({ 
    "enter hall", "go east", "go out", "go west", "go down",
    "go down", "go north", "go south", "go west", "go east",
    "enter inn", "go out", "go up", "go up", "go west", 
    "go west", "go east", "go east", "go east", "go east",
    "go west", "go west",
  }) );
  SetWanderRecurse(1);
}

void eventSpecial() {
  switch (random(2)) {
     case 0:
  if (!GetLimb("tail")) return;
    send_messages("swipe",
      "$agent_name%^RED%^BOLD%^ $agent_verb%^RESET%^ $target_name "
      "visciously with $agent_possessive barbed tail.",
       this_object(), GetCurrentEnemy(), environment());
    GetCurrentEnemy()->eventReceiveDamage(this_object(), 
      PIERCE, random(80), 0);
    GetCurrentEnemy()->AddPoison(10);
  return;
default:
return;
  }
}

int CheckSoleil() {
  object who = this_player();
  if(!userp(who) && !(who->GetProperty("invader"))) {
    SetAttack(who);
    eventForce("emote snarls and lunges at "+who->GetKeyName());
    return 1;
  }
return 0;
}

void init() {
  fear::init();
  invader::init();
}