#include <lib.h>
#include <domains.h>
#include "../../lisht.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetClimate("arid");
  SetExits( ([
    "north" : LISHT_ROOM "elf/ra1",
    "south" : LISHT_ROOM "elf/ra3",
    ]) );
  SetShort("River Alley by the Wall of Lisht");
  SetLong(
    "The alley continues to the north and south from here. To the north, the "
    "alley leads off towards the River Road. Directly to the west is the Wall "
    "of Lisht, which towers over the small and pathetic buildings that comprise "
    "the elven section of Lisht. A small building by the side of the wall "
    "appears to house the local healer."
    );
  SetItems( ([
    "building" : "This building appears to house the local healer.",
    "wall"     : "The Wall of Lisht towers over the alley.",
    ]) );
  SetListen("The alley is quiet to the point of oppressive.");
  SetEnters( ([
    "building" : LISHT_ROOM "elf/healer",
    ]) );
}
