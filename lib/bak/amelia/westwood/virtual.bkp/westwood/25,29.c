#include <lib.h>
#include "../westwood.h"
inherit LIB_ROOM;

static void create(int x, int y) 
{
  ::create(25, 29);
  SetShort("an elegant waterfall");
  SetLong("A waterfall cascades down the mountains that border the "
    "WestWood creating the beginning of a river.  As it splashes "
    "down it creates a fine mist that covers everything in a delicate "
    "layer of water.  Rumors exist that waterfalls of this "
    "magnifigance are put here to hide a darker secret, sometimes "
    "caves behind them where dark things lurk.  The waterfall creates "
    "small waves that lap along shore.  The forest here is dark and "
    "gloomy, shading over the river and magnifing the darkness here.  "
    "Set apart from the darkness in a small patch of light, an inn "
    "sits here.  A sign above the door labels it as the 'Happy Hunting "
    "Grounds.'");
  SetItems( ([
    ({ "waterfall" }) : "The waterfall is magnifigant as it splashes "
      "down the mountains, meeting the small pool of water and "
      "creating a small river.  Behind the waterfall, their appears "
      "to be some spots that are darker than the mountain is.",
    ({ "trees","tree","forest" }) : "The fenfir trees here are are "
      "shaded darkly amongst the mountains.  They still stand tall, "
      "as though trying to rise above this dark area.",
    ({ "river","wave","waves","shore" }) : "The river here is choppy "
      "from the waterfall splashing down and creating waves along the "
      "shore.  It is not very large, but one could not clear it easily.",
    ({ "mountain","mountains" }) : "The mountains here are tall and "
      "with a white snow.  They are made of solid rock and shale.  "
      "caverns are known to exist in mountains such as this.",
    ({ "mist" }) : "A fine mist is created as the waterfall touches "
      "down into the small pool at the base of the mountains, covering "
      "everything in fine layers of water.",
    ({ "cave","caves" }) : "Behing the waterfall, there appears to be "
      "a cave.",
    ({ "fish" }) : "Fish do not normally spawn this close to a waterfall.",
    ({ "thing","things" }) : "Dark things are known to hide behind "
      "waterfalls such as this.",
    ({ "darkness" }) : "The forest closes in on this area and the "
      "mountains shade the area, creating a dark appearance in this "
      "inside this forest.",
    ({ "inn" }) : "The inn is a small building designed to blend in "
      "with the natural architecture of the forest.  It is a light "
      "shade of green that mirrors the fenfir trees.  A sign above "
      "the door labels it as the 'Happy Hunting Grounds.'",
  ]) );
  SetItemAdjectives( ([
    "mist" : "fine",
    "waterfall" : ({ "magnifigant" }),
    "thing" : "dark",
    "wave" : "small",
    "forest" : ({ "dark","gloomy" }),
  ]) );
  SetListen( ([
    "default" : "The waterfall creates an almost deafening roar here, with "
      "slight sounds of water echoing.",
  ]) );
  SetSmell( ([
    "default" : "The air here smells clean and fresh.",
  ]) );
  SetObviousExits("southwest, south, southeast");
  SetExits( ([
    "southwest" : V_ROOM + "24,28",
    "south" : V_ROOM + "25,28",
    "southeast" : V_ROOM + "26,28",
  ]) );
   SetEnters( ([
      "waterfall" : C_ROOM + "cave1",
      "cave" : C_ROOM + "cave1",
      "inn" : V_ROOM + "p_inn",
   ]) );
}
