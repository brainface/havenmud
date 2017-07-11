// Coded by Zeratul
// 3-23-2000

#include <lib.h>
#include <domains.h>
#include "../../vacazar.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("underground");
  SetShort("the fighter hall");
  SetLong(
     "This is the fighter hall. Inside this building is where the fighters "
     "of the town come to train and work on their skills. There are some "
     "paintings that depict battles that they have been in, as these warriors "
     "have more honor than the assassins. To the north is the barracks "
     "of the fighter hall, while a door leads out into the road. "
  );
  SetItems( ([
     ({"hall","fighter hall"}) : (:GetLong:),
     ({"paintings"}) : "These paintings are hung around the room. They depict "
     "the battles that the fighters of the town have been in. These are "
      "objects of the proud warriors of this town. ",
  ]) );
  SetItemAdjectives( ([
     "fighter hall" : ({"proud","stone","honorable"}),
     "paintings" : ({"proud","honorable"}),
  ]) );
  SetListen( ([
     "default" : "The sounds of the warriors training echoes around the room. ",
  ]) );
  SetSmell( ([
     "default" : "The hall has a musty smell to it.",
  ]) );
  SetExits( ([
     "out" : V_ROOM + "fighter_road/fr4",
  ]) );
  SetInventory( ([
  ]) );
  }
