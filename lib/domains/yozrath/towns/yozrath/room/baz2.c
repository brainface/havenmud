#include <lib.h>
#include "../yozrath.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetClimate("arid");
  SetExits( ([
    "west" : YOZRATH_ROOM "baz1",
    "east" : YOZRATH_ROOM "bazaar",
    ]) );
  SetShort("near the Bazaar of Yozrath");
  SetLong(
    "The Bazaar Road continues to the east and west from here. Directly to the east "
    "lies the Yozrath Bazaar, a famed institution of trade. Built to the south is "
    "a large building that serves as a local inn. Though the desert gets little in "
    "the way of visitors, the inn still seems to be busy. Other buildings line "
    "the road, but none seem accessable from here."
    );
  SetItems( ([
    ({ "buildings", "building" }) : "None of the buildings of the inn are notable.",
    "inn" : "There is a large wooden building here which serves as an inn.",
    "bazaar" : "The bazaar is to the east.",
    ]) );
  SetSmell("Something from the inn smells delicious.");
  SetListen("From here, the sounds of the bazaar are very loud.");
  SetEnters( ([
    "inn" : YOZRATH_ROOM "inn",
    ]) );
}
