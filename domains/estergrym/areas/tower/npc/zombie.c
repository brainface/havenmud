#include <lib.h>
#include <std.h>
#include <damage_types.h>
#include "../defs.h"

inherit LIB_NPC;

static void create() {
  ::create();
  SetRace("gelfling");
  SetGender("male");
  SetClass("rogue");
  SetLevel(random(15)+50);
  SetKeyName("zombie");
  SetId( ({ "zombie", "grunt"}) );
  SetShort("a zombie grunt");
  SetAdjectives( ({ "grunt", "undead" }) );
  SetLong("This zombie is rotten all over his body. His rotted skin "
          "is peeling off of his muscles and dangling by thin "
          "patches. His milky white eyes are encased in bumpy rotted "
          "eyelids which drain a clear liquid off his face. As he "
          "surveys his surroundings he looks around for any sign "
          "of life to feast on.");
  SetUndead(1);
  SetWander(10);
  SetInventory( ([
    TOWER_OBJ + "strap" : 1,
	TOWER_OBJ + "zcloak" : "wear cloak",
   ]) );
  SetMorality(-15);
  SetStat("charisma", 201, 1);
  SetFriends(({TOWER_NPC+"skeleton1"
               TOWER_NPC+"sumskeleton"
               TOWER_NPC+"nsumskeleton"
               TOWER_NPC+"skeleton2"
               TOWER_NPC+"necromancer"
               TOWER_NPC+"mummy"
  }));  
  SetResistance(ACID, "high");
  SetResistance(GAS, "high");
  SetResistance(HUNGER, "high");
  SetResistance(DISEASE, "high");
}
