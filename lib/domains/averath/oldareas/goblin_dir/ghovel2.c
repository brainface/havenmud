#include <lib.h>
#include <domains.h>
inherit LIB_ROOM;

static void create() {
  room::create();

  SetClimate("indoors");
  SetAmbientLight(0);
  SetShort("a dirty hovel");
  SetLong("This small room has been carved out of the hard earth and is "
     "home to a few goblins. The dusty earthen floor is covered with muck "
     "and piles of garbage and bones. The walls are covered with simple "
     "pictures of goblins in lewd acts.");
  SetListen( ([
     "default" : "The scratching noises of small rodents is loud.",
     ]) );
  SetSmell( ([
     "default" : "The stench of garbage and refuse is unbearable.",
     ]) );
  SetItems( ([
     ({"floor","ground"}) : "The dirt floor is covered with piles of "
       "garbage in places as well as large piles of bones in a corner.",
     ({"garbage","pile","piles"}) : "Small heaps of various debris from "
       "the sewer tunnels above have been dragged into this hovel to create "
       "make shift beds for the goblins that live here. The piles are "
       "foul smelling and contain dung as well as bones of small creatures.",
     ({"wall","walls","pictures","picture"}) : "The earth walls of the "
       "hovel covered with crude paintings, hand painted with mud and "
       "other muck from the floor. They display goblins of all sizes in "
       "various positions.",
     ]) );
  SetItemAdjectives( ([
     ]) );
  SetExits( ([
     "out" : AVERATH_UNDERGROUND "3,1,-2",
     ]) );
  SetInventory( ([
     AVERATH_NPC "cyrvrakis" : 1,
     ]) );
}
