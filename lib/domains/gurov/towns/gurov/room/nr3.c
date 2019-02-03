#include <lib.h>
#include "../gurov.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetClimate("sub-arctic");
  SetExits( ([
    "east" : GUROV_ROOM "nr2",
    ]) );
  SetShort("the Nobles' Road by the Council Hall");
  SetLong(
    "The Nobles' Road ends here in front of the Council of Nobles Hall. "
    "The Hall looms high with dark red colored brick walls. Its purpose "
    "stands in stark relief to the Prince, who the Council holds in check. "
    "Off to the east, the road continues back towards the Center Road. "
    "Sitting proudly next to the Council Hall is the Nubile Noble Inn, "
    "a place for the nation's nobles to relax and unwind."
    );
  SetSmell("The road is kept clean and free of offal.");
  SetListen("The occasional snippet of conversation escapes the Hall.");
  SetItems( ([
    "hall" : "The Council Hall looms with its dark red walls. Its appearance "
             "is less than friendly.",
    "inn"  : "This inn seems to be fairly prosperous.",
    ]) );
  SetItemAdjectives( ([
    "hall" : ({ "council", "duma" }),
    ]) );
  SetEnters( ([
    "hall" : GUROV_ROOM "council1",
    "inn"  : GUROV_ROOM "inn2",
    ]) );
}
