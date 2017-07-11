#include <lib.h>
#include "parva.h"
inherit LIB_ROOM;

static void create() {
   room::create();
   SetTown("Parva");
   SetDomain("HavenWood");
   SetShort("a necromancer's hut");
   SetLong("Skeletons in a variety of states sit around the "
           "room.  Other strange objects clutter all "
           "available space, except on the floor of "
           "this necromancer's hut.  A doorway leads out "
           "on the north side.");
   SetItems( ([
                ({ "necromancers hut","hut" }) :
                   (: GetLong :),
                ({ "Parvan skeletons","skeleton","skeletons",
                   "bodies","body" }) :
                   "The skeletons are really an assortment "
                   "of bodies from dead Parvans that the "
                   "local necromancer must have gathered "
                   "from the cemetery.",
                ({ "strange objects","objects","object" }) :
                   "The objects are not easily "
                   "recognizable.  They are probably "
                   "used by the necromancer in his "
                   "magic.",
                ({ "clean floor","floor" }) :
                   "The floor is kept immaculately clean.",
                ({ "north doorway","door","doorway" }) :
                   "A doorway leads out on the north "
                   "side of the hut.  It is the "
                   "only exit.",
           ]) );
   SetItemAdjectives( ([
                          "hut" : ({ "necromancer","necromancers",
                                     "necromancy" }),
                          "skeletons" : ({ "parvan" }),
                          "objects" : ({ "strange" }),
                          "floor" : ({ "clean" }),
                          "door" : ({ "north" }),
                     ]) );
   SetSmell( ([
                "default" : "Rot and decay fill the air.",
           ]) );
   SetExits( ([
                "out" : P_ROOM + "/cemetery",
           ]) );
   SetInventory( ([
               ]) );
}
