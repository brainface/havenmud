#include <lib.h>
#include "../gurov.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetClimate("sub-arctic");
  SetExits( ([
    "north" : GUROV_ROOM "cr8",
    "south" : GUROV_ROOM "cr6",
    "west"  : GUROV_ROOM "cemetery",
    ]) );
  SetShort("the Center Road by the Gurov Cemetery");
  SetLong(
    "The Center Road continues to the north and south from here.  Further to "
    "the north lies Gurov Bay, which connects the city to the Northern Sea. "
    "Directly to the west lie both the Cemetery and the Cathedral of Three Gods. "
    "The cemetery, while forlorn, does not appear to be "
    "evil, and the onion domes of the Cathedral of Three Gods rise in triumphant gold "
    "embossing to the skies."
    );
  SetItems( ([
    "cathedral" : "The Cathedral is off to the west. It has red brick walls "
                  "and onion domes made of embossed gold.",
    "cemetery"  : "The cemetery is a small place near the Cathedral for the in"
                  "ternment of the dead.",
    ({ "dome", "domes" }) : "The onion domes are shaped like a blooming onion "
                            "and are made of embossed gold.",
    ]) );
  SetItemAdjectives( ([
    "cathedral" : ({ "kylin", }),
    "dome"      : ({ "onion", "gold", "embossed", }),
    "cemetery"  : ({ "gurov" }),
    ]) );
  SetEnters( ([
    ]) );
  SetSmell("The smell of freshly turned earth comes from the cemetery.");
  SetListen("Deep chanting can be faintly heard from the cathedral.");
}
