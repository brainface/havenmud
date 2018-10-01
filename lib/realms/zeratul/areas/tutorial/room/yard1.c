// Zeratul@Haven - Adam Haye
// 09/12/2013

#include <lib.h>
#include "../tutorial.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("temperate");
  SetShort("within a fenced in yard");
  SetLong(
      "This area leads into a fenced in courtyard behind the tavern. "
      "There appears to be all manner of training items for young travelers "
      "to utilized. To the east is a corner with a series of training dummies. "
      "To the west is a pond with a few small strcutures around it. To the north "
      "leads out of the fenced area and back onto the path. The tavern sits "
      "directly to the south and can be entered from here. "
      "\nType <%^MAGENTA%^BOLD%^peer [direction]%^RESET%^> to view the next room. "
  );
  SetInventory( ([
  ]) );
  SetItems( ([
      ({ "fence" }) :
      "This fence surrounds the courtyard outside of the tavern. It appears designed "
      "to keep items and people in as well as out. ",
      ({ "pond", "lake" }) :
      "The pond is in an eastern direction from here. There appears to be numerous "
      "structure set about the lake. ",
      ({ "tavern", "building" }) :
      "This structure is made of wood.",
  ]) );
  SetSmell( ([
      "default" : "The scent of dust and pine mix together here.",
  ]) );
  SetListen( ([
      "default" : "Soft sounds of voices can be heard from the tavern. ",
  ]) );
  SetEnters( ([
      "tavern" : T_ROOM + "tavern3",
  ]) );
  SetExits( ([
      "north" : T_ROOM + "end1",
      "east" : T_ROOM + "yard2",
      "west" : T_ROOM + "yard3",
  ]) );
  SetDoor( "tavern", T_OBJ + "door" );
}
