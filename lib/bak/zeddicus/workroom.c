#include <lib.h>
#include <std.h>
#include <dirs.h>

inherit LIB_ROOM;

static void create()
{
  room::create();

  SetShort("a workroom");
  SetLong("This is your basic workroom. There is not much to see "
          "here, but if you were interested, you could go north "
          "to get to the staff room of the Immortals.");
  SetClimate("indoors");
  SetAmbientLight(40);
  SetExits( ([
    "north" : DIR_STANDARD_DOMAIN "/staffroom",
    "up" :    DIR_STANDARD_DOMAIN "/room/portal"
  ]) );

  find_living("zeddicus")->AddChannel("intergossip");
}
