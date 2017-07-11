#include <lib.h>
#include "../camp.h"
inherit LIB_NPC;	

static void create() {
  npc::create();
  SetKeyName("girl");
  SetId( ({ "girl"}) );
  SetAdjectives(  ({"adolescent"}) );
  SetShort("an adolescent girl");
  SetLong(
    "This girl is in her adolescence. She has thick black "
    "hair and warm brown eyes. Her smile is bright and "
    "sunny. She seems to enjoy laughing."
  );
  SetRace("human");
  SetClass("bard");
  SetLevel(10);
  SetSongBook( ([
  	"debutant aria"  : 100,
  	"staccato"       : 100,
  	"harpy's shriek" : 100,
  	]) ); 
  SetCombatAction(25, ({
    "!sing debutant aria",
    "!sing staccato",
    "!sing harpy's shriek",
    }) );
  SetGender("female");
  SetMorality(250);
  SetAction(5, ({ 
    "!emote laughs heartily."
  }));
  SetInventory( ([
    C_OBJ + "dress3" : "wear dress",
    C_OBJ + "dagger1" : 2
  ]) );
  SetFirstCommands( ({
  	"wield first dagger in left hand",
  	"wield first dagger in right hand",
  }) );
}
