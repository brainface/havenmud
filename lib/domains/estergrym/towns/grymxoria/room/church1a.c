#include <lib.h>
#include "../grymxoria.h"
inherit LIB_ROOM;

 
static void create() {
  room::create();
  SetClimate("indoors");
  SetAmbientLight(20);
  SetTown("Grymxoria");
  SetShort("the Temple of the Dark Goddess");
  SetLong(
    "This is the northwestern part of the Temple of the "
    "Dark Goddess. It is a bare stone room, where visitors "
    "can sit and contemplate their impurity before entering "
    "the church building proper. In the corner of the room "
    "is a stone staircase leading up."
  );
  SetItems( ([
    ({ "stone" }) : "Blocks of crudely shaped black stone.",
    ({ "stair", "staircase" }) : "A stair case of "
    "black stone, leading upwards."
  ]) );
  SetListen( ([
    "default" : "Every thing is completely silent."
  ]) );
  SetExits( ([ 
    "out" : G_ROOM + "road15",
    "up" : G_ROOM + "church1b"
  ]) );
}


