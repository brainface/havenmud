/*   Portia  1-9-99
    The evoker's study.
 */

#include <lib.h>
#include "../mal.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("an evoker's workroom");
  SetClimate("indoors");
SetAmbientLight(20);
  SetExits( ([
    "northwest" : MAL_ROOMS3 + "hall1",
    "southwest" : MAL_ROOMS3 + "hall2",
    ]) );
  SetInventory( ([
    MAL_NPC3 + "lead_evok" : 1,     
    MAL_NPC3 + "teach_evok" : 1,    
    ]) );
  SetSmell( ([
    "default" : "The air smells of incense and mildew.",
    ]) );
  SetListen( ([
    "default" : "Chanting is all that can be heard.",
    ]) );
  SetLong("This study is obviously the workroom of a "
    "powerful evoker. There are no windows and the only "
    "light comes from a large torch in the center of the "
    "room. The room is very neat and everything is in its "
    "place. Only one large spellbook lies on the obsidian "
    "table. An odd shaped crack splits the middle of the room. "
    "Something very heavy would have to have fallen to create such "
    "a crack in the obsidian. The walls here curve very much to the west.");
  SetItems( ([
    ({"walls", "wall"}) : "The walls curve westward here.",
    ({"light"}) : "The light is bright from the torch.",
    ({"crack"}) : "The crack is not deep, merely long.",
    ({"torch"}) : "The torch sits brightly in the center of "
      "of the room.",
    ({"spellbook"}) : "The large spellbook is the only one "
      "on the table.",
    ({"table"}) : "The table of obsidian sits in the corner "
      "of the room.",
    ({"corner"}) : "The corner is filled with the table.",
    ]) );
  SetItemAdjectives( ([
    "crack" : ({"long", "odd", "shaped"}),
    "light" : "bright",
    "torch" : "large",
    "spellbook" : ({"one", "large"}),
    "table" : "obsidian",
    ]) );
  }
