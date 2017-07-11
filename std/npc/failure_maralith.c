#include <lib.h>
#include <std.h>

inherit LIB_NPC;
inherit LIB_FEAR;

int lifespan = 3;

int SetLifeSpan(int span);

static void create()
{
  npc::create();

  SetKeyName("maralith");
  SetShort("a six armed demoness");
  SetLong("This demon is a six armed creature from the Abyss. Her body "
          "is composed of a humanlike torso which leads down into a "
          "snakelike lower body which gives her quick mobility. Her head "
          "is humanlike and rather beautiful. The stunning feature that "
          "stands out however is the six arms that protrude from her torso "
          "ready for action.");
  SetGender("female");
  SetId( ({ "demon", "maralith", "demoness", "spell_failure_maralith" }) );
  SetRace("maralith");
  SetClass("fighter");
  SetInventory( ([
    STD_WEAPON "sword" : 3,
    STD_WEAPON "hack/large_axe" : 3,
    ]) );
  SetFirstCommands( ({ "wield all" }) );
  SetLevel(10);
  SetAdjectives( ({ "six-armed", "six armed" }) );
  SetMorality(-1000);
  SetFearType("demon fear");
  SetResistLevel(15);
  SetFearLength(5);
  SetNoCorpse(1); 
  SetDie("%^BOLD%^BLUE%^The demoness disperses into a fine mist and is gone.%^RESET%^");
}

void init() {
  npc::init();
  fear::init();
}

static void heart_beat() {
  npc::heart_beat();

  if (lifespan--) return;
  environment()->eventPrint("%^BOLD%^BLUE%^The demoness disperses into a fine mist and is gone.%^RESET%^");
  eventDestruct();
}

int SetLifeSpan(int span) { return lifespan = span; 
}
