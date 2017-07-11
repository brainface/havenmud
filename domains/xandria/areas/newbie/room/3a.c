//Selket@Haven
//2006
#include <lib.h>
#include "../newbie.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("in a southern corner of the garden");
  SetClimate("arid");
  SetLong(
    "Here the walls meet, closing the garden off from the "
    "wilderness. Cacti grow in this drier edge of the "
    "garden, tall and green amidst the sand and sky. Little "
    "else is here but the path, which leads north towards a "
    "small clearing and east, towards a body of water. "
  );
  SetItems( ([
    "garden" : "This is a public garden, complete with "
    "animals and various plants.",
    ({ "sand", "path" }) : 
    "The sandy path seems to be less used the further you "
    "move from the city.",
    "corner" : "Here the walls meet to form a corner, fencing "
    "off the garden from the city and the outside world.",
    ({ "cactus", "cacti" }) : 
    "Tall, short, round, spiny. They're not something you "
    "need to get too close to. ",
  ]) );
  SetItemAdjectives( ([
   "path" : ({"sandy"}),
   "garden" : ({ "public" }),
  ]) );
  SetInventory( ([
    NEWBIE_NPC "asp" : 3,
  ]) );
  SetListen("It is quiet here.");
  SetSmell("The air is fresh and clean.");
  SetExits( ([
    "north" : NEWBIE_ROOM "/2a",
    "east" : NEWBIE_ROOM "/3b",
  ]) );
}
