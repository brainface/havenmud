#include <lib.h>
inherit LIB_ROOM;
#include "../castle.h"

static void create() {
   room::create();
   SetClimate("indoors");
   SetAmbientLight(30);
   SetShort("a downward stairway");
   SetLong("The air opens below, with wooden beams passing across the "
           "unenclosed space to hold up the stone-gray rocks this castle "
           "is built of.  A pale gray mortar holds the rocks together, "
           "as well as the general laws of nature.  The stones proceed "
           "to go upward in a stairstep manner on the floor, following "
           "the outer wall.  Downward is a potential direction for "
           "departure; to the west there is also an opening into a "
           "hallway.");
   SetItems( ([
                ({ "wooden beams","beams","beam","wooden beam",
                   "solid beams of thick wood","solid beams","solid beam",
                   "solid beam of thick wood","wood","thick wood",
                   "beam of thick wood","beam of wood","beams of thick "
                   "wood","beams of wood","solid beam of wood",
                   "solid beams of wood" }) :
                   "Solid beams of thick wood keep the castle from "
                   "collapsing due to the weight of all the stones that "
                   "make up the rest of it.",
                ({ "small room","fairly small room","room","air",
                   "unenclosed space","space","castle" }) :
                   (: GetLong :),
                ({ "downward stairway","stairway","stairs","stair",
                   "staircase","case","stone-gray rocks","gray rocks",
                   "stone-gray rock","gray rock","rock","rocks",
                   "pale gray mortar","mortar","gray mortar",
                   "stones","stone","outer wall","wall","floor" }) :
                   "The staircase heads downward, leading to the first "
                   "floor of the castle, hidden from view by the "
                   "stairs themselves as they turn around and follow "
                   "the walls.  All the stones are fairly regular in "
                   "shape and size, building flat surfaces to "
                   "walk upon.",
           ]) );
   SetExits( ([
                "down" : VC_ROOM + "/stair1",
                "west" : VC_ROOM + "/hall3",
           ]) );
   SetInventory( ([
                    VC_NPC + "/servant" : 1,
                    VC_NPC + "/slave_f" : random(2),
                    VC_NPC + "/soldier" : 2+random(2),
               ]) );
}
