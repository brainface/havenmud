#include <lib.h>
#include <domains.h>
inherit LIB_ROOM;

static void create() {
  room::create();

  SetClimate("indoors");
  SetAmbientLight(0);
  SetShort("a small hovel");
  SetLong("This small dirty hovel is carved out of the earth and stone "
     "that makes up the sewer tunnels. The floor is covered with muck "
     "that has been tracked in and garbage lays in piles on the floor. "
     "The walls are covered with crude pictures and carvings of goblins "
     "in various acts.");
  SetItems( ([
     ({"earth","stone"}) : "This hovel has been carved out of the dark "
       "hard stones that make up the sewer tunnels and the earth that lies "
       "beyond it. Small pieces of rock litter the earthen floor.",
     ({"tunnels","sewer tunnels","tunnel"}) : "The murky damp tunnels "
       "of the sewer lie beyond a small hole on the northern wall.",
     ({"floor","ground"}) : "The dirt floor is covered with piles of "
       "garbage in places as well as a dark muck that has been tracked in "
       "from the tunnels.",
     ({"garbage","pile","piles"}) : "Small heaps of various debris from "
       "the main sewer tunnels have been dragged into this hovel to create "
       "make shift beds for the goblins that live here. The piles are "
       "foul smelling and contain dung as well as bones of small creatures.",
     ({"wall","walls","pictures","picture","carvings","carving"}) : "The "
       "earth walls of the hovel are covered with crude paintings, hand "
       "painted with mud and other muck from the floor, while the engravings "
       "were carved with bones or some sort of crude knife. Both display "
       "goblins of all sizes engaged in lewd acts.",
     ]) );
  SetItemAdjectives( ([
     "stone" : ({"hard","dark"}),
     "floor" : ({"dirt"}),
     "picture" : ({"crude"}),
     ]) );
  SetExits( ([
     "out" : AVERATH_UNDERGROUND "-1,0,-2",
     ]) );
  SetInventory( ([
     AVERATH_NPC "goblin" : 2,
     ]) );
}
