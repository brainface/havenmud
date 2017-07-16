// Zeratul@Haven - Adam Haye
// 09/12/2013

#include <lib.h>
#include "../tutorial.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("indoors");
  SetAmbientLight(40);
  SetShort("inside a large tavern");
  SetLong(
      "This building reveals itself to travelers as a welcoming and warm facility. "
      "Large wooden supports stretch up into the ceiling while the walls are covered "
      "with tapestries that show the history of Kailie. There is a bar in the "
      "middle of the place with many different tables surrounding it. The floor is "
      "covered in dirt, a tribute to the many individuals who have passed through "
      "these walls. There are rooms to the east that are occupied by those who "
      "live here and await to meet newcomers to this realm. "
      "\nType <%^MAGENTA%^BOLD%^greet loran%^RESET%^> to receive his help. "
  );
  SetInventory( ([
      T_NPC + "equipper" : 1,
  ]) );
  SetItems( ([
      ({ "tapestry", "walls" }) :
      "The walls are lined with many different tapestries, artwork, and literature that "
      "show the history of Kailie. ",
  ]) );
  SetSmell( ([
      "default" : "The strong scent of smoke, alcohol, and sweat permeates the room.",
  ]) );
  SetListen( ([
      "default" : "Distant chatter resonates throughout the building.",
  ]) );
  SetExits( ([
      "north" : T_ROOM + "tavern3.c",
      "east" : T_ROOM + "tavern2.c",
      "out" : T_ROOM + "begin3.c",
  ]) );
}
