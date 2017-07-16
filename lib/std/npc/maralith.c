/*  A maralith
  */
#include <lib.h>
#include <std.h>
inherit LIB_SENTIENT;
inherit LIB_FEAR;

static void create() {
  sentient::create();
  SetKeyName("maralith");
  SetShort("a six armed demoness");
  SetLong("This demon is a six armed creature from the Abyss. Her body "
          "is composed of a humanlike torso which leads down into a "
          "snakelike lower body which gives her quick mobility. Her head "
          "is humanlike and rather beautiful. The stunning feature that "
          "stands out however is the six arms that protrude from her torso "
          "ready for action.");
  SetGender("female");
  SetId( ({ "demon", "maralith", "demoness" }) );
  SetRace("maralith");
  SetClass("fighter");
  SetLevel(24);
  SetAdjectives( ({ "six-armed", "six armed" }) );
  SetInventory( ([
    "/std/weapon/blunt/war-hammer" : "wield hammer in lower left hand",
      "/std/weapon/hack/hand-axe" : "wield first axe in lower right hand",
      "/std/weapon/slash/bluesword" : "wield longsword in upper left hand",
     "/std/weapon/slash/shortsword" : "wield shortsword in middle left hand",
      "/std/weapon/blunt/mace" : "wield mace in middle right hand",
      "/std/weapon/blunt/copper_club" : "wield club in upper right hand",
      ]) );
  SetMorality(-1000);
  SetCurrency( ([
     "imperials" : random(1200),
     ]) );
  SetEncounter(101);
  SetWanderSpeed(5);
  SetFearType("demon fear");
  SetResistLevel(15);
  SetFearLength(10);
  }

void init() {
  sentient::init();
  fear::init();
  }
