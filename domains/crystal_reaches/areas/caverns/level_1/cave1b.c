/*  Level #1 Cavern #1 - Section #2  */

#include <lib.h>
#include "../caves.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("underground");
  SetAmbientLight(0);
  SetShort("a small cavern");

  SetLong("In this area of the cavern the way that the stalactites have grown "
          "has created a natural habitat for a colony of bats.  Thus the "
          "ceiling looks like one giant writhing mass.  Every now and again a "
          "bat or two will swoop around the cavern to another spot on the "
          "ceiling.  On the ground, a sea of insects covers the guano that is "
          "doubtlessly here underfoot.");

  SetSmell( ([
    "default"  :  "The smell of guano is the highlight of this part of the "
                  "cave, that's for certain.",
  ]) );

  SetListen( ([
    "default"  :  "The dripping of water continues its constant job of "
                  "building the rock formations of the caves.",
  ]) );

  SetExits( ([
    "north"  :  ROOMLV1 + "/cave1c",
    "south"  :  ROOMLV1 + "/cave1a",
  ]) );
  SetObviousExits("north, south");

  SetItems( ([
    ({ "small cavern", "cavern" })  :  (: GetLong :),
    ({ "stalactites", "stalactite", "ceiling", "giant writhing mass",
       "giant mass", "writhing mass", "mass", "bats" })  :
       "Up on the ceiling packed between and on the stalactites hundreds of "
       "bats cover the ceiling as a giant writhing mass.",
    ({ "bat" })  :
       "Some bats fly lazily to a new place on the ceiling every now and "
       "then.",
    ({ "ground", "floor", "insects", "insect", "guano" })  :
       "The ground is covered with a sea of insects that covers the guano "
       "that doubtlessly is underneath the creatures.",
  ]) );

  SetInventory( ([ NPCS + "/bat" : 1, ]) );
}


