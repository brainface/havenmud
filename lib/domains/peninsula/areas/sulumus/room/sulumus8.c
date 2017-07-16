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
     "high into the sky. A row of small tables are arranged along the wall here. "
  );
  SetItems( ([
     ({ "gate" }) : "The trading post gate leads into the Sulumus Trading Post. "
     "This gate was crafted from large tree trunks, wrapped together with hardened "
     "clay and vines to assist in keeping these large pieces of wood held together. ",
     ({ "walls" }) : "The outer walls of the trading post surround this "
     "little piece of civilization in every direction, warding off wild animals "
     "and invaders. These walls look to have been made from large tree trunks, "
     "stood upright from the ground, and the top edges sharped to a lethal point. ",
     ({ "tables" }) : "A long row of tables lay along parallel to the palisade wall. "
     "A large assortment of different types of fruits, vegetables, and meats are arranged "
     "upon their own tables. ",
  ]) );
  SetItemAdjectives( ([
     "tables" : ({ "row", "of", "small" }),
     "gate" : ({ "trading","post" }),
     "walls" : ({ "trading","post" }),
  ]) );
  SetInventory( ([
     S_NPC + "travelfarmer" : 1,
     S_NPC + "karl" : 1,
  ]) );
  SetEnters( ([
  ]) );
  SetSmell( ([
     "default" : "The fresh air is mixed with the faint smell of burning wood. ",
  ]) );
  SetListen( ([
     "default" : "The occasional sounds of voices and trading carts is heard. ",
  ]) );
  SetExits( ([
     "northeast" : S_ROOM + "sulumus1",
     "north" : S_ROOM + "sulumus2",
     "northwest" : S_ROOM + "sulumus3",
     "west" : S_ROOM + "sulumus9",
     "east" : S_ROOM + "sulumus7",
  ]) );
}
