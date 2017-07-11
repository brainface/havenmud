//Selket@Haven
//2006
#include <lib.h>
#include "../newbie.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("a muddy area");
  SetClimate("arid");
  SetLong(
    "Here is one end of a muddy pool of stagnant water. "
    "Although the other end of the pool offers some lush "
    "and verdant plant life, here the mud has all but choked "
    "it out. However, the clay seems to be perfect for the "
    "forming of pots. The sandy path leads east and west, "
    "as well as north to a clearing."
  );
  SetItems( ([
    "garden" : "This is a public garden, complete with "
    "animals and various plants.",
    ({ "sand", "path" }) : 
    "The sandy path seems to be less used the further you "
    "move from the city.",
    "area" : "The area is quite muddy and not unlike a "
    "cesspit in many ways, but the clay here is useful. ",
    ({ "mud", "clay" }) : 
    "The redish brown mud is thick and great for potting. ",
    ({ "water", "pool" }) : 
    "The water is neither fit for drinking nor fishing. ",
  ]) );
  SetItemAdjectives( ([
   "path" : ({"sandy"}),
   "garden" : ({ "public" }),
   "area" : ({ "muddy" }),
   "water" : ({"stagnant"}),
  ]) );
  SetInventory( ([
    NEWBIE_NPC "potter" : 1,
  ]) );
  SetListen("The thick mud burbles occasionally.");
  SetSmell("The air smells like dirt.");
  SetExits( ([
    "north" : NEWBIE_ROOM "/2b",
    "west" : NEWBIE_ROOM "/3a",
    "east" : NEWBIE_ROOM "/3c",
  ]) );
}
