#include <lib.h>
inherit LIB_ROOM;
#include "ditmar.h"

static void create() {
   room::create();
   SetTown("Ditmar");
   SetClimate("indoors");
   SetAmbientLight(20);
   SetShort("Ditmar General Store");
   SetLong("Stone shelves are set against the walls, and stone chairs "
           "are set around them for further comfort while browsing.  "
           "There are no natural features inside this store, and "
           "it seems like it has been carved out of the rock, rather "
           "than allowed to form naturally.  The exit is to the north.");
   SetItems( ([
                ({ "Ditmar General Store","ditmar general store",
                   "store","ditmar","general store","ditmar store",
                   "cave","rock","stone" }) :
                   (: GetLong :),
                ({ "stone shelves","shelf","shelves" }) :
                   "The shelves are plain, made for utility rather than "
                   "beauty, but appear sturdy and ready to hold "
                   "whatever mind be put upon them.",
                ({ "stone chairs","chairs","chair" }) :
                   "The chairs, like the shelves, are more for use than "
                   "decoration.  Though the store is small, apparently "
                   "citizens of Ditmar prefer resting on stone to "
                   "standing like other people while they look through "
                   "things.",
           ]) );
   SetItemAdjectives( ([
                         "shelves" : ({ "stone" }),
                         "chairs" : ({ "stone" }),
                    ]) );
   SetSmell( ([
                "default" : "The smell is of goods and supplies long "
                   "left in a storeroom and just brought out today to "
                   "be aired out and sold.",
           ]) );
   SetExits( ([
                "north" : D_ROOM + "/cave_b",
           ]) );
   SetInventory( ([
                    D_NPC + "/gs" : 1,
               ]) );
}