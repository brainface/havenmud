#include <lib.h>
#include <domains.h>
#include "../../lisht.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetClimate("arid");
  SetExits( ([
    "north" : LISHT_ROOM "elf/ra2",
    "south" : LISHT_ROOM "elf/ra4",
    ]) );
  SetShort("River Alley by the Wall of Lisht");
  SetLong(
    "The alley continues to run to the north and south from here. "
    "To the south, it appears that the alley ends, but even here it "
    "thins as it travels. A small house sits facing the alley, home "
    "to the the local priest. The Wall of Lisht rises over the alley, "
    "making it dark and often depressing. The rundown nature of this "
    "section of the city is testament to it being the home of those "
    "whom the gnolls of Xandria choose to suppress."
    );
  SetDayLight(-10);
  SetSmell("A faint smell of incense seems to come from the house.");
  SetItems( ([
    "wall" : "The Wall of Lisht is a large and imposing barrier.",
    "house" : "The house of the local priest seems to serve as "
              "as temple for the slaves.",
    ]) );
  SetEnters( ([
    "house" : LISHT_ROOM "elf/cleric_house",
    ]) );              
}
