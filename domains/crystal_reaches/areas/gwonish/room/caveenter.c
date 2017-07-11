#include <lib.h>
#include <climb.h>
#include "../path.h"

inherit LIB_ROOM;
int dugOut;


int CheckHole(string dir);

static void create()
{
  dugOut = 0;
  room::create();
  SetClimate("outdoors");
  SetShort("cave opening");
  SetLong( "Cool air breathes from the opening of the tiny hole at "
           "the base of the cliff." );

  SetItems((["nul_cliff" : "Stretching nearly 150 feet into the air the cliff"
                         "dominates the small clearing at it's base.  Roots "
                         "stick out from it's face creating hand and "
                         "footholds at regular intervals all the way down.  "
                         "At the very bottom of the cliff, amidst a few large "
                         "rocks, a hole can be seen leading back into the "
                         "cliff.",
             ({"root","roots","handholds","footholds","handhold","foothold"}) :

                     "The roots stick out from the cliff face creating neat "
                     "hand and footholds in their regularity.",
               ({"rock","rocks"}) : "Chunks of rock distributed along the "
                     "base of the cliff contain many crevices.  One of the "
                     "holes looks like it might lead back into the actual "
                     "face of the cliff.",
               "hole" : "The hole does not go back into the cliff nearly as "
                        "far as it appears too.  In fact the back is filled "
                        "in with dirt, preventing passage further in.",
               "crevices" : "The base of the cliff is riddled with "
                            "crevices."]) );

  SetSmell( ([ "default" : "The rotten smell of the nearby swamp nearly "
                           "overpowers you.",
               ({"cave","hole","crevices"}) : "The musty earth smell of the "
                           "cave is pierced by an acrid odor."]) );
  SetListen( ([ "default" : "It is very quiet, except for the chirping of a "
                            "cricket."]) );
  SetInventory( ([ GWONISH + "room/cliffob2" : 1 ]) );

  //AddEnter("hole", CAVERN + "room/entrance1", (: CheckHole :));

}


int CheckHole(string dir)
{
  if(!dugOut)
  {
    write("There is way too much dirt for you to squeeze into the cave.");
    return 0;
  }
  else return 1;
}

