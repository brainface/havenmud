#include <lib.h>
#include "../camp.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("woman");
  SetId( ({ "woman"}) );
  SetAdjectives( ({"young"}) );  
  SetShort("a young woman");
  SetLong(
    "This young woman has dark brown "
    "hair and bright green eyes. Her hands are "
    "soft and smooth with long, agile fingers."
  );
  SetRace("human");
  SetClass("bard");
  SetLevel(15);
  SetSongBook( ([
  	"glory of the mage" : 100,
  	"staccato"          : 100,
  	"tavern song"       : 100,
  	]) ); 
  SetCombatAction(25, ({
    "!sing glory of the mage",
    "!sing staccato",
    "!sing tavern song",
    }) );

  
  SetGender("female");
  SetMorality(100);
  SetAction(5, ({ 
    "!plays a melody that's easy to dance to." 
  }));
  SetInventory( ([
    C_OBJ + "shirt1" : "wear shirt",
    C_OBJ + "skirt1" : "wear skirt",
    C_OBJ + "mandolin" : "wield mandolin",
    C_OBJ + "dagger1" : "wield dagger" 
  ]) );
}
