#include <lib.h>
#include <std.h>
#include <dirs.h>
inherit LIB_ROOM;

static void create() {
  room::create();

  SetClimate("indoors");
  SetAmbientLight(40);
  SetShort("a large open space");
  SetLong(
     "Light grey marble lines the walls and floor of this large open space, "
     "two rows of large darker pilars being the only break in lightness. "
     "The space seems to stretch out endlessly to the east and west "
     "with no end to the rows of pilars visible from this point. A "
     "shimmering portal hovers here near the southernmost wall. "
     );
  SetExits( ([
    "south" : "/realms/alessandra/projects/xandria/tameria/room/death",
    "west" : "/realms/alessandra/workroom",
     ]) );
}
