// Monastery
// Aerelus
// 06/05/2006

#include <lib.h>
#include <domains.h>
#include "../monastery.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetAmbientLight(30);
  SetClimate("indoors");
  SetShort("inside the belfry");
  SetLong(
    "The belfry is a tall building that houses a bell at the top. The floor "
    "is covered with a thick layer of sand. There is a stone staircase that "
    "leads up to the bell here. There should have been a rope here for "
    "operating the bell, but it seems someone has stolen it. The monastery "
    "courtyard can be seen outside. "
  );
  SetItems( ([
  ({ "belfry", "building" }) : (: GetLong :),
  ({ "bell" }) :
    "The bell is located up the staircase.",
  ({ "staircase" }) :
    "The stone staircase leads up to the bell. ",
  ({ "floor", "sand", "layer" }) :
    "The floor is covered in sand.",
  ({ "courtyard" }) :
    "The courtyard lies outside the belfry.",
  ]) );
  SetItemAdjectives( ([
    "staircase" : ({ "stone" }),
    "sand" : ({ "thick" }),
    "courtyard" : ({ "monastery" }),
    "building" : ({ "tall" }),
    "layer" : ({ "thick" }),
  ]) );
  SetInventory( ([
      AREA_NPC "bat" : 2,
  ]) );
  SetListen( ([
    "default" : "The sounds of deep chanting can be heard.",
  ]) );
  SetSmell( ([
    "default" : "The belfry smells a little damp. ",
  ]) );
  SetExits( ([
    "out" : AREA_ROOM "courtyard",
    "up" : AREA_ROOM "bell_room",
  ]) );
}
