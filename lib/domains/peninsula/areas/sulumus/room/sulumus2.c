// Proximo@Via Imperialis
// 05/29/2003

#include <lib.h>
#include "../sulumus.h"

inherit LIB_ROOM;

int CheckPeople();

static void create() {
  room::create();
  SetClimate("temperate");
/*
  SetDomain("mountain");
*/
  SetShort("The center of the Sulumus Trading Post");
  SetLong(
     "Passing through the main gate, the road leads into a small trading post "
     "known as the Sulumus Trading Post. This road branches off into many "
     "directions from here, leading to everywhere within the trading post walls. "
     "Far off into the distance to the northeast can be seen the mountains standing "
     "high into the sky. A large canvas tent can be seen sitting within the "
     "center of the trading post here. "
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
     S_NPC + "torchmerchant" : 1,
     S_NPC + "random_guard" : 1,
     S_OBJ + "poster" : 1,
     S_NPC + "standing_guard" : 1,
  ]) );
  SetEnters( ([
  ]) );
  AddEnter("tent", S_ROOM + "warlord_tent", (: CheckPeople :));
  SetSmell( ([
     "default" : "The fresh air is mixed with the faint smell of burning wood. ",
  ]) );
  SetListen( ([
     "default" : "The occasional sounds of voices and trading carts is heard. ",
  ]) );
  SetExits( ([
     "east" : S_ROOM + "sulumus1",
     "northeast" : S_ROOM + "sulumus4",
     "north" : S_ROOM + "sulumus5",
     "northwest" : S_ROOM + "sulumus6",
     "west" : S_ROOM + "sulumus3",
     "southeast" : S_ROOM + "sulumus7",
     "south" : S_ROOM + "sulumus8",
     "southwest" : S_ROOM + "sulumus9",
  ]) );
}

int CheckPeople() {
  object who = this_player();
  object guard = present("enforcer", this_object());

  if(creatorp(who)) return 1;
  if(!guard) return 1;
  if(this_player()==guard) return 1;
  if(guard->GetParalyzed()) return 1;
  if(who->GetInvis()) return 1;
  if(!living(guard)) return 1; 
  message("", who->GetName() + " tries to enter the tent. ",
     this_object());
  guard->eventForce("say You aren't allowed in there, scum!");
  return 0;
}
