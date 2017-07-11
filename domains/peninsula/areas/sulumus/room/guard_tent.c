// Proximo@Via Imperialis
// 05/29/2003

#include <lib.h>
#include "../sulumus.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("indoors");
/*
  SetDomain("mountains");
*/
  SetAmbientLight(30);
  SetShort("inside the Guard Tent");
  SetLong(
     "This very large canvas tent is where the local guards for the Sulumus "
     "Trading Post operate from. The thick material that makes up "
     "this tent blocks much of the outside world, despite it's lack of "
     "a regal appearance. A large fire roars in the center of the "
     "tent, spouting flames and smoke straight up into the small hole in the roof."
  );
  SetItems( ([
     ({"tent","canvas"}) : 
     "The material that this tent is composed of is that of tightly-wrapped canvas "
     "stretched over a wooden frame. This allows for a weather proof structure, "
     "able to withstand many types of weather. ",
     ({"fire","hole"}) :
     "A large fire burns brightly in the center of the tent, generating a fair "
     "amount of heat and light for those near its reach. A plume of smoke "
     "from the fire leads straight up into the air and out through the small hole "
     "in the roof. ",
  ]) );
  SetItemAdjectives( ([
  ]) );
  SetInventory( ([
     S_NPC + "thulis" : 1,
  ]) );
  SetEnters( ([
  ]) );
  SetSmell( ([
     "default" : "The air smells of a sweet smelling smoke. ",
  ]) );
  SetListen( ([
     "default" : "It is very quiet and calm in here. ",
  ]) );
  SetExits( ([
     "out" : S_ROOM + "sulumus1",
  ]) );
}
