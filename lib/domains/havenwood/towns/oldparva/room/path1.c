#include <lib.h>
#define DAWORLD "/domains/havenwood/virtual/parvaroad/15,0"
#include "parva.h"
inherit LIB_ROOM;

int PreExit();

static void create() {
   room::create();
   SetTown("Parva");
   SetDomain("HavenWood");
   SetShort("in Parva");
   SetLong("Dust hangs airily around the ramshackle buildings "
           "of Parva.  The edge of the Havenwood is to the south, "
           "and tree stumps are visible in that direction.  The "
           "shacks are make-shift; their only purpose is to "
           "keep out the basic elements and enclose the "
           "stores and businesses of the land.  The path through "
           "town goes east and west.  The town continues to "
           "the east, while the open land is to the west.");
   SetItems( ([
                ({ "Parva","parva","town" }) :
                   (: GetLong :),
                ({ "hanging dust","dust" }) :
                   "Dust hangs in the air, light reflecting off of "
                   "it, obscuring the view.",
                ({ "ramshackle buildings","buildings","building",
                   "shack","shacks" }) :
                   "The buildings slowly disintegrate in the dry "
                   "dust of Parva.  The humans build the shacks "
                   "as temporary dwellings; they have remained "
                   "since the forming of this ferry-town.",
                ({ "Havenwood","havenwood","woods","wood" }) :
                   "The Havenwood is south of Parva; Parva "
                   "sits at its edge.  Humans cut down the "
                   "Havenwood trees nearest them to build the "
                   "shacks.",
                ({ "tree stumps","stump","stumps" }) :
                   "Some old, some new, the tree stumps "
                   "south of here represent the destruction "
                   "all towns are built upon:  The humans "
                   "who came here to build Parva cut down "
                   "many trees for ferries and shacks.  More "
                   "are cut down daily to build more ferries and "
                   "improve the shacks.",
                ({ "town path","path" }) :
                   "The two buildings to either side of the path "
                   "define where it is; the other buildings of "
                   "Parva keep to a general straight line, as "
                   "well.",
                ({ "town hall","hall","townhall" }) :
                   "The town hall is on the south side of the "
                   "path.  An open gap in the front of it "
                   "allows access.",
                ({ "Parva Bank","bank","parva bank" }) :
                   "The Parva Bank is north of the path.  "
                   "An open gap in the front of it allows "
                   "access.",
           ]) );
   SetItemAdjectives( ([
                         "buildings" : ({ "ramshackle" }),
                         "stumps" : ({ "tree" }),
                    ]) );
   SetSmell( ([
                "default" : "The dust dampens out the other smells.",
           ]) );
   SetListen( ([
                 "default" : "Gentle waves crash into the land to "
                     "the east.",
            ]) );
   SetExits( ([
                "east" : P_ROOM + "/path2",
           ]) );
   AddExit("west", DAWORLD, (: PreExit :));
   SetEnters( ([
                 "townhall" : P_ROOM + "/th",
                 "bank" : P_ROOM + "/bank",
            ]) );
   SetInventory( ([
                     P_NPC + "/cit" : 2,
                     P_OBJ + "/sign1" : 1,
                     P_NPC + "/cit_steal" : 1,
               ]) );
}

int PreExit() {
   if(this_player()->GetProperty("parvanoleave")) return 0;
   else return 1;
}
