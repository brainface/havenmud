#include <lib.h>
#include "../yozrath.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetClimate("indoors");
  SetAmbientLight(35);
  SetShort("inside an inn");
  SetExits( ([
    "out" : YOZRATH_ROOM "baz2",
    ]) );
  SetLong(
    "The large wooden building serves as an inn.  Though the desert "
    "sect of Kylin forbids the use of alcohol, the various juices "
    "and foods of the desert are famed throughout the world. Large "
    "wooden tables are spread across the common room of the inn, and "
    "there are significantly large open windows to the outside to "
    "provide ventilation."
    );
  SetItems( ([
    ({ "table", "tables" }) : "The tables are ordinary wooden tables.",
    ({ "window", "windows" }) : "The windows open to the street and provide fresh air.",
    ]) );
  SetSmell("Various fruits and juices give the inn a sweet and light smell.");
  SetListen("The dull roar of the bazaar can be heard from outside.");
  SetInventory( ([
    YOZRATH_NPC "dancer" : 1,
    YOZRATH_NPC "rogue"  : 1,
    ]) );
}
