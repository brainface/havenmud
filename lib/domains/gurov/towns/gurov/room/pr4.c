#include <lib.h>
#include "../gurov.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetClimate("sub-arctic");
  SetExits( ([
    "west" : GUROV_ROOM "pr3",
    ]) );
  SetShort("a dead end on the Prince's Road");
  SetLong(
    "The Prince's Road ends here against the town wall. Rising into the "
    "sky, the wall is a pristine grey stone without even a hint of weakness. "
    "The Prince's Road leads off to the west towards the Keep. Lying along "
    "the road here is a large house that obviously is the residence of someone "
    "fairly important in the Principality."
    );
  SetItems( ([
    "wall" : "The wall is 20 feet tall and solid grey stone.",
    "house" : "The house seems to be a fairly comfortable domicile.",
    ]) );
  SetEnters( ([
    "house" : GUROV_ROOM "houses/house3",
    ]) );
  SetSmell("The smell of dust lingers so close to the wall.");
  SetListen("The wall dampens the normal sounds of the city.");
}