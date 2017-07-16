// Coded by Zeratul
// 3-11-2000

#include <lib.h>
#include <domains.h>
#include "../../vacazar.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("underground");
  SetShort("The Assassin Lane");
  SetLong(
     "The Assassin Lane leads off into the assassin section of town. "
     "The assassin hall stands off to the west, while the main road "
     "is to the east. A few scattered buildings line along the road, "
     "which appear to be either homes or barracks. "
  );
  SetItems( ([
     ({"town","cavern"}) : (:GetLong:),
     ({"buildings","stone buildings"}) : "A couple of buildings "
     "reside on either side of the road. These buildings appear to be "
     "either homes or barracks. ",
     ({"hall","assassin hall"}) : "The assassin hall stands at the end of "
     "the road to the west. The building appears to be carved out of "
     "the stone from the mountains. It stands over the rest of the "
     "buildings along the road. ",
     ({"road","assassin lane","lane"}) : "The road here is the Assassin "
     "Lane. This road leads off into the assassin section of town. ",
  ]) );
  SetItemAdjectives( ([
     "assassin lane" : ({"worn"}),
     "assassin hall" : ({"large"}),
      "buildings" : ({"scattered"}),
  ]) );
  SetListen( ( [
     "default" : "The sounds of civilization echoes throughout the city. ",
  ]) );
  SetSmell( ([
     "default" : "The underground city smells of city life. ",
  ]) );
  SetInventory( ([
  ]) );
  SetExits( ([
     "east" : V_ROOM + "main_road/mr8",
     "west" : V_ROOM + "assassin_lane/al2",
  ]) );
  }
