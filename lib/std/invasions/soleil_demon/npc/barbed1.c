// A Barbed Devil
// Demon Invasion of Soleil
// Coded by: Unknown
// Rewritten: Laoise, 2005

#include <lib.h>
#include <damage_types.h>
inherit LIB_INVADER;
inherit LIB_FEAR;
int eventTail();
int CheckSoleil();

static void create() {
  invader::create();
  SetKeyName("barbed devil");
  SetShort("a barbed devil");
  SetId( ({ "devil", "demon_inv" }) );
  SetAdjectives( ({ "barbed" }) );
  SetLong(
    "This is a barbed devil, a fiery evil looking creature with "
    "wicked spiked hands and a long, evil looking tail."
  );
  SetRace("devil");
  AddLimb("tail", "torso", 2);
  SetGender("male");
  SetClass("rogue");
  SetLevel(25);
  SetMorality(-200);
  SetCurrency("imperials", random(800));
  SetFearType("devil fear");
  SetResistLevel(18);
  SetFearLength(8);
  SetCombatAction(5, (: eventTail :) );
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

int eventTail() {
  object target = GetCurrentEnemy();
  object who = this_object();
  if (GetLimb("tail")) {
    send_messages("swipe",
      "$agent_name $agent_verb%^RED%^BOLD%^ evilly%^RESET%^ with "
      "$agent_possessive tail!", who, target, environment() );
    target->eventReceiveDamage(who, PIERCE, random(200));
  return 1;
  }
return 0;
}

int CheckSoleil() {
  object who = this_player();
  if(!userp(who) && !(who->GetProperty("invader"))) {
    SetAttack(who);
    eventForce("speak time to die "+who->GetCapName()+ "!");
    return 1;
  }
return 0;
}

void init() {
  invader::init();
  fear::init();
}
