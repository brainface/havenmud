//Selket@Haven
//2006
#include <lib.h>
#include "../newbie.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("at a scummy watering hole");
  SetClimate("arid");
  SetLong(
    "The muddy water sluices through the area here, running "
    "both north and west. A few water plants thrive in the "
    "murky shallows, and a few animals enjoy the moist mud. "
    "The path of sand leads north and west, following the "
    "banks of the muddy water, and eastward."
  );
  SetItems( ([
    "garden" : "This is a public garden, complete with "
    "animals and various plants.",
    ({ "sand", "path" }) : 
    "The sandy path seems to be less used the further you "
    "move from the city.",
    ({ "plant", "water plant" "plants" }) : 
    "The plants do not appear unusual. ",
    ({ "water", "pool", "hole", "pond" }) :
    "The water is neither fit for drinking nor fishing. ",
    ({ "animals", "animal" }) : 
    "Hippopotamuses have made their dwellings here. ",
  ]) );
  SetItemAdjectives( ([
   "path" : ({"sandy"}),
   "garden" : ({ "public" }),
   "hole" : ({ "watering" }),
   "water" : ({"muddy"}),
  ]) );
  SetInventory( ([
    NEWBIE_NPC "hippo" : 2,
  ]) );
  SetListen("The thick mud burbles occasionally.");
  SetSmell("The air reeks of hippo.");
  SetExits( ([
    "north" : NEWBIE_ROOM "/2c",
    "west" : NEWBIE_ROOM "/3b",
    "east" : NEWBIE_ROOM "/3d",
  ]) );
}
