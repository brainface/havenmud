#include <lib.h>
#include "../grymxoria.h"
inherit LIB_ROOM;

 
static void create() {
  room::create();
  SetNewsgroups( ({ "town.grymxoria" }) );
  SetProperty("no attack",1);
  SetProperty("no bump",1);
  SetClimate("indoors");
 SetProperty("no magic", 1);
  SetAmbientLight(20);
  SetTown("Grymxoria");
  SetShort("the Town Hall of Grymxoria");
  SetLong(
    "This is an public meeting room in the eastern wing of the "
    "Grymxoria town hall. It is a large open room with a large "
    "fire place at one end, and several large tables with chairs "
    "scattered around. At the back of the room is a large bulletin "
    "board for general town posting."
  );
  SetItems( ([
    ({ "fire place" }) : "A large stone fire place with a good size fire "
    "in it.",
    ({ "tables" }) : "Large rectangular wooden tables scattered about the "
    "room",
    ({ "chairs" }) : "Wooden chairs scattered about the room and around "
    "tables." 
  ]) );
  SetInventory( ([
	G_OBJ + "poster" : 1,
  ]) );
  SetExits( ([ 
    "north" : G_ROOM + "church3b",
    "west" : G_ROOM + "town_hall2b",
    "down" : G_ROOM + "town_hall2a" 
  ]) );
  }
