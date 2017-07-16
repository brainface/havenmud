/*  A maralith
  */

#include <lib.h>
#include <std.h>
inherit LIB_INVADER;
inherit LIB_FEAR;

static void create() {
  invader::create();
  SetKeyName("maralith");
  SetShort("a six armed demoness");
  SetId( ({ "demon", "maralith", "demoness", "demon_inv" }) );
  SetAdjectives( ({ "six-armed", "six armed" }) );
  SetLong(
    "This demon is a six armed creature from the Abyss. Her body "
    "is composed of a humanlike torso which leads down into a "
    "snakelike lower body which gives her quick mobility. Her head "
    "is humanlike and rather beautiful. The stunning feature that "
    "stands out however is the six arms that protrude from her torso "
    "ready for action."
  );
  SetGender("female");
  SetRace("maralith");
  SetClass("fighter");
  SetLevel(125);
  SetMorality(-1000);
  SetEnemyTown("Haven");
  SetInventory( ([
    STD_BLUNT + "war-hammer" : "wield hammer in lower left hand",
    STD_HACK + "hand-axe" : "wield first axe in lower right hand",
    STD_SLASH + "bluesword" : "wield longsword in upper left hand",
    STD_SLASH + "shortsword" : "wield shortsword in middle left hand",
    STD_BLUNT + "mace" : "wield mace in middle right hand",
    STD_BLUNT + "copper_club" : "wield club in upper right hand",
      ]) );
  SetCurrency( ([
    "imperials" : random(1200),
  ]) );
  SetFearType("demon fear");
  SetResistLevel(15);
  SetFearLength(10);
  SetFriends( ({ "demon_inv" }) );
  SetWanderSpeed(5);
  SetWanderPath( ({
    "go east", "go east", "go east", "go east", "go east", "go east",
    "go east", "go east", "enter library", "go east",
    "go east", "attack alhana" 
  }) );
}

void init() {
  invader::init();
  fear::init();
}
