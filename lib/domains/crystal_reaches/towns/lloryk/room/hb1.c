#include <lib.h>
#include "../path.h"
inherit LIB_ROOM;


static void create() {
  room::create();
  SetShort("Heroes Lane near the Western Gate");
  SetExits( ([
     "east" : LLORYK + "room/hb2",
     "west" : LLORYK + "room/westgate",
     "south" : LLORYK "room/wharf",
     ]) );
  SetLong("Heroes Lane tapers off here as it approaches the western "
          "gate of the Shire. Off to the east, the road gathers more "
          "width as it approaches the heart of the Shire. The rolling "
          "hills of the Shire stretch out to the north and south, "
          "while the Gwonish swamp begins not too far west."
    );
  SetItems( ([ 
    ({ "gate", }) : "The western gate is the most secure of the various "
                    "gates of the Shire, being built to keep out the "
                    "dark and brooding things from the Gwonish Swamp.",
    ({ "hill", "hills" }) : "The hills of the Shire are peaceful and make for "
                            "good farmland.",
    ]) );
  SetListen( ([
     "default" : "Lloryk is quieter here so close to the swamp.",
     ]) );
  SetSmell( ([
     "default" : "Farm smells mix with the occasional smell of the swamp.",
     ]) );
}
