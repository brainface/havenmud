#include <lib.h>
#include "../camp.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("man");
  SetId( ({ "man"}) );
  SetAdjectives( ({"young"}) );
  SetShort("a young man");
  SetLong(
    "The young man has black "
    "hair and blue eyes. He smiles as he awkwardly "
    "plays a tambourine."
  );
  SetRace("human");
  SetGender("male");
  SetClass("bard");
  SetLevel(10);
  SetSongBook( ([
  	"protective note" : 100,
  	"staccato"        : 100,
  	"famine"          : 100,
  	]) ); 
  SetCombatAction(25, ({
    "!sing warrior's honor",
    "!sing staccato",
    "!sing drift",
    }) );
  SetMorality(100);
  SetAction(5, "The young man laughs.");
  SetInventory( ([
    C_OBJ + "pants1" : "wear pants",
    C_OBJ + "shirt1" : "wear shirt",
    C_OBJ + "tambourine1" : 1,
    C_OBJ + "knife1" : "wield knife",
    ]) );
}
