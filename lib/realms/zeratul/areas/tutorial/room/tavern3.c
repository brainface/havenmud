// Zeratul@Haven - Adam Haye
// 09/12/2013

#include <lib.h>
#include "../tutorial.h"

inherit LIB_ROOM;

static void create () {
  room::create();
  SetClimate("indoors");
  SetAmbientLight(40);
  SetShort("inside a large tavern");
  SetLong(
      "This part of the building, the roof narrows at a steep slope. The walls here are lined "
      "with sconces that are partially lit with candles to illuminate a few tables. The "
      "seating arrangement here is a little more cozy and intimate than the center of the room. "
      "There is a door on the exit that leads out. "
      "\nType <%^MAGENTA%^BOLD%^open door%^RESET%^> to open the door if closed. "
  );
  SetInventory( ([
  ]) );
  SetItems( ([
      ({ "sconces", "candles" }) :
      "Many sconces line the walls here. Some contain lit candles while others appear "
      "to have either no candle or ones burned all the way to the bottom. ",
  ]) );
  SetSmell( ([
      "default" : "The strong scent of smoke, alcohol and sweat permeates the room.",
  ]) );
  SetListen( ([
      "default" : "Distant chatter resonates throughout the building.",
  ]) );
  SetExits( ([
      "south" : T_ROOM + "tavern1.c",
      "out" : T_ROOM + "yard1.c",
  ]) );
  SetDoor( "out", T_OBJ + "door" );
  call_other( T_OBJ + "door", "SetClosed", 1);
}
