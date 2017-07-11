#include <lib.h>
#include "../newbie.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("a desolate waste");
  SetDayLong("Off to the north, a large structure rises from the center "
             "of the ruins like a hand reaching from the grave.  To the "
             "north, east, and west the patches of green grasses are "
             "enough that it could be considered almost normal ground.");
  SetNightLong("Off to the north, a large structure rises from the center "
             "of the ruins like a hand reaching from the grave. To the "
             "north, east, and west the patches of green grasses are "
             "enough that it could be considered almost normal ground.");
  SetItems( ([
    "structure" : "This appears to be a crypt of some kind.",
    ({ "grass", "grasses" }) : "These patches of green are out of place here.",
    ]) );
  SetItemAdjectives( ([
    "grass" : ({ "green" }),
    ]) );
  SetSmell( ([
    "default" : "The scent of death hangs on the air.",
    ]) );
  SetListen( ([
    "default" : "Deathly silence echoes from the ruined surroundings.",
    ]) );
  SetDayLight(-10);
  SetExits( ([
     "north" : NEWBIE_ROOM + "/field5",
     "east"  : NEWBIE_ROOM + "/field7",
     "west"  : NEWBIE_ROOM + "/field1",
     ]) );
  }
