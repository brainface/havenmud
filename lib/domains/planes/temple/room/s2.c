/*  Lamrani Temple, Southern Hallway, Room 2 */
/*     A room of chanting and wailing        */
#include <lib.h>
#include "../temple.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetProperty("lower plane", 1);
  SetClimate("indoors");
  SetAmbientLight(35);
  SetShort("a large open chamber");
  SetExits( ([
    "north" : TEMPLE_ROOM "s1",
    ]) );
  SetSmell( ([
    "default" : "The smell of incense comes from the north.",
    ]) );
  SetListen( ([
      "default" : "The wail of lost souls seems to come from the walls.",
    ]) );
  SetLong("The walls of this chamber are blank, giving no indication "
          "of where the howling wail that fills the room comes from. "
          "The cold marble floor seems to lead back north, almost "
          "begging anyone who might enter here to leave. Further north "
          "the hallway leads out.");
  SetItems( ([
    "floor" : "The floor is a highly polished dark marble.",
    ({ "wall", "walls" }) : "The walls seem almost flawlessly white.",
    ]) );
  SetItemAdjectives( ([
      "floor" : ({ "cold", "marble" }),
    ]) );
  SetInventory( ([
    TEMPLE_NPC "lamrani1" : 2,
    ]) );
 }
