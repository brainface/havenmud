#include <lib.h>
inherit LIB_ROOM;
#include "../underdark.h"
#define ROAD "/domains/estergrym/virtual/grymxoria_road/15,0"

static void create() {
  room::create();
  SetShort("the foot of a small mountain");
  SetLong("At the foothills of a small mountain, the land all around seems "
          "to be dead. There are no trees, bushes, or animals anywhere.  "
          "Rising up in the north is a small mountain. A cave opening can "
          "be seen about half way up the mountain, yawning like some foul "
          "black, stalactite toothed mouth.");
  SetExits( ([
          "north" : U_ROOM + "room3a",
          "south" : ROAD,
          ]) );
  SetItems( ([
          "land" : "The dead land stretches away in every direction.",
          ({ "foothills", "hills" }) : 
          "The foothills of the mountain. The hills steadilly rises up to the "
          "mountain. All the hills have an uniform dead brown color with no "
          "vegatation, other than the dead grass. ",
          ({ "mountain"}) : 
          "A small grey craggy mountain with a cave opening about half way up.",
          ({ "cave", "opening", "mouth" }) : 
          "The opening of a cave. It looks like a yawning, foul black, stalactite "
          "toothed mouth. Somhow it seems darker just inside the opening than it "
          "ought to.",
          ({ "stalactite", "stalactites" }) : 
          "Large stalactite formations, common in damp caves, droop from the roof "
          "of the cave. Some of the larger ones reach nearly to the floor."
          ]) );
  SetItemAdjectives( ([
  				"mountain" : ({"small", "grey", "craggy"}),
  				"opening"  : ({"cave"}),
  				"mouth"    : ({"yawning", "foul", "black", "toothed"}),
    ]) );
  SetSmell( ([
          "default" : "There is a stong smell of dust.",
    ]) );
  SetListen( ([
          "default" : "A strong wind whistles over the barren land.",
    ]) );
}
