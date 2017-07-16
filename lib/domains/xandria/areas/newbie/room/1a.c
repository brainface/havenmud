//Selket@Haven
//2006
#include <lib.h>
#include <domains.h>
#include "../newbie.h"
inherit LIB_ROOM;
int PreExit();

static void create() {
  room::create();
  SetShort("entrance to a public garden");
  SetClimate("arid");
  SetLong(
    "This is a garden open to the people of Lisht. It "
    "is a well tended miniature representation of the "
    "Xandrian countryside, with local plants and fauna. "
    "A small sandy path cuts through the area, leading "
    "south and west. A major roadway lies to the north, "
    "back into the city.");
  SetItems( ([
    "garden" : "This is a public garden, complete with "
    "animals.",
    ({ "major roadway", "major road", "road", "roadway"}) :
    "The road to the north is the Wall Road of Lisht. ",
    "fauna" : "Brightly plumed birds, crawling and winged "
    "insects, and the occasional lizard or other creature "
    "all make their homes in this place.",
    "entrance" : "The entrance into the garden is north, and "
    "it leads through a small gate back into the city of Lisht.",
    ({ "sand", "path" }) : 
    "The sandy path seems to be less used the further you "
    "move from the city.",
    ({ "plants" }) : 
    "The plants range from delicate desert flowers and grasses "
    "to spindly incense trees and spiny cacti.",
  ]) );
  SetItemAdjectives( ([
  "path" : ({ "small", "sandy" }),
   "plants" : ({ "local" }),
  "garden" : ({ "public", "lisht" }),
  "roadway" : ({ "major", "wall" }),
  ]) );
  SetInventory( ([
    NEWBIE_NPC "asp" : 1,
    NEWBIE_NPC "scarab" : 2,
  ]) );
  SetListen("The sound of birds chirping can be heard.");
  SetSmell("It smells fresh and sweet here.");
  SetExits( ([
    "south" : NEWBIE_ROOM "/2a",
    "east"  : NEWBIE_ROOM "/1b",
  ]) );
  AddExit("north", XANDRIA_TOWNS "lisht/room/gnoll/wr4", (: PreExit :) );
}

int PreExit() {
    if (this_player()->id("lisht_newbie") ) {
        if (this_player()->GetOwner() == "")
          return 0;
        }
    return 1;
}
