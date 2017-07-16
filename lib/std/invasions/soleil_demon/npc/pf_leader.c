// A Pit Fiend, Leader
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
  SetKeyName("pit fiend");
  SetShort("a pit fiend");
  SetId( ({ "fiend", "devil", "demon_inv" }) );
  SetAdjectives( ({ "pit" }) );
  SetLong(
    "This pit fiend is a towering giant of a devil with a reddish "
    "body and huge wings jutting from his torso. His large claws "
    "and huge teeth set this creature apart as a viscious killer."
    "This particular pit fiend looks larger then average and has "
    "an intricate mark branded upon his forehead, appearing to denote "
    "his high rank among the demons."
  );
  SetRace("devil");
  AddLimb("left wing", "torso", 2);
  AddLimb("right wing", "torso", 2);
  SetGender("male");
  SetClass("fighter");
  SetLevel(65);
  SetFearType("devil fear");
  SetResistLevel(45);
  SetFearLength(30);
  SetCombatAction(3, (: eventSpecial :) );
  SetMeleeAttackString("claws");
  SetMeleeDamageType(SLASH);
  SetEncounter( (: CheckSoleil :) );
  SetFriends( ({ "demon_inv" }) );
  SetWanderSpeed(5);
  SetWanderPath( ({ 
    "go up", "go down", "enter gallery", "go out", "enter temple", 
    "go out",
  }) );
  SetWanderRecurse(1);
  SetAction(5, ({
    "!emote looks around maniacally.",
  }) );
}

void eventSpecial() {
  object who = this_object();
  object target = GetCurrentEnemy();

  send_messages("tear",
    "$agent_name%^RED%^ $agent_verb%^RESET%^ at $target_name "
    "with $agent_possessive teeth.", who, target, environment() );
  target->eventReceiveDamage(who, SLASH, random(500), 0, 
    target->GetRandomLimb("head") );
  return;
}

int CheckSoleil() {
  object who = this_player();
  if(!userp(who) && !(who->GetProperty("invader"))) {
    SetAttack(who);
    eventForce("laugh evilly");
    eventForce("emote bares his teeth in a horrible grin and "
    "leans towards "+ who->GetCapName());
    return 1;
  }
return 0;
}

void init() {
  invader::init();
  fear::init();
}
