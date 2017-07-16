#include <lib.h>
#include "../camp.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("indoors");
  SetInventory( ([
    CAMP_NPC + "leader" : 1,
    ]) );
  SetAmbientLight(45);
  SetShort("inside the large tent");
  SetLong("This huge tent is obviously occupied by someone important in "
          "the ronin hierarchy. The tent is made of much finer quality "
          "than the other tents in the camp. Scattered around the tent "
          "are several important looking papers which seem to lay about "
         "in a haphazard fashion. Off to one side of the room is an area "
         "which serves as personal quarters.");
  SetItems( ([
   ({ "paper", "papers" }) : "These seem to be the day to day business "
                             "of the ronin.",
   ({ "wall", "walls" }) : "These are made of a much sturdier cloth than "
                          "those of the other tents.",
    ]) );
  SetExits( ([
      "out" : CAMP_ROOM + "cl6",
     ]) );
}
