#include <lib.h>
#include <domains.h>
#include "../../lisht.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetClimate("arid");
  SetShort("in front of the Palace");
  SetLong(
    "The Pharaoh's Road ends here in front of the massive stone palace of the Pharaoh. "
    "Large marble spires sit at the arched entrance welcoming visitors while instilling "
    "a sense of awe into most. Another paved road meets up here from the south, the Temple "
    "Road that leads to the Temple of the Gods. Far off to the east the Wall of Lisht sits "
    "to protect the citizens from the slaves."
    );
  SetItems( ([
    "palace" : "The might stone palace of the Xandrian Dynasty rises above the street here.",
    ]) );
  SetEnters( ([
    "palace" : LISHT_ROOM "gnoll/palace_ent",
    ]) );
  SetExits( ([
   "east" : LISHT_ROOM "gnoll/pr2",
  "south" : LISHT_ROOM "gnoll/tr1",
    ]) );
}
