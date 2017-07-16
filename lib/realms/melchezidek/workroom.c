#include <lib.h>
#include <std.h>
#include <dirs.h>
inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("indoors");
  SetAmbientLight(40);
  SetShort("the doorway to despair");
  SetLong(
    "Darkness and nothingness are all that remains in this "
    "place. Pitch black emptiness full of nothing. An "
    "existential dreamland. \n \n"
    "You experience an overwhelming sense of despair and nothingness."
  );
  SetItems( ([
    ({ "nothing", "nothingness" }) : "That would be a feat, wouldn't it?",
 ]) );
  SetExits( ([
    "north" : DIR_STANDARD_DOMAIN "/staffroom",
    "east"  : STD_AREA "room/basic",
    "south" : "/realms/melchezidek/room/portal",
    "west"  : "/domains/frostmarches/towns/durgoroth/room/road02",
    "down" : "/realms/melchezidek/projects/starfire/room/room01",
  ]) );
}
