/*  TelgoReCoded 1998.11.07          */
/*  Glimmerdin's Northern Hall Room  */
/*  Completely recoded in September of 2004
 *  Duuk
 */
#include <lib.h>
#include "../path.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("indoors");
  SetAmbientLight(25);
  SetShort("the northern end of the Great Hall");
  SetLong(
    "The Great Hall ends here against the finely hewn walls of the cavern. "
    "Built into the stone is a massive cathedral which dominates the "
    "entire wall to the north. Its gigantic pillars rise to the very top "
    "of the cavern, where they fade off into the darkness. To the west, "
    "the hall leads off into a smaller area with slightly less traffic. "
    "To the east lies the Glimmerdin cemetery, a place for quiet contemplation "
    "of recent losses. To the south lies the Center of Glimmerdin."
    );
  SetProperty("no teleport",1);
  SetProperty("no conjuring",1);
  SetItems( ([
    ({ "wall", "walls" }) : 
      "The walls are smooth and well crafted stone.",
    ({ "stone" }) :
      "The stone of the cavern is smooth and well hewn.",
    ({ "pillar", "pillars" }) :
      "The pillars are massive structures of stone that rise far beyond "
      "sight into the upper reaches of the cavern.",
    ({ "cathedral", "church" }) :
      "The Cathedral of Kylin is the central focus of the northern wall. "
      "Its pillars rise into the depths of the ceiling, far out of view. "
      "The clean stone of the walls are perfectly hewn and flawless in "
      "every detail.",
    ({ "cemetery", }) :
      "The cemetery lies to the east, a quiet tomb of contemplation.",
    ]) );
  SetItemAdjectives( ([
    "wall"  : ({ "stone", "finely", "hewn" }),
    "stone" : ({ "smooth", "well", "crafted" }),
    "pillar" : ({ "gigantic", "massive", "stone" }),
    "cathedral" : ({ "kylin", "massive", }),
    ]) );
  SetEnters( ([
    "cathedral" : G_ROOM "church",
    ]) );
  SetExits( ([
    "south" : G_ROOM "gh_central",
    "east"  : G_ROOM "cemetery",
    "west"  : G_ROOM "gh_west",
    ]) );
  SetSmell( ([
    "default" : "The smells of food waft in from the west.",
    ]) );
  SetListen( ([
    "default" : "Music echoes in from the west.",
    ]) );
  SetInventory( ([
    G_NPC "basic_guard"  : 3,
    G_NPC "pouch_vendor" : 1,
    ]) );
}
