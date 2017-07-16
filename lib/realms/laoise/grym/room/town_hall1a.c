#include <lib.h>
#include "../grymxoria.h"
inherit LIB_ROOM;

 
static void create() {
  room::create();
  SetClimate("indoors");
  SetAmbientLight(20);
  SetTown("Grymxoria");
  SetShort("the Town Hall of Grymxoria");
  SetLong(
    "This is the southwestern part of the Grymxoria town "
    "hall. This room is a large waiting room, where people "
    "may sit and await their appointment with the High "
    "Chancellor. There is a set of stone stairs leading up."
  );
  SetItems( ([
    ({ "stair", "stair case" }) : "A staircase of black "
    "stone, leading up."
  ]) );
  SetExits( ([ 
    "out" : G_ROOM + "road15",
    "up" : G_ROOM + "town_hall1b"
  ]) );
}

