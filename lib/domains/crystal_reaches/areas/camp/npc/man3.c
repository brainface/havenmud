
#include <lib.h>
#include <std.h>
#include "../camp.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("man");
  SetShort("an older man");
  SetId( ({"man"}) );
  SetAdjectives( ({"older"}) );
  SetLong(
    "This man has salt and pepper hair and "
    "mahogany eyes. His hands are very soft with "
    "long slender fingers. His face is deeply lined "
    "from smiling. "
    );
  SetRace("human");
  SetGender("male");
  SetClass("bard");
  SetLevel(20);
  SetSongBook( ([
  	"warrior's honor" : 100,
  	"tavern song"     : 100,
  	"famine"          : 100,
  	]) );
  SetCombatAction(25, ({
  	"!sing warrior's song",
  	"!sing tavern song",
  	"!sing famine",
    }) );
  SetMorality(100);
  SetAction(5, ({ 
    "!plays a heart wrenching piece on the lyre." 
    }) );
  SetInventory( ([
    C_OBJ + "pants4" : "wear pants",
    C_OBJ + "shirt1" : "wear shirt",
    C_OBJ + "knife1" : "wield knife", 
    STD_INSTRUMENTS + "lyre" : 1,
  ]) );
}
