// Amelia
#include <lib.h>
#include <domains.h>
inherit LIB_ROOM;

static void create() {
   ::create();
   SetShort("at the edge of a forest");
   SetLong("Waves crash against the rocky shore.  A sheer sea cliff seperates "
           "the forest from the beach.  A small hillock rises to the north, "
           "speckled with skeletal remains.  The forest continues to the north "
           "and west.");
   SetItems( ([
                ({ "forest" }) : (: GetLong :),
                ({ "rocky shore","shore","ocean","rocks","rock","waves","wave",
                   "sea","beach" }) :
                   "The rocky shore is about five human lengths below.  Repeatedly, "
                   "the ocean throws waves up against the cliffs.",
                ({ "sheer sea cliff","cliff","cliffs", }) :
                   "The cliffs rise about five human lengths from the shore, "
                   "providing no easy route down to the ocean.  A small ledge "
                   "two human lengths downs furnishes a single birch.",
                ({ "small ledge","ledge","outcropping" }) :
                   "A gentle outcropping two human lengths below provides "
                   "purchase for a single birch tree to grow.  The ledge leaves "
                   "the tree open to the harsh elements.",
                ({ "single birch tree","tree","birch" }) :
                   "Stunted and deformed, swift winds have blown the birch tree "
                   "into odd contortions.  It's tiny home on the ledge provides "
                   "no protection and little nurishment.",
                ({ "small hillock","hillock","hill" }) :
                   "An infestation of ivy covers the hill.  Some of the trendils "
                   "dip into a recess in the ground.",
                ({ "ivy infestation","ivy","trendils","trendil" }) :
                   "Soft in color but rich in health, the ivy grows wild.",
                ({ "recess in the ground","recess","ground","cave" }) :
                   "The entrance to an underground cave hides under a patch of "
                   "wild ivy.",
                ({ "skeletal remains","remains","remain","skeletons","skeleton",
                   "bones","bone" }) :
                   "Various skeletons can be picked out of the remains, some "
                   "still decomposing.",
           ]) );
   SetListen( ([
                 "default" : "A steady throm of waves sounds below the cliffs.",
            ]) );
   SetSmell( ([
                "default" : "A mixture of ocean and decay fumes scent the area.",
           ]) );
   SetEnters( ([
                 "cave" : FOREST_ROOMS + "bearcave",
            ]) );
   SetInventory( ([
                    FOREST_NPC + "babybear" : 2,
               ]) );
   SetExits( ([
                "north" : AVERATH_ISLAND + "7,-5,0",
                "west" : AVERATH_ISLAND + "6,-6,0",
           ]) );
}
