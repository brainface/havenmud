// Items fixed up, ItemAdjs added - Laoise

#include <lib.h>
#include "../grymxoria.h"
inherit LIB_ROOM;


static void create() {
  room::create();
  SetAmbientLight(20);
  SetTown("Grymxoria");
  SetShort("crusade court");
  SetLong(
    "The heart of the city's Merchant Quarter. "
    "Crusade court, named after the event in Nosferatu history, "
    "extends off to the east and west. To the south is a medium "
    "sized stone building with a sign over the door bearing a "
    "picture of a anvil and a sword."
  );
  SetExits( ([ 
    "west" : G_ROOM + "road24",
    "east" : G_ROOM + "road26" 
  ]) );
  SetItems( ([
    ({ "smithy", "shop", "store", "building", "blacksmith" }) :
    "A medium sized stone building with a sign over the door "
    "bearing a picture of a anvil and a sword. Under the "
    "picture the sign notes that this is Jubbal's Smithy" 
  ]) );
  SetItemAdjectives( ([
    "shop" : ({ "blacksmith", "medium", "sized", "stone", "south", "smith" }),
  ]) );
  SetEnters(  ([
    ({"building", "smithy", "store", "shop" }) :
    G_ROOM + "/black_smith",
  ])  );
}

