// Coded by Zeratul
// 3-22-2000

#include <lib.h>
#include <domains.h>
#include "../../vacazar.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("underground");
  SetShort("the cemetery");
  SetExits( ([
     "west" : V_ROOM + "church/ch1",
  ]) );
  SetLong(
     "This cemetery is where the citizens of the town bury their dead. "
     "Large tombs stand around the cemetery, as the rock is too solid to bury "
     "anything into the rock. To the west is the church of Skadar. "
  );
  SetItems( ([
     ({"cemetery"}) : (:GetLong:),
     ({"tomb","tombs"}) : "These large, stone tombs stand around the cemetery. "
     "These tombs are used instead of graves due to the fact that the rock "
     "is too solid to bury anything in it. ",
     ({"church"}) : "The huge church of Skadar stands to the west. The large "
     "church stands high into the cavern, standing over the rest of the town. ",
  ]) );
  SetItemAdjectives( ([
     "cemetery" : ({"dark","creepy","death"}),
     "tombs" : ({"stone","resting place"}),
     "church" : ({"large","stone","looming"}),
  ]) );
  SetListen( ([
     "default" : "The graveyard has the stillness of death.",
  ]) );
  SetSmell( ([
     "default" : "The smell of death hangs in the air.",
  ]) );
  }
