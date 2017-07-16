#include <lib.h>
#include "../gurov.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetShort("the Nubile Noble Inn");
  SetClimate("indoors");
  SetAmbientLight(40);
  SetLong(
    "The Nubile Noble panders to the exotic tastes and needs of "
    "the various nobles of the Principality of Gurov. Comfortable, "
    "well upholstered chairs are spread around the room, designed "
    "for more class and comfort than seating capacity. Everything "
    "about the inn seems to be catered to the very wealthy rather "
    "than in any effort to do any volume of business."
    );
  SetItems( ([
    ({ "chair", "chairs" }) : "The chairs are very comfortable "
          "and well upholstered.",
    ]) );
  SetSmell("There is a faint smell of flavoured tobacco in the air.");
  SetListen("The walls of the Inn are meant to prevent sound from travelling.");
  SetExits( ([
    "out" : GUROV_ROOM "nr3",
    ]) );
  SetInventory( ([
    GUROV_NPC "lucinda" : 1,
    ]) );
}
