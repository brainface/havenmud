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
  SetShort("a dirt path outside the Sulumus Trading Post");
  SetLong(
     "This small beaten path represents the link between the Via Imperialis and "
     "the Sulumus Trading Post. Deep ruts have been dug into the road, likely "
     "the cause of wheels from carts trafficing their goods to and from the "
     "Sulumus Trading Post. A patch of briar bushes line the path on either side, "
     "preventing anyone from traveling in those directions. Far off in the "
     "distance to the northeast can be seen the mountains standing high into the "
     "sky. "
  );
  SetItems( ([
     ({"path","road","ruts"}) : "This small beaten path runs from the "
     "Sulumus Trading Post and connects with the Via Imperialis. Deep ruts have "
     "been formed in the road, likely caused by the wheels from carts trafficing "
     "their goods to and from the Sulumus Trading Post. ",
     ({"bush","bushes"}) : "Patches of thick briar bushes run alongside each "
     "side of the road here, preventing anyone from traveling in those directions. ",
     ({"mountains"}) : "Far off in the distance to the northeast can be seen "
     "the mountains standing high into the sky. ",
  ]) );
  SetItemAdjectives( ([
  ]) );
  SetInventory( ([
  ]) );
  SetEnters( ([
  ]) );
  SetSmell( ([
     "default" : "The fresh air stimulates the senses. ",
  ]) );
  SetListen( ([
     "default" : "The gentle sounds of nature can be heard in all directions. ",
  ]) );
  SetExits( ([
     "east" : "/domains/peninsula/virtual/vimp/0,6",
     "west" : S_ROOM + "sulumus1",
  ]) );
}
