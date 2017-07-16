// Amelia
#include <lib.h>
#include <domains.h>
inherit LIB_ROOM;

static void create() {
   ::create();
   SetShort("up a tree");
   SetLong("The trunk of the oak tree stretches up into the sky, "
           "easily as thick as a grown human is tall.  Many branches "
           "provide easy access to the ground below, but above, "
           "few branches are sturdy enough to hold much weight.  "
           "Luxurious moss grows on some of the branches.");
   SetItems( ([
                ({ "oak tree","tree" }) : (: GetLong :),
                ({ "trunk of the oak tree","trunk" }) :
                   "The trunk of the great oak tree is rough and "
                   "hard.  Only a giant could wrap his arms around it "
                   "completely.",
                ({ "branches","branch" }) :
                   "A myriad of thick, sturdy branches can be clambered "
                   "down to reach the forest floor.  However, little can "
                   "be found in the way of branches for climbing further "
                   "up the tree.",
                ({ "luxurious moss","moss" }) :
                   "Thick, luxurious moss carpets the top of many of "
                   "the branches.",
           ]) );
   SetItemAdjectives( ([
                         "trunk" : ({ "oak","tree" }),
                         "moss" : ({ "luxurious" }),
                    ]) );
   SetSmell( ([
                "default" : "A pungent aroma gathers near the tree.",
                "moss" : "The moss possesses a strong antiseptic odor.",
           ]) );
   SetListen( ([
                 "default" : "Wind rustles the branches.",
            ]) );
   SetExits( ([
                "down" : AVERATH_ISLAND + "7,-4,0",
           ]) );
   SetInventory( ([
                    FOREST_NPC + "livedryad" : 1,
                    FOREST_NPC + "olddryad" : 1,
               ]) );
}
