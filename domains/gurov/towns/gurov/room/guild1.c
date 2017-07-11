#include <lib.h>
#include "../gurov.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetExits( ([
    "out"  : GUROV_ROOM "tavern",
    "east" : GUROV_ROOM "guild2",
    ]) );
  SetClimate("indoors");
  SetAmbientLight(35);
  SetShort("inside the Guild of Thieves");
  SetLong(
    "The Guild Hall is a dimly lit place where people are not "
    "encouraged to take too active a look at their surroundings. "
    "Though the Guild is tolerated as a necessary evil by the Prince, "
    "that does not make it secure in its place by any means. The walls "
    "of this \"hall\" seem to be more like underground tunnels, and "
    "condensation forms and drips from them freely."
    );
  SetItems( ([
    ({ "wall", "walls" }) : "Water (and other less mentionable fluids) "
                            "drip down the walls onto the floor.",
    ({ "condensation", "water", "fluid", "fluids" }) :
                            "The fluids are a mix of water and waste.",
    "floor" : "The floor is slick with the fluid that drips from the walls.",
    ]) );
  SetSmell("The slimy floor and dripping fluid smell of human waste.");
  SetListen("The sounds of the tavern above echo through the ceiling.");
  SetInventory( ([
    GUROV_NPC "leon" : 1,
    ]) );
}
