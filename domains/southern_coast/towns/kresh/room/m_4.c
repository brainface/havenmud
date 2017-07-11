#include <lib.h>
#include "../goblins.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("a path through the village");
  SetLong(
    "The path continues on to the south and to the northeast, where "
    "it joins up with the main path through the village.  To the south "
    "there are several tents which seem important. "
    "There is a quiet and humble looking tent here."
    );
  SetSmell( ([
     "default" : "The path smells of waste and offal.",
    ]) );
  SetListen( ([
     "default" : "The sounds of the goblin village are quieter here.",
      ]) );
  SetInventory( ([
     GOBLIN_NPC + "medium" : 3,
    ]) );
  SetItems( ([
    "tent" : "This tent serves as the post and news tent for Kresh.",
    ]) );
  SetEnters( ([
    "tent" : GOBLIN_TENT "office",
    ]) );
  SetExits( ([
     "northeast" : GOBLIN_ROOM + "m_3",
     "south" : GOBLIN_ROOM + "m_6",
    ]) );
  }
