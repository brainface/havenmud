#include <lib.h>
inherit LIB_ROOM;
#include "../underdark.h"

static void create() {
  room::create();
  SetShort("on a small mountain");
  SetLong("On the foot of a small mountain. The land all around seems "
          "dead. There are no trees, bushes, or animals anywhere. Rising up "
          "in the north is the peak of the mountain. A cave opening can be "
          "seen a little way  to the north, yawning open like some foul "
          "black, stalactite toothed mouth.");
  SetExits( ([
          "north" : U_ROOM + "room6a",
          "south" : U_ROOM + "room1a",
          "east" : U_ROOM + "room4a",
          "west" : U_ROOM + "room2a"]) );
  SetItems( ([
          "land" : "The dead land stretches away into the distance.",
          ({ "foot", "hills", "foothills" })  : "The foothills of the mountain. "
          "The hills steadilly rise up to the mountain. They are all a uniform "
          "dead brown color with no vegitation, other than dead grass, or "
          "animals to be seen. ",
          "mountain" : "A small grey craggy mountain with a cave opening "
          "about half way up.",
          ({ "cave", "opening", "cave opening", "mouth" }) : "The opening "
          "of a cave. It looks like a yawning, foul black, stalactite toothed "
          "mouth. Somhow it seems darker just inside the opening than it "
          "ought to.",
          ({ "stalactite", "stalactites" }) : "Large stalactite formations, common "
          "in damp caves, droop from the roof of the cave. Some of the larger "
          "ones reach nearly to the floor.",
          ({ "peak", "mountain peak" }) : "A tall spire of solid grey rock. "
          "A little bit of snow covers the peak with an icy slick. It would be "
          "extremely dangerous to climb."]) );
  SetSmell( ([
          "default" : "The air has a faint foul smell to it."]) );
  SetListen( ([
          "default" : "A strong wind whistles over the crags and cliffs of "
          "the mountain."]) );
  SetInventory( ([
          U_NPC + "dazed_dwarf" : 1 ]) );
  }
