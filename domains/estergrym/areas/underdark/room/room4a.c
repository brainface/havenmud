#include <lib.h>
inherit LIB_ROOM;
#include "../underdark.h"

static void create() {
  room::create();
  SetShort("on a small mountain");
  SetLong("On the foot of a small mountain. The land all around seems "
          "dead. There are no trees, bushes, or animals anywhere. Rising up "
          "in the northwest is the peak of the mountain. A cave opening can "
          "be seen a off to the northwest, yawning open like some foul "
          "black, stalactite toothed mouth.");
  SetExits( ([
          "north" : U_ROOM + "room7a",
          "west" : U_ROOM + "room3a"]) );
  SetItems( ([
          "land" : "The dead land stretches away into the distance.",
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
          "default" : "There is a strong smell of dust."]) );
  SetListen( ([
          "default" : "A strong wind whistles over the crags and cliffs of "
          "the mountain."]) );
  }
