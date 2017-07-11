// Coded by Zeratul
// 3-11-2000

#include <lib.h>
#include <domains.h>
#include "../../vacazar.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("underground");
  SetShort("the fighter road");
   SetLong(
     "The Fighter Road leads off into the fighter section of town. The "
     "fighter hall stands off to the west, while the main road "
     "is to the east. A few scattered buildings line along the road, "
     "which appear to be either homes or barracks. "
  );
  SetItems( ([
     ({"town","cavern"}) : (:GetLong:),
     ({"buildings","stone buildings"}) : "A couple of buildings "
     "reside on either side of the road. These buildings appear to be "
     "either homes or barracks. ",
     ({"hall","fighter hall"}) : "The fighter hall stands at the end of "
     "the road to the west. The building appears to be carved out of the "
     "stone of the mountains, standing over the rest of the buildings "
     "along the road. ",
     ({"road","fighter road"}) : "The road here is the Fighter Road. This "
     "road leads off into the fighter section of town. ",
  ]) );
  SetItemAdjectives( ([
     "fighter road" : ({"worn"}),
     "fighter hall" : ({"large"}),
     "buildings" : ({"scattered"}),
  ]) );
  SetListen( ([
     "default" : "The sounds of civilization echoes throughout the city. ",
  ]) );
  SetSmell( ([
     "default" : "The underground city smells of city life. ",
  ]) );
  SetInventory( ([
  ]) );
  SetExits( ([
     "east" : V_ROOM + "fighter_road/fr2",
     "west" : V_ROOM + "fighter_road/fr4",
  ]) );
  }
