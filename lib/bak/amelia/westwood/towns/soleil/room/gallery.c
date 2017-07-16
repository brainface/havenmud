#include <lib.h>
#include "../soleil.h"
inherit LIB_ROOM;

static void create() {
   room::create();
   SetTown("Soleil");
   SetDomain("WestWood");
   SetClimate("indoors");
   SetAmbientLight(48);
   SetShort("an art gallery");
   SetLong("Beautiful paintings are displayed on the walls "
           "of this well-lit room.  They are very colorful. "
           "A soft bench is in the middle of the room, perfect "
           "for sitting at an observing any of the pictures.  "
           "A door leads out in the east wall.");
   SetItems( ([
                ({ "art gallery","gallery","room" }) :
                   (: GetLong :),
                ({ "beautiful paintings","paintings","painting",
                   "walls","wall","pictures","picture" }) :
                   "The paintings on the walls are all colorful "
                   "and rather realistic.  One exhibits a "
                   "deep blue lake with Eclatish clerics around "
                   "it, some crying and some laughing, but all "
                   "good.  Another shows a scene in the middle "
                   "of a meadow; the lone tree has a clumsy "
                   "treehouse teaming with gelfling, halfling, "
                   "and muezzin children.  The final painting "
                   "is of a festival, with gelflings and halflings "
                   "and muezzin of all ages dancing together and "
                   "playing music on brightly decorated instruments.  "
                   "The paintings were all carefully framed and "
                   "hung evenly.  There is one on each of the "
                   "walls except for the east one.",
                ({ "soft bench","bench" }) :
                   "The comfortable bench is a soft brown color. "
                   "It has no back, and could be sat on facing "
                   "any direction; it easily allows one to sit and "
                   "view the paintings.",
                ({ "east door","door","wall" }) :
                   "The east door leads out of the gallery; it is the "
                   "only exit.  The east wall is the only wall "
                   "without a painting; most likely this is because "
                   "of the door.",
           ]) );
   SetItemAdjectives( ([
                         "gallery" : ({ "art","well-lit" }),
                         "paintings" : ({ "beautiful","colorful" }),
                         "bench" : ({ "soft","comfortable" }),
                         "door" : ({ "east" }),
                    ]) );
   SetSmell( ([
                "default" : "The room smells clean and pure, but "
                   "slightly dusty.",
           ]) );
   SetListen( ([
                 "default" : "The room is quiet, save a few whispers.",
            ]) );
   SetExits( ([
                "out" : S_ROOM + "tree_c",
           ]) );
   SetInventory( ([
                    S_NPC + "trainer_cleric" : 1,
               ]) );
}