#include <lib.h>
#include "../gurov.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetExits( ([
    "west" : GUROV_ROOM "guild1",
    ]) );
  SetClimate("indoors");
  SetAmbientLight(35);
  SetShort("the central hall of the Guild of Thieves");
  SetLong(
    "The Guild of Thieves central hall is only slightly more impressive "
    "than the tunnel which led to it. A wooden floor seems to be elevated "
    "slightly from the ground, allowing the muck from the walls to travel "
    "down and under rather than underfoot. Thin wooden slats line the walls, "
    "preventing the fluid from dripping on to anything important."
    );
  SetItems( ([
    "wall" : "The walls of the Guild are thin wooden slats that have seen "
             "better days.",
    ({ "slat", "slats" }) : "The slats are thin wood that seems to be discolored "
                            "and possibly rotting from the opposite side.",
    ]) );
  SetSmell("The fluid smells bad even through the walls and floor.");
  SetListen("The sounds of the tavern are muffled from here.");
  SetInventory( ([
    GUROV_OBJ "rogue_ladder" : 1,
    GUROV_NPC "dirty_trainer" : 1,
    ]) );
}
