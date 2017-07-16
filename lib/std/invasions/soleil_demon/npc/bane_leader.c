// A Bane Devil
// Demon Invasion of Soleil
// Coded by: Unknown
// Rewritten: Laoise, 2005

#include <lib.h>
#include <std.h>
#include <daemons.h>
#include <dirs.h>
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
    "looks sharp and viscious. A stylized brand upon his forehead "
    "appears to indicate he has some rank among the demons."
  );
  SetRace("devil");
  AddLimb("tail", "torso", 2);
  SetGender("male");
  SetClass("rogue");
  SetLevel(45);
  SetMorality(-200);
  SetFearType("devil fear");
  SetResistLevel(24);
  SetFearLength(10);
  SetCombatAction(6, (: eventThing :) );
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
    eventForce("yell die "+who->GetCapName() + "!!");

  return 1;
  }
return 0;
}
