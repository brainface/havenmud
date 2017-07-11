//Selket@Haven
//2006
#include <lib.h>
#include "../newbie.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("within a public garden");
  SetClimate("arid");
  SetLong(
    "Here the garden tends to be a bit overgrown, with "
    "a healthy layer of underbrush from fallen leaves "
    "and older grasses. The path continues east and west, "
    "and also the south, where a small body of water stands. "
  );
  SetItems( ([
    "garden" : "This is a public garden, complete with "
    "animals and various plants.",
    ({ "sand", "path" }) : 
    "The sandy path seems to be less used the further you "
    "move from the city.",
    ({ "underbrush", "grass", "grasses", "leaves" }) : 
    "Desert grasses and leaves from the spindly incense "
    "trees cover the ground around the path.",
  ]) );
  SetItemAdjectives( ([
   "path" : ({"sandy"}),
  "garden" : ({ "public " }),
   "leaves" : ({ "fallen" }),
   "grasses" : ({ "older" }),
  ]) );
  SetInventory( ([
    NEWBIE_NPC "scarab" : 4,
  ]) );
  SetListen("The wind rustles the dead grasses.");
  SetSmell("The air smells of decaying leaves.");
  SetExits( ([
    "west" : NEWBIE_ROOM "/1b",
    "east" : NEWBIE_ROOM "/1d",
    "south" : NEWBIE_ROOM "/2c",
  ]) );
}
