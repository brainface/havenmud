//Selket@Haven
//2006
#include <lib.h>
#include <domains.h>
#include "../newbie.h"
#define NEWBIE 1
inherit LIB_ROOM;
int PreExit();

static void create() {
  room::create();
  SetShort("entrance to a public garden");
  SetClimate("arid");
  SetLong(
    "This is a garden open to the people of Lisht. It "
    "is a well tended miniature representation of the "
    "Xandrian countryside, with local plants and fauna.  "
    "A small sandy path cuts through the area, leading  "
    "south, east, and west. A major roadways lies north, "
    "back into the city.");
  SetItems( ([
    "garden" : "This is a public garden, complete with "
    "animals.",
    ({ "major roadway", "major road", "road", "roadway"}) :
    "The road to the north is the River Alley of Lisht. ",
    ({ "sand", "path" }) : 
    "The sandy path seems to be less used the further you "
    "move from the city.",
    ({ "plants" }) : 
    "The plants range from delicate desert flowers and grasses "
    "to spindly incense trees and spiny cacti.",
  "entrance" : "The entrance to the garden is north, leading "
    "into Lisht through a small gate.",
    "fauna" : "Brightly plumed birds, winged and crawling insects, "
    "and other animals all reside happily here in the garden.",
  ]) );
  SetItemAdjectives( ([
  "path" : ({"sandy", "small"}),
   "plants" : ({ "local" }),
  "roadway" : ({ "major", "lisht" }),
  ]) );
  SetInventory( ([
    NEWBIE_NPC "horus" : 1,
    NEWBIE_NPC "scarab" : 2,
  ]) );
  SetListen("The wind blows playfully through the grasses.");
  SetSmell("It smells sweet and fresh here.");
  SetExits( ([
    "west" : NEWBIE_ROOM "/1a",
    "east" : NEWBIE_ROOM "/1c",
    "south" : NEWBIE_ROOM "/2b",
  ]) );
  AddExit("north", XANDRIA_TOWNS "lisht/room/elf/ra4", (: PreExit :) );
}

int PreExit() {
    if (this_player()->id("lisht_newbie")) {
        if (this_player()->GetOwner() == "")
          return 0;
    }
    return 1;
}
