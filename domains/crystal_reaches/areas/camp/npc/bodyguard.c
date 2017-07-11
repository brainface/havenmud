
#include <lib.h>
#include <std.h>
#include "../camp.h"
inherit LIB_SENTIENT;

static void create() {
  sentient::create();
  SetKeyName("bodyguard");
  SetShort("the leader's bodyguard");
  SetId( ({ "bodyguard" }) );
  SetAdjectives( ({ "leader's" }) );
  SetLong(
    "The leader's bodyguard is an imposing figure. "
    "He is young, tall, and brawny. His face is as hard "
    "as stone. He takes his job very seriously."
  );
  
  SetRace("human");
  SetGender("male");
  SetClass("necromancer");
  SetLevel(30);
  
  SetSpellBook( ([
    "boneshell"  : 100,
    "wound"      : 100,
    "acid blast" : 100,
    "cloudkill"  : 100,
  ]) );
  SetCombatAction(50, ({ 
    "!cast boneshell",
    "!cast wound",
    "!cast acid blast",
    "!cast cloudkill",
  }) );
  
  SetInventory( ([
    C_OBJ + "staff1" : "wield staff",
    C_OBJ + "pants2" : "wear pants",
    C_OBJ + "shirt5" : "wear shirt",
  ]) );
  SetAction(3, ({
    "!emote watches over the leader.",
  }) );
  SetSpellBook( ([
    "necromantic shield" : 100,
    "drain soul"         : 100,
    "acid rain"          : 100,
    "lava storm"         : 100,
    "fireball"           : 100,
  ]) );
  SetCombatAction(15, ({ 
    "!cast drain soul",
    "!cast acid rain",
    "!cast lava storm",
    "!cast fireball"
  }) );
  SetFirstCommands( ({
    "cast necromantic shield",
    "cast necromantic shield",
    "cast necromantic shield",   
    "cast necromantic shield",
    "cast necromantic shield",
  }) );
}
