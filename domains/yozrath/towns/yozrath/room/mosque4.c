#include <lib.h>
#include "../yozrath.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetClimate("indoors");
  SetAmbientLight(40);
  SetShort("the base of the minaret");
  SetExits( ([
    "north" : YOZRATH_ROOM "mosque1",
    "up"    : YOZRATH_ROOM "minaret",
    ]) );
  SetLong(
    "The minaret is a tall spire that overlooks the city.  From its "
    "heights, the imams call the faithful to worship. Its brown sandstone "
    "is unadorned following the spartan nature of Desert Kylin. The "
    "stairs leading up the spiral minaret are thin and without railing, "
    "forcing the Imam to rely greatly on faith to climb them."
    );
  SetSmell("Incense wafts in from the north.");
  SetListen("Chants echo from the hallways.");
}
