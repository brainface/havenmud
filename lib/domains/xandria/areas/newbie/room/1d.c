//Selket@Haven
//2006
#include <lib.h>
#include "../newbie.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("a quiet corner");
  SetClimate("arid");
  SetLong(
    "The walls of Lisht that contain this garden meet here, "
    "keeping the bedlam of the city at bay. A towering tree "
    "stands here, taller than any in all of Lisht. It seems "
    "ancient. The path leads south and east. "
  );
  SetItems( ([
    "garden" : "This is a public garden, complete with "
    "animals and various plants.",
    ({ "sand", "path" }) : 
    "The sandy path seems to be less used the further you "
    "move from the city.",
    "corner" : "The walls meet here, closing off the garden.",
    ({ "tree" }) : 
    "The tree is tall, but doesn't clear the height of the "
    "walls. It was probably planted eons ago, before the "
    "city became so large.",
  ]) );
  SetItemAdjectives( ([
  "path" : ({"sandy", "small" }),
  "garden" : ({ "public" }),
   "tree" : ({ "ancient", "towering" }),
  ]) );
  SetInventory( ([
    NEWBIE_NPC "asp" : 3,
  ]) );
  SetListen("It is peaceably quiet here.");
  SetSmell("The tree exudes a pleasant scent.");
  SetExits( ([
    "west" : NEWBIE_ROOM "/1c",
    "south" : NEWBIE_ROOM "/2d",
  ]) );
}
