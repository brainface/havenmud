//Selket@Haven
//2006
#include <lib.h>
#include "../newbie.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("at a muddy pool");
  SetClimate("arid");
  SetLong(
    "The scummy pool here has attracted all manner of "
    "animals to the area, some of which can be dangerous. "
    "Reeds and the occasional lotus bloom here, but the "
    "water looks undrinkable and unhealthy even for fish. "
    "The pond seems to curve around to the southwest, and "
    "the sandy trail leads in all cardinal directions."
  );
  SetItems( ([
    "garden" : "This is a public garden, complete with "
    "animals and various plants.",
    ({ "sand", "path" }) : 
    "The sandy path seems to be less used the further you "
    "move from the city.",
    ({ "pool", "water", "pond" }):
    "The water looks more like mud, and smells foul. ",
    ({ "animals" }) : 
    "Indeed, the animal that lives here seems to be a "
    "ferocious crocodile. ",
    ({ "reed", "lotus" }) : 
    "The reeds are spindly, yellowish-green tubes. The lotus "
    "flowers range from a deep azure to the palest of tissue pinks, "
    "and give off a pleasing aroma that seems almost defiled by "
    "the muddy stench. ",
  ]) );
  SetItemAdjectives( ([
   "path" : ({"sandy"}),
  "path" : ({ "sandy", "small"}),
  "pool" : ({ "scummy", "muddy" }),
   "animals" : ({ "dangerous" }),
  ]) );
  SetInventory( ([
    NEWBIE_NPC "crocodile" : 1,
  ]) );
  SetListen("The mud burbles occasionally.");
  SetSmell("A noxious scent rises from the mud.");
  SetExits( ([
    "north" : NEWBIE_ROOM "/1c",
    "south" : NEWBIE_ROOM "/3c",
    "east" : NEWBIE_ROOM "/2d",
    "west" : NEWBIE_ROOM "/2b",
  ]) );
}
