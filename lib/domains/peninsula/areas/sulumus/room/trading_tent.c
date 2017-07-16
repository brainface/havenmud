// Proximo@Via Imperialis
// 05/29/2003

#include <lib.h>
#include "../sulumus.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("indoors");
  SetWarmth(35);
/*
  SetDomain("mountains");
*/
  SetAmbientLight(30);
  SetShort("inside the Trading Tent");
  SetLong(
     "This very large canvas tent is where much of the trading is done within "
     "the Sulumus Trading Post. The thick material that makes up this tent "
     "blocks much of the outside world, despite it's lack of a regal "
     "appearance. A few tables have been set up along the walls of the tent, "
     "displaying the many different items that are here to be sold to any who "
     "wish to purchase it. A large fire roars in the center of the tent, "
     "spouting flames and smoke straight up into the small hole in the roof. "
  );
  SetItems( ([
     ({"tent","canvas"}) :
     "The material that this tent is composed of is that of tightly-wrapped canvas "
     "stretched over a wooden frame. This allows for a weather proof structure, "
     "able to withstand many types of weather. ",
     ({"table","tables","items"}) :
     "A few tables have been set up along the walls of the tent, displaying "
     "many different items for sale on display. ",
     ({"fire","hole"}) :
     "A large fire burns brightly in the center of the tent, generating a fair "
     "amount of heat and light for those near its reach. A plume of smoke "
     "from the fire leads straight up into the air and out through the small hole "
     "in the roof. ",
  ]) );
  SetItemAdjectives( ([
  ]) );
  SetInventory( ([
     S_NPC + "merrik" : 1,
  ]) );
  SetEnters( ([
  ]) );
  SetSmell( ([
     "default" : "The air smells of a sweet smelling smoke. ",
  ]) );
  SetListen( ([
     "default" : "It is rather busy and loud in here. ",
  ]) );
  SetExits( ([
     "out" : S_ROOM + "sulumus3",
  ]) );
}
