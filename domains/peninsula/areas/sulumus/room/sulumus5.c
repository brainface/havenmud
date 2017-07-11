// Proximo@Via Imperialis
// 05/29/2003

#include <lib.h>
#include "../sulumus.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("temperate");
/*
  SetDomain("mountains");
*/
  SetShort("Along the wall of the Sulumus Trading Post");
  SetLong(
     "Passing through the main gate, the road leads into a small trading post "
     "known as the Sulumus Trading Post. This road branches off into many "
     "directions from here, leading to everywhere within the trading post walls. "
     "Far off into the distance to the northeast can be seen the mountains standing "
     "high into the sky. A large canvas tent with a sign hanging from the "
     "entrance is seen directly to the north. "
  );
  SetItems( ([
     ({ "gate" }) : "The trading post gate leads into the Sulumus Trading Post. "
     "This gate was crafted from large tree trunks, wrapped together with hardened "
     "clay and vines to assist in keeping these large pieces of wood held together. ",
     ({ "walls" }) : "The outer walls of the trading post surround this "
     "little piece of civilization in every direction, warding off wild animals "
     "and invaders. These walls look to have been made from large tree trunks, "
     "stood upright from the ground, and the top edges sharped to a lethal point. ",
     ({ "tent" }) : "A large canvas tent is seen directly to the north. A "
     "small sign reading \"The Currency Exchange Tent\" hangs outside the entrance. ",
  ]) );
  SetItemAdjectives( ([
     "gate" : ({ "trading","post" }),
     "walls" : ({ "trading","post" }),
     "tent" : ({ "large","canvas" }),
  ]) );
  SetInventory( ([
     S_NPC + "travelfarmer" : 1,
  ]) );
  SetEnters( ([
     "tent" : S_ROOM + "currency_tent",
  ]) );
  SetSmell( ([
     "default" : "The fresh air is mixed with the faint smell of burning wood. ",
  ]) );
  SetListen( ([
     "default" : "The occasional sounds of voices and trading carts is heard. ",
  ]) );
  SetExits( ([
     "west" : S_ROOM + "sulumus6",
     "southwest" : S_ROOM + "sulumus3",
     "south" : S_ROOM + "sulumus2",
     "southeast" : S_ROOM + "sulumus1",
     "east" : S_ROOM + "sulumus4",
  ]) );
}
