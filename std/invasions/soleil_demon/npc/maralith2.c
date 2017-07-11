// A Maralith
// Demon Invasion of Soleil
// Coded by: Unknown
// Rewritten: Laoise, 2005

#include <lib.h>
#include <std.h>
inherit LIB_INVADER;
inherit LIB_FEAR;

int CheckSoleil();

static void create() {
  invader::create();
  SetKeyName("maralith");
  SetShort("a six armed demoness");
  SetId( ({ "demon", "maralith", "demoness", "demon_inv" }) );
  SetAdjectives( ({ "six-armed", "six armed" }) );
  SetLong(
    "This demon is a six armed creature from the Abyss. Her body "
    "is composed of a humanlike torso which leads down into a "
    "snake-like lower body which gives her quick mobility. Her head "
    "is humanlike and rather beautiful. The stunning feature that "
    "stands out however is the six arms that protrude from her torso "
    "ready for action."
  );
  SetRace("maralith");
  SetGender("female");
  SetClass("fighter");
  SetLevel(45);
  SetMorality(-500);
  SetInventory( ([
    STD_HACK "large_axe" : "wield large axe in lower left hand",
    STD_HACK "hand-axe" : "wield first axe in lower right hand",
    STD_SLASH "bluesword" : "wield longsword in upper left hand",
    STD_SLASH "shortsword" : "wield shortsword in middle left hand",
    STD_BLUNT "mace" : "wield mace in middle right hand",
    STD_BLUNT "copper_club" : "wield club in upper right hand",
  ]) );
  SetCurrency( ([
    "imperials" : random(1200),
  ]) );
  SetFearType("demon fear");
  SetResistLevel(15);
  SetFearLength(10);
  SetEncounter( (: CheckSoleil :) );
  SetFriends( ({ "demon_inv" }) );
  SetWanderSpeed(5);
  SetWanderPath( ({ 
    "go up", "enter home", "go north", "go south", "go out",
    "enter town hall", "go out", "go down"
  }) );
  SetWanderRecurse(1);
}

int CheckSoleil() {
  object who = this_player();
  if(!userp(who) && !(who->GetProperty("invader"))) {
    SetAttack(who);
    eventForce("yell I have come to make this place a lower plane!");
    return 1;
  }
return 0;
}

void init() {
  invader::init();
  fear::init();
}
