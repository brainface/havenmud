// Goblin invasion of Soleil
// Original coder: Unknown
// Edited: Laoise, 2005

#include <lib.h>
#include "../gis.h"

inherit LIB_INVADER;

static void create() {
  invader::create();
  SetKeyName("leader");
  SetId( ({ "orc", "leader", "goblin_inv" }) );
  SetShort("an orc leader");
  SetAdjectives( ({ "orc", "tall", "very", "impressive" }) );
  SetLong(
    "This orc is very tall. Standing about seven feet tall, he has to "
    "hunch down inside this tent. His skin is brown in color and he "
    "has no hair. He is very impressive standing there looking over "
    "maps and planning strategies."
  );
  SetRace("orc");
  SetGender("male");
  SetClass("fighter");
  SetLevel(25 + random(10));
  SetAction(6, ({ 
    "!attack first citizen",
    "!attack first muezzin",
  }) );
  SetCombatAction(30, ({
    "!say Kill everything that moves!!",
    "!emote deftly moves about in an attack pattern",
    "!emote swings his sword in very skilled arcs",
  }) );
  SetInventory( ([
    GIS_OBJ + "leader_armour" : "wear armour",
    GIS_OBJ + "leader_sword" : "wield sword",
    GIS_OBJ + "backpack" : "wear backpack",
  ]) );
  SetCurrency("cuicui", 500 + random(300));
  SetFriends( ({ "goblin_inv" }) );
  SetWanderSpeed(5);
  SetWander(10, ({ 
    "go south", "go up", "go south",
  }), 1);
  SetDie("Orc leader falls down in death.");
}