#include <lib.h>
#include "../camp.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("indoors");
  SetInventory( ([
      CAMP_NPC + "/leader" : 1,
        ]) );
  SetAmbientLight(45);
  SetShort("inside the large tent");
  SetLong("This huge tent is obviously occupied by someone important in \n"
          "the bandit hierarchy.  The tent is made of much finer quality \n"
          "than the other tents in the camp.  Scattered around the tent \n"
          "are several important looking papers which seem to lay about \n"
         "in a haphazard fashion.  Off to one side of the room is an area \n"
         "which serves as personal quarters.");
  SetItems( ([
   ({ "paper", "papers" }) : "These seem to be the day to day business "
                             "of the bandits.",
   ({ "wall", "walls" }) : "These are made of a much sturdier cloth than "
                          "those of the other tents.",
    ]) );
  SetObviousExits("out");
  SetExits( ([
      "out" : CAMP_ROOM + "/cl6",
     ]) );
 }
