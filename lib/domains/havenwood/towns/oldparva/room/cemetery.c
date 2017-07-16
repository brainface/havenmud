#include <lib.h>
#include "parva.h"
inherit LIB_ROOM;

static void create() {
   room::create();
   SetTown("Parva");
   SetShort("Parva Cemetery");
   SetDomain("HavenWood");
   SetLong("Shallow graves for the dead of Parva were dug around "
           "the tree stumps left from cutting down part of the "
           "Havenwood to build houses.  The Havenwood is just "
           "south of here; Parva is to the north, accessible "
           "by a small path running between the buildings.");
   SetItems( ([
                ({ "Parva Cemetery","cemetery","parva","town" }) :
                   (: GetLong :),
                ({ "shallow graves","graves","grave" }) :
                   "The people of Parva don't spend much time "
                   "on their dead; around the shallow graves are "
                   "signs of simple cremation ceremonies in "
                   "which all the corpses lying nearly above "
                   "ground were burned.",
                ({ "tree stumps","stumps","stump" }) :
                   "Tree stumps stick out of the ground at various "
                   "angles, their roots poking out around them.",
                ({ "tree roots","roots","root" }) :
                   "The roots sticks out of the ground near the "
                   "stumps.  Most are still attached to stumps, "
                   "and are brown and dirty.",
                ({ "Havenwood","forest","woods","wood","havenwood" }) :
                   "The Havenwood is south of here.  The tree stumps "
                   "used to help hold up trees that were part of "
                   "the Havenwood, but no more.",
                ({ "small path","path" }) :
                   "The path leads north into town.  It is dusty "
                   "and dry.",
                ({ "ramshackle buildings","buildings","building" }) :
                   "The buildings to the north were made from the "
                   "trees that used to be on the stumps here.  "
                   "They were meant to be temporary, but most have "
                   "remained unchanged.",
           ]) );
   SetItemAdjectives( ([
                         "cemetery" : ({ "parva","town" }),
                         "graves" : ({ "shallow" }),
                         "stumps" : ({ "tree" }),
                         "roots" : ({ "tree","stump" }),
                         "woods" : ({ "haven" }),
                         "path" : ({ "small" }),
                         "buildings" : ({ "ramshackle" }),
                    ]) );
   SetSmell( ([
                "default" : "Smells of rotting rise from the "
                   "shallow graves.",
           ]) );
   SetListen( ([
                 "default" : "The town makes noises north of "
                    "here.",
                 "town" : "The noises are coming from the town "
                    "north of here.  It sounds like people.",
            ]) );
   SetExits( ([
                "north" : P_ROOM + "/cpath",
           ]) );
}
