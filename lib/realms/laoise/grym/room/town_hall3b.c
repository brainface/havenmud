#include <lib.h>
#include "../grymxoria.h"
inherit LIB_ROOM;

 
static void create() {
  room::create();
  SetTown("Grymxoria");
  SetClimate("indoors");
  SetAmbientLight(20);
  SetProperty("no attack",1);
  SetProperty("no bump",1);
  SetShort("the Town Hall of Grymxoria");
  SetLong(
    "This is an public meeting room in the eastern wing of the "
    "Grymxoria Town Hall. It is a large open room with a large "
    "fireplace at one end, and several large tables with chairs "
    "scattered around. At the back of the room is a large bulletin "
    "board for general town posting."
  );
  SetItems( ([
   ({ "fire", "fireplace" }) : "A large stone fire place with a "
   "good size fire in it.",
   ({ "tables" }) : "Large rectangular wooden tables scattered "
   "about the room",
   ({ "chairs" }) : "Wooden chairs scattered about the room and "
   "around tables." 
  ]) );
  SetExits( ([ 
    "north" : G_ROOM + "church3b",
    "west" : G_ROOM + "town_hall2b",
    "down" : G_ROOM + "town_hall2a" ]) );
  SetInventory( ([
    G_OBJ + "poster" : 1,
  ])  );
  SetNewsgroups( ({ 
    "town.grymxoria" 
  }) );
}
