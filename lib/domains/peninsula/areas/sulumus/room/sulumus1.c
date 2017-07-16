// Proximo@Via Imperialis
// 05/29/2003

#include <lib.h>
#include "../sulumus.h"

inherit LIB_ROOM;

int PreExit();

static void create() {
  room::create();
  SetClimate("temperate");
/*
  SetDomain("mountains");
*/
  SetShort("inside the Gates of the Sulumus Trading Post");
  SetLong(
     "Passing through the main gate, the road leads into a small trading post "
     "known as the Sulumus Trading Post. This road branches off into many "
     "directions from here, leading to everywhere within the trading post walls. "
     "Far off into the distance to the northeast can be seen the mountains standing "
     "high into the sky. A large canvas tent can be seen sitting directly off "
     "from the trading post gate. "
  );
  SetItems( ([
     ({ "gate" }) : "The trading post gate leads into the Sulumus Trading Post. "
     "This gate was crafted from large tree trunks, wrapped together with hardened "
     "clay and vines to assist in keeping these large pieces of wood held together. ",
     ({ "walls" }) : "The outer walls of the trading post surround this "
     "little piece of civilization in every direction, warding off wild animals "
     "and invaders. These walls look to have been made from large tree trunks, "
     "stood upright from the ground, and the top edges sharped to a lethal point. ",
     ({ "tent" }) : "A large canvas tent can be seen sitting directly off "
     "from the trading post gate. ",
  ]) );
  SetItemAdjectives( ([
     "gate" : ({ "trading","post" }),
     "walls" : ({ "trading","post" }),
     "tent" : ({ "large","canvas" }),
  ]) );
  SetInventory( ([
     S_NPC + "travelmerchant" : 1,
     S_NPC + "gdog" : 1,
     S_NPC + "guard2" : 1,
     S_NPC + "guard1" : 1,
     S_OBJ + "sign" : 1,
  ]) );
  SetEnters( ([
     "tent" : S_ROOM + "guard_tent",
  ]) );
  SetSmell( ([
     "default" : "The fresh air is mixed with the faint smell of burning wood. ",
  ]) );
  SetListen( ([
     "default" : "The occasional sounds of voices and trading carts is heard. ",
  ]) );
  SetExits( ([
     "north" : S_ROOM + "sulumus4",
     "northwest" : S_ROOM + "sulumus5",
     "west" : S_ROOM + "sulumus2",
     "southwest" : S_ROOM + "sulumus8",
     "south" : S_ROOM + "sulumus7",
  ]) );
  AddExit("east", S_ROOM + "path", (: PreExit :));
}

int PreExit() {
  if (this_player()->id("we_wander")) return 0;
  return 1;
}
