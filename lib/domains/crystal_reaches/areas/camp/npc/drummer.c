#include <lib.h>
#include "../camp.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("drummer");
  SetId( ({ "drummer"}) );
  SetShort("a drummer");
  SetLong(
    "The drummer is a young man with brown "
    "hair and green eyes.  He smiles as he beats his "
    "drums."
  );
  SetRace("human");
  SetGender("male");
  SetClass("bard");
  SetLevel(15);
  SetSongBook( ([
  	"warrior's honor" : 100,
  	"staccato"        : 100,
  	"famine"          : 100,
  	]) ); 
  SetCombatAction(25, ({
    "!sing warrior's honor",
    "!sing staccato",
    "!sing famine",
    }) );
  SetMorality(100);
  SetAction(5, ({ 
    "The drummer keeps a steady rhythm." 
  }) );
  SetInventory( ([
    C_OBJ + "pants1" : "wear pants",
    C_OBJ + "shirt1" : "wear shirt",
    C_OBJ + "drum1" : 1,
    C_OBJ + "knife1" : "wield knife" 
  ]) );
}
