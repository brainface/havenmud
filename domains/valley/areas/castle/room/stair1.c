#include <lib.h>
inherit LIB_ROOM;
#include "../castle.h"

static void create() {
   room::create();
   SetClimate("indoors");
   SetAmbientLight(30);
   SetShort("an upward stairway");
   SetLong("The air opens above, with wooden beams passing across the "
           "unenclosed space to hold up the stone-gray rocks this castle "
           "is built of.  A pale gray mortar holds the rocks together, "
           "as well as the general laws of nature.  The stones proceed "
           "to go upward in a stairstep manner on the floor, following "
           "the outer wall.  Two exits, besides upward, leave this "
           "fairly small room:  One is a door heading west; the other "
           "an open archway to the north.");
   SetItems( ([
                ({ "open archway","archway","arch" }) :
                   "The archway leads into the entrance of the castle, "
                   "just north of here.",
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
                ({ "upward stairway","stairway","stairs","stair",
                   "staircase","case","stone-gray rocks","gray rocks",
                   "stone-gray rock","gray rock","rock","rocks",
                   "pale gray mortar","mortar","gray mortar",
                   "stones","stone","outer wall","wall","floor" }) :
                   "The staircase heads upward, leading to the second "
                   "floor of the castle, hidden from view by the "
                   "stairs themselves as they turn around and follow "
                   "the walls.  All the stones are fairly regular in "
                   "shape and size, building flat surfaces to "
                   "walk upon.",
           ]) );
   SetExits( ([
                "up" : VC_ROOM + "/stair2",
                "north" : VC_ROOM + "/ent",
                "west" : VC_ROOM + "/grhall1",
           ]) );
   SetInventory( ([
                    VC_NPC + "/servant" : 2,
                    VC_NPC + "/serf" : random(1),
                    VC_NPC + "/soldier" : 2+random(2),
               ]) );
}
