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
    "This is the northeastern part of the Temple of the Dark "
    "Goddess. It is a bare stone room, where visitors "
    "can sit and contemplate their impurity before entering "
    "the actual church building. In the corner of the room "
    "is a stone stair case leading up."
  );
  SetItems( ([
    "stone" : "Blocks of crudely shaped black stone.",
    ({ "stair", "stair case" }) : "A stair case of "
    "black stone, leading up."
  ]) );
  SetListen( ([
    "default" : "Every thing is completely silent."
  ]) );
  SetExits( ([ 
    "out" : G_ROOM + "road17",
          "up" : G_ROOM + "church3b"
  ]) );
}

