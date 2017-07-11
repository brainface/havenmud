#include <lib.h>
#include "../camp.h"
inherit LIB_NPC;	

static void create() {
  npc::create();
  SetKeyName("dancer");
  SetId( ({ "dancer"}) );
  SetAdjectives(  ({"graceful"}) );
  SetShort("a graceful dancer");
  SetLong(
    "The graceful dancer has long, thick black "
    "hair and violet eyes. She flashes her beautiful smile "
    "as she twirls about and sings beautifully."
  );
  SetRace("human");
  SetGender("female");
  SetClass("bard");
  SetLevel(20);
  SetSongBook( ([
  	"staccato"       : 100,
  	"harpy's shriek" : 100,
  	]) );
  SetCombatAction(25, ({
  	"!sing staccato",
  	"!sing harpy's shriek",
    }) );
  SetMorality(200);
  SetAction(5, ({ 
    "The dancer sways and twirls gracefully.",
    "The dancer sings beautifully. "
  }));
  SetInventory( ([
    C_OBJ + "dress1" : "wear dress",
    C_OBJ + "dagger1" : 2,
  ]) );
  SetFirstCommands( ({
  	"wield first dagger in left hand",
  	"wield first dagger in right hand",
  }) );
}
