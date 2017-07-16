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
    "This quiet corner is the place where two walls meet, "
    "blocking the wilderness. It is quite barren here except "
    "for a few patches of grass sticking up stubbornly through "
    "the dunes. The path leads northward and westward toward "
    "a small body of water."
  );
  SetItems( ([
    "garden" : "This is a public garden, complete with "
    "animals and various plants.",
    ({ "sand", "path" }) : 
    "The sandy path seems to be less used the further you "
    "move from the city.",
    ({ "grass", "patches" "patch" }) : 
    "The grass struggles to survive in this dry area. ",
  ]) );
  SetItemAdjectives( ([
   "path" : ({"sandy"}),
   "garden" : ({ "public" }),
   "grass" : ({"stubborn"}),
  ]) );
  SetInventory( ([
    NEWBIE_NPC "asp" : 4,
  ]) );
  SetListen("Distant sounds can be heard.");
  SetSmell("The air is clean and free of fragrance.");
  SetExits( ([
    "north" : NEWBIE_ROOM "/2d",
    "west" : NEWBIE_ROOM "/3c",
  ]) );
}
