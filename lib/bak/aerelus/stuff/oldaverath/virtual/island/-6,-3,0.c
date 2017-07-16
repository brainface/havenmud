/* tunnel1.c */

#include <lib.h>
#include <domains.h>
#include "../glim.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetAmbientLight(45);
  SetClimate("underground");
  SetShort("a narrow tunnel");
  SetLong("This is the beginning of the Glistendin tunnels.  "
    "The tunnels cut directly into the mountain's "
    "base. From here it is quite obvious that, unlike other "
    "cultures that build their cities and towns upwards, towards "
    "the heavens, the dwarves build deeper and cut deeper into "
    "the mountain as their cities expand. The great mithril gates of "
    "Glistendin stand here in all their strength and durability.  "
    "They are the first defense Glistendin has against invaders "
    "of any kind, and they are of incredible strength. They were "
    "made in the heart of the dwarven forges and are probably "
    "the oldest and longest lasting feature in the entire town.");
  SetItems( ([
    ({"beginning", "tunnel", "tunnels"}) :
      "This is the beginning of the tunnels that lead to Glistendin.",
    ({"gate", "gates"}) :
      "The great mithril gates of Glistendin stand here.",
    ({"torch", "torches"}) :
      "Torches give the area a dim, flickering light.",
  ]) );
 
  SetItemAdjectives( ([
    "beginning" : ({"steep"}),
    "gate"  : ({"great", "mithril"}),
    "torch" : ({"dim", "flickering"})
  ]) );
   SetInventory( ([
    ]) );
  SetExits( ([
    "west"  : AVERATH_ISLAND + "-7,-3,0",
    "south" : AVERATH_ISLAND + "-6,-4,0",
  ]) );

  SetSmell( ([
    "default" : "Fresh air from the outdoors flows in.",
  ]) );

  SetListen( ([
    "default" : "Movement some distance away occasionally breaks the silence.",
   ]) );
}
 
