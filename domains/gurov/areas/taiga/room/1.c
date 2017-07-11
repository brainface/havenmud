//Illura@haven
//Room 1
//August 2009
#include <lib.h>
#include <std.h>
#include <dirs.h>
#include <domains.h>
#include "../taiga.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("temperate");
  SetShort("On the edge of a boreal forest");
  SetLong(
    "An extensive taiga stands to the north, just beyond "
    "the rolling Gurov plains and the road running through "
    "the Prince's lands. Although it is rather cold here, the "
    "ancient conifers block the tundra winds, which whistle "
    "eerily. The place seems quite untamed."
  );
  SetExits( ([
    "east"  : TAIGA_ROOM "2",
    "north" : TAIGA_ROOM "4",
    "south" : GUROV_VIRTUAL "gurovrd/5,0",
  ]) );
  SetItems( ([
    "plains" : "The cold prairies are south.",
    ({"conifer", "conifers"}) : "Pine trees with dark green needles grow thickly.",
  ]) );
  SetItemAdjectives( ([
    "conifer" : "ancient",
  ]) );
  SetInventory( ([
    TAIGA_NPC + "dormouse" : 1,
  ]) );
  SetListen( ([
    "default" : "The wind keens with almost a sorrowful sound.",
  ]) );
  SetSmell( ([
    "default" : "The air is cool and crisp.",
  ]) );
}
