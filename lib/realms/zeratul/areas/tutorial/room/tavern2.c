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
      "This part of the building leads down a hallway at the intersection of three rooms. "
      "There is a sign hanging above each door, indicating what lies within each room. "
      "\nType <%^MAGENTA%^BOLD%^read sign%^RESET%^> to read the sign. "
  );
  SetInventory( ([
      T_OBJ + "tavern_sign" : 1,
  ]) );
  SetSmell( ([
      "default" : "The smell of smoke, alcohol and sweat is somewhat noticeable.",
  ]) );
  SetListen( ([
      "default" : "Distant chatter resonates throughout the building.",
  ]) );
  SetExits( ([
      "north" : T_ROOM + "tavern_melee",
      "east" : T_ROOM + "tavern_caster",
      "south" : T_ROOM + "tavern_trade",
      "west" : T_ROOM + "tavern1",
  ]) );
}
