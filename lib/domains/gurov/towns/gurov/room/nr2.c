#include <lib.h>
#include "../gurov.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetClimate("sub-arctic");
  SetExits( ([
    "east" : GUROV_ROOM "nr1",
    "west" : GUROV_ROOM "nr3",
    ]) );
  SetShort("the Nobles' Road");
  SetLong(
    "The Nobles' Road continues east and west from here. Off to the "
    "east, the road meets up with Center Road which travels the length "
    "of the town. Off to the west lies the Council of Nobles Hall, "
    "where all the ranking members of the nation meet to discuss the "
    "issues of the day."
    );
  SetItems( ([
    ]) );
  SetSmell("The Nobles' Road is kept clear of animal waste.");
  SetListen("The sounds of the city come from all around.");
}