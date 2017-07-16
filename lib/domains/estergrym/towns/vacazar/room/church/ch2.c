// Coded by Zeratul
// 3-17-2000

#include <lib.h>
#include <domains.h>
#include "../../vacazar.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("underground");
  SetShort("The room of the Skadar faithful");
  SetLong(
     "This room leads off from the main hall of the church. This is the "
     "room of the faithful of Skadar. This rather simple room has a few "
     "decorations placed in the room. A simple looking couch sits in the "
     "western corner of the room, while a few chairs are on the eastern "
     "side of the room. The board of the Faithful is hung on the southern "
     "wall. "
  );
  SetItems( ([
     ({"room","faithful room"}) : (:GetLong:),
     ({"couch","simple couch"}) : "This simple couch appears to be "
     "nothing more than a piece of wood, but is quite comfortable. "
     "The material of the couch appears to be of a soft leather, with "
     "some small holes in it. ",
     ({"chairs","chair"}) : "A few chairs stand over in the eastern "
     "corner of the room. They appear to be made out of a good quality "
     "wood. ",
     ({"decorations"}) : "A few decorations have been placed in the room. "
     "These decorations liven up the rather plain looking room. ",
  ]) );
  SetItemAdjectives( ([
     "chairs" : ({"good","comfortable"}),
     "couch" : ({"simple","comfortable"}),
     "decorations" : ({"colorful"}),
     "room" : ({"faithful"}),
  ]) );
  SetListen( ([
     "default" : "The sounds of praying can be heard to the north. ",
  ]) );
  SetSmell( ([
     "default" : "The smell of lit urns fills the room. ",
  ]) );
  SetInventory( ([
  ]) );
  SetExits( ([
     "north" : V_ROOM + "church/ch1",
  ]) );
  }
