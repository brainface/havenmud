#include <lib.h>
#include "../yozrath.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetShort("the Mosque Road at the Janissary Hall");
  SetClimate("arid");
  SetExits( ([
    "east" : YOZRATH_ROOM "mos3",
    "west" : YOZRATH_ROOM "mos1",
    ]) );
  SetLong(
    "The Mosque Road continues to the east and west from here. To the south "
    "lies the Hall of Janissaries, the training center for the army of the "
    "sheikdom. To the east lies the Mosque of Yozrath, the home of the Imams "
    "that preach to the masses the glory of He Who Judges. Various lesser "
    "buildings line the road, but none appear accessable from here."
    );
  SetItems( ([
    ({ "building", "buildings" }) : "Various buildings line the road, but only "
                                    "the Hall of Janissaries seems important.",
     "hall" : "The Hall of Janissaries is the primary training center of the "
              "Sheik's army.",
     "mosque" : "The Mosque of Yozrath is to the east.",
     ]) );
  SetItemAdjectives( ([
    "building" : ({ "various", "lesser" }),
    ]) );
  SetEnters( ([
    "hall" : YOZRATH_ROOM "janissary",
    ]) );
  SetSmell("Incense burns to the east.");
  SetListen("At all hours, the sounds of combat training come from the hall.");
  SetInventory( ([
    ]) );                                    
}
