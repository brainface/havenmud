#include <lib.h>
#include "../gwonish.h"
inherit LIB_ROOM;

static void create() {
	::create(); SetClimate("sub-tropical");
	SetShort("a curve in the swamp path");
	SetExits( ([
	  "west"  : GWONISH_ROOM "gw07",
	  "south" : GWONISH_ROOM "gw04",
	  ]) );
  SetLong(
    "The swamp paths continue to the west and south from here. "
    "Further to the west lies what appears to be the center of the "
    "village, while to the south the path leads towards more huts. "
    "Posted on a tree are several notices involving the rules of the "
    "village. Vines hang loosely from the trees here, obscuring the "
    "skylight."
    );
  SetItems( ([
    ({ "vine", "vines" }) : "The vines are greenish things that "
                            "hang off the trees preventing light "
                            "from the sky.",
    ({ "notice", "notices" }) : "The notices are posted on the "
                                "news board.",
    ({ "tree", "trees", }) : "The trees are semi tropical varieties.",
    ]) );
  SetSmell( ([
    "default" : "Various stenches prevent any one smell from being "
                "identified.",
    ]) );
  SetListen( ([
    "default" : "The caws of various birds see to fill the air.",
    ]) );
  SetNewsgroups( ({ "town.gwonish" }) );
  SetInventory( ([
    ]) );
}