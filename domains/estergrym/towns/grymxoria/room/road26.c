#include <lib.h>
#include "../grymxoria.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("sub-arctic");
  SetAmbientLight(20);
  SetTown("Grymxoria");
  SetShort("intersection of Blood River road and Crusade Court");
  SetLong(
    "The intersection of Blood River road and Crusade "
    "Court. Blood  River road continues to the north and "
    "south, while Crusade Court leads off to the east "
    "and west into Grymxoria's merchants quarter."
  );
  SetExits( ([ 
    "north" : G_ROOM + "road22",
    "south" : G_ROOM + "road30",
    "east" : G_ROOM + "road27",
    "west" : G_ROOM + "road25"
  ]) );
}
