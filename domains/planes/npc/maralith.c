/*  A maralith  */
//mahkefel 2010 mar: added armour
#include <lib.h>
#include "../planes.h"
inherit LIB_SENTIENT;
inherit LIB_FEAR;

void WearHalo();

static void create() {
  sentient::create();
  SetKeyName("maralith");
  SetId( ({ "demon", "maralith", "demoness" }) );
  SetAdjectives( ({ "six-armed", "six armed" }) );
  SetShort("a six armed demoness");
  SetLong("This demon is a six armed creature from the Abyss. Her body "
          "is composed of a humanlike torso which leads down into a "
          "snake-like lower body which gives her quick mobility. Her head "
          "is humanlike and rather beautiful. The stunning feature that "
          "stands out however is the six arms that protrude from her torso "
          "ready for action.");
  SetGender("female");
  SetRace("maralith");
  SetClass("fighter");
  SetLevel(160);
  SetCurrency( ([
    "imperials" : random(1200) + 1,
  ]) );
  SetEncounter(101);
  SetFearLength(10);
  SetFearType("demon fear");
  SetFirstCommands( ({
    "wear halo",
  }) );
  SetInventory( ([
    "/std/weapon/blunt/war-hammer"  : "wield hammer in lower left hand",
    "/std/weapon/hack/hand-axe" : "wield first axe in lower right hand",
    "/std/weapon/slash/bluesword"   : "wield longsword in upper left hand",
    "/std/weapon/slash/shortsword"  : "wield shortsword in middle left hand",
    "/std/weapon/blunt/mace"        : "wield mace in middle right hand",


    "/std/weapon/blunt/copper_club" : "wield club in upper right hand",
    PLANE_OBJ + "breastplate" : 
      "wear breastplate on torso and upper right arm and upper left arm",
    PLANE_OBJ + "bracer" : 
      "wear bracer on middle left arm and middle left hand",
    PLANE_OBJ + "halo" : "wear halo",
  ]) );
  SetMorality(-1500);
  SetResistLevel(15);
  SetSkill("heavy plate armour",324,1);
  SetWanderSpeed(5);
}

void init() {
  sentient::init();
  fear::init();
}


