#include <lib.h>
inherit LIB_ROOM;
#include "../hiker.h"

static void create() {
   room::create();
   SetClimate("indoors");
   SetAmbientLight(35);
   SetShort("inside a cabin");
   SetLong("The cabin is divided into three general areas based on "
           "what things are done there.  In the kitchen area, there "
           "are some wooden cabinets and a counter near an iron "
           "stove.  Near the kitchen is a table for dining on and "
           "everything else.  Beyond that, lining the walls, are bunk " 
           "beds that form the sleeping area of the cabin.  A door "
           "leads out, and behind the stove is a ladder going up.");
   SetItems( ([
                ({ "wooden walls","wooden wall","wall","walls",
                   "north wall","west wall","east wall","south wall" }) :
                   "The walls provide the structure and boundary to the "
                   "cabin, but all serve other purposes, as well.  "
                   "The east wall hold the ladder in place and many "
                   "cabinets are on it, as well as the south wall, "
                   "which has the door out in it.  The west wall "
                   "has one of the three bunks attached to it; the "
                   "rest are held up by the north one.",
                ({ "log cabin","cabin","log","logs" }) :
                   (: GetLong :),
                ({ "kitchen area","area" }) :
                   "The kitchen area is obviously used a lot; its "
                   "counter is scratched up and the cabinets have the "
                   "marks of being shut and opening and spilled on many "
                   "times.  The stove is also old and well-used.",
                ({ "scratched counter","counter","plain wood","wood" }) :
                   "The counter is made of plain wood that was smooth "
                   "at one point in time, but the liberal use of "
                   "knives on it to cut up food has worn it down.  "
                   "It is on top of half the counters, with the other "
                   "half hanging somewhere above it.  The counter "
                   "fits snuggly where the east and south walls meet.",
                ({ "wooden cabinets","wooden cabinet","cabinets",
                   "cabinet","wood" }) :
                   "The cabinets are set up above and below the "
                   "scratched counter.  They are made of wood, and "
                   "are blocky and square.",
                ({ "iron stove","stove","squat little iron thing",
                   "squat thing","squat little thing","squat iron thing",
                   "little thing","little iron thing","iron thing",
                   "thing" }) :
                   "The stove is a squat little iron thing that could " 
                   "be used for cooking.",
                ({ "dining area","area" }) :
                   "A wooden table is in the dining area, with four "
                   "matching chairs around it.",
                ({ "wooden table","table" }) :
                   "The table is rectangular, with a slight tilt to it "
                   "that makes it a little less than ideal.  There are "
                   "four chairs around it, one to each side.",
                ({ "matching chairs","matching chair","chair","chairs" }) :
                   "The chairs are all exactly the same, aside from " 
                   "slightly different damages done to each.  All are "
                   "wooden and have a basic, clunky chair structure to "
                   "them, and all have seen better days in their life.  "
                   "They are pretty worn.",
                ({ "sleeping area","area" }) :
                   "There are a total of three bunk beds against the "
                   "walls, with a plain mattress for each.  They are "
                   "well spaced, with two attached to the north wall "
                   "and one up against the west well.",
                ({ "bunk beds","bunk bed","bed","beds" }) :
                   "The beds are designed so that the lower bunk is "
                   "about a foot longer than the upper bunk, allowing "
                   "the person sleeping above to use it as a stepping "
                   "stone.  There are enough mattresses for each bunk "
                   "to have one, too, totalling up to six mattresses.  "
                   "Two bunks beds are spaced out on the north wall, " 
                   "with the third against the west one.",
                ({ "plain mattresses","plain mattress","mattress",
                   "mattresses" }) :
                   "There are a total of six mattresses, one for each of "
                   "the bunk beds, but they are not evenly distributed.  "
                   "A couple of the bunks have two mattresses, and "
                   "two others have none.",
                ({ "wooden ladder","ladder" }) :
                   "The ladder goes up to another area in a stair-step "
                   "manner, heading through a hole in the ceiling.",
                ({ "wooden ceiling","ceiling" }) : 
                   "There is a hole in the ceiling for the ladder to "
                   "go through, but other than that, there is little "
                   "the wooden ceiling.",
                ({ "ladder hole","hole" }) :
                   "A hole exists in the ceiling for the ladder to go "
                   "through.  It is rectangular in shape, and has "
                   "rough edges.",
           ]) );
   SetSmell( ([
                "default" : "The room smells a little smoky.",
           ]) );
   SetExits( ([
                "up"  : H_ROOM + "loft",
                "out" : H_ROOM + "porch",
           ]) );
   SetDoor("out",H_ROOM + "cabin_dr");
   SetInventory( ([
                    H_NPC + "cab_man" : 1,
                    H_NPC + "cab_qu" : 1,
               ]) );
}
