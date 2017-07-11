#include <lib.h>
#include <std.h>
#include "../parva.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetExits( ([
    "north" : PARVA_ROOM "path7",
    "southwest": PARVA_ROOM "path8",
    ]) );
  SetShort("the Parvan cemetery");
  SetLong(
    "The mouldering, cracked gravestones and lichen-encrusted wooden grave-markers "
    "that seem to sprout from the hilly ground signify this area as the cemetery "
    "of Parva. Flowers and freshly-cut sea rushes are strewn about by the locals "
    "in an effort to make the cemetery bearable, and a small shrine constructed "
    "from dark wood, blackened with decay, stands on the eastern edge."
  );
  SetItems( ([
    "shrine" : "This shrine serves the Thorian death cult.",
    ({ "gravestone", "gravestones", "marker", "markers", "grave", "graves" }) : "The gravestones and "
        "grave markers signify the presence of graves.",
    ({ "flower", "flowers", "rushes" }) : "These flowers serve both as pious "
        "salutations to the dead and air freshener.",   
    "lichen" : "Silvery, curling lichen grows around and on some of the gravestones.",     
    ]) );
  SetItemAdjectives( ([
    "gravestone" : ({ "grave", "lichen", "encrusted", "wooden", "mouldering", "cracked", }),
    "flower"     : ({ "fresh", "freshly", "cut" }),
    ]) );
  SetEnters( ([
    "shrine" : PARVA_ROOM "thorian",
    ]) );
  SetSmell( ([
    "default" : "Fresh flowers try in vain to cover the smells of the cemetery.",
    "lichen"  : "The lichen smells of rotting bones.",
    ]) );
  SetListen("It is quiet and peaceful here.");
  SetInventory( ([
    STD_OBJ "reztotem" : 1,
    ]) );
}

