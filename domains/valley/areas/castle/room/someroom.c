#include <lib.h>
inherit LIB_ROOM;
#include "../castle.h"

static void create() {
   room::create();
   SetClimate("indoors");
   SetAmbientLight(25);
   SetShort("inside the donjon");
   SetLong("A general path seems to go from the door to the north to "
           "another door that is to the east.  Mud and dirt have been "
           "tracked in along that line, moreso than in the rest of the "
           "room, though it seems that a good deal of mud hangs near a "
           "bench set against the west wall.  To the south, the room "
           "extends into a hallway, the pale gray stones of the castle "
           "lightening in that direction.");
   SetItems( ([
                ({ "pale gray stones","gray stones","pale stones","stones",
                   "pale gray stone","gray stone","pale stone","stone",
                   "dusty unpolished wooden beams","dusty wooden beams",
                   "unpolished wooden beams","dusty unpolished beams",
                   "dusty beams","unpolished beams","wooden beams","beams",
                   "dusty unpolished wooden beam","dusty wooden beam",
                   "unpolished wooden beam","dusty unpolished beam","beam",
                   "dusty beam","unpolished beam","wooden beam" }) :
                   "The stones make up the donjon, supported by the "
                   "dusty and unpolished wooden beams that extend "
                   "from spot to spot, adding to the sturdiness of the "
                   "structure.",
                ({ "donjon","room","small room","general path","path",
                   "mud","dirt","line","hallway","castle","structure" }) :
                   (: GetLong :),
                ({ "west wall bench","bench","west wall","wall",
                   "tree stumps","tree","stump","tree stump","stumps",
                   "leftover board","board" }) :
                   "The bench is basically a leftover board, but set "
                   "up on two tree stumps that are basically the same "
                   "hieght, turning it into a place to sit.",
           ]) );
   SetExits( ([
                "north" : VC_ROOM + "/gen_01",
                "east"  : VC_ROOM + "/dining",
                "south" : VC_ROOM + "/hall2",
           ]) );
   SetInventory( ([
                    VC_NPC + "/slave_f" : 1,
                    VC_NPC + "/slave_m" : random(2),
               ]) );
}
