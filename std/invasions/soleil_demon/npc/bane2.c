// A Bane Devil, Leader
// Demon Invasion of Soleil
// Coded by: Unknown
// Rewritten: Laoise, 2005

#include <lib.h>
#include <damage_types.h>
#include <armour_types.h>
inherit LIB_INVADER;
inherit LIB_FEAR;

int eventThing();
int CheckSoleil();

static void create() {
  invader::create();
  SetKeyName("bane devil");
  SetShort("a bane devil");
  SetId( ({ "devil", "demon_inv" }) );
  SetAdjectives( ({ "bane" }) );
  SetLong(
    "This bane devil is a short and stocky creature with pure "
    "evil written on his face. His horrible hooked tail "
    "looks sharp and viscious."
  );
  SetRace("devil");
  AddLimb("tail", "torso", 2);
  SetGender("male");
  SetClass("rogue");
  SetLevel(30);
  SetMorality(-200);
  SetFearType("devil fear");
  SetResistLevel(24);
  SetFearLength(10);
  SetCombatAction(6, (: eventThing :) );
  SetEncounter( (: CheckSoleil :) );
  SetFriends( ({ "demon_inv" }) );
  SetWanderSpeed(5);
  SetWanderPath( ({ 
    "go up", "enter home", "go north", "go south", "go out",
    "enter town hall", "go out", "go down"
  }) );
  SetWanderRecurse(1);
}

int eventThing() {
  object target = GetCurrentEnemy();
  object who = this_object();
  if (GetLimb("tail")) {
    send_messages("attack",
      "$agent_name $agent_verb%^RED%^BOLD%^ $target_name "
      "%^RESET%^with $agent_possessive tail!",
      who, target, environment() ); 
    GetCurrentEnemy()->eventReceiveDamage(this_object(), ACID,
      (random(50) + 50), 0); 
  return 1;
  }
return 0;
}

int CheckSoleil() {
  object who = this_player();
  if (!userp(who) && !(who->GetProperty("invader")) ) {
    SetAttack(who);
    eventForce("yell die "+ who->GetCapName() + "!!");
  return 1;
  }
return 0;
}


void init() {
  fear::init();
  invader::init();
}
