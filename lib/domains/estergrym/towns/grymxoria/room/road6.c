#include <lib.h>
#include "../grymxoria.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("sub-arctic");
  SetAmbientLight(20);
  SetTown("Grymxoria");
  SetShort("intersection of Blood River road and Exile avenue");
  SetLong(
    "The intersection of Blood River road and Exile avenue. "
    "Blood River road continues to the north towards the gate, "
    "and south towards the center of town. Exile avenue leads "
    "off to the east and west into Grymxoria's rogues quarter. "
    "The Blood river flows down the center of the two lane "
    "Blood River road from north to south. To the north is "
    "the Grymxoria city barracks."
  );
  SetItems( ([
    ({ "river", "blood river", "Blood River" }) : "The Blood River "
    "flows down the center of the divided two lane road. "
    "It gets its name from the reddish color of the water from "
    "the large amounts of iron and copper in it."
  ]) );
  SetListen( ([
    "default" : "The river swishes and gurgles eerily."
  ]) );
  SetExits( ([ 
    "north" : G_ROOM + "road2",
    "south" : G_ROOM + "road10",
    "east" : G_ROOM + "road7",
    "west" : G_ROOM + "road5"
  ]) );
}

