// Amelia
#include <lib.h>
#include <domains.h>
inherit LIB_ROOM;

static void create() {
   ::create();
   SetClimate("indoors");
   SetAmbientLight(15);
   SetShort("underneath a tree");
   SetLong("Dark roots form a ceiling of this cave, holding "
           "back dirt.  While the entrance is small, the cave "
           "opens out into a cavern about three humans long and "
           "four humans wide, with enough space for a tall man "
           "to stand straight.  Light shines in from the entrance.");
   SetItems( ([
                ({ "cavern","cave" }) : (: GetLong :),
                ({ "tree" }) : "The tree is above.",
                ({ "dark roots","roots","root","dark root",
                   "ceiling" }) :
                   "The apex of the ceiling is where the roots "
                   "gather together at the base of the tree.  "
                   "Wind has hollowed out much of the cave, "
                   "leaving some gaps.",
                ({ "dirt" }) : "Dirt is everywhere.",
                ({ "entrance" }) :
                   "The entrance is between two large roots, facing "
                   "the ocean.",
                ({ "ocean" }) : "The ocean is outside.",
           ]) );
   SetSmell( ([ "default" : "The cave has a musty, fungal scent.",
           ]) );
   SetListen( ([ "default" :"The ocean roars outside.",
            ]) );
   SetExits( ([ "out" : AVERATH_ISLAND + "8,-5,0",
           ]) );
   SetInventory( ([
                    FOREST_NPC + "dryadghost" : 1,
               ]) );
}
