#include <lib.h>                    
#include <daemons.h>                
#include <domains.h>                
#include "../gurov.h"               

inherit LIB_SHIPCAPTAIN;

static void create() {
  ::create();         
  SetKeyName("explorer");
  //SetShort("Piotr Ushakov, the Arctic Explorer");
  SetShort("an arctic explorer");
  SetId( ({ "explorer" }) );
  SetAdjectives( ({ "arctic" }) );
  SetRace("human");
  SetClass("sailor");
  SetLevel(98); // annilate longships, avoid warships, don't go in circles.
  SetGender("male");
  SetLong(
    "The cracks and ruddy color of this aging human's face "
    "are common after effects of surviving severe frostbite. "
    "However, a wide smile often reaches his face, and he moves "
    "with the energy of an enthusiast at his hobby."
  );
  SetInventory( ([
    INNERSEA_ENCOUNTERS "obj/parka" : "wear parka",
    INNERSEA_ENCOUNTERS "obj/rigging_knife" : "wield knife",
  ]) );
  SetFirstCommands( ({
    "out",
    "board icebreaker",
    "yell All aboard for the arctic expedition!"
  }) );
  SetAction(3, ({
    "!say killer whale off the starboard bow!"
  }) );
  SetShipWanderPath(
    GUROV_ROOM "bay4",
    INNERSEA_VIRTUAL "ocean/-50,500",
  );
  SetAction(10, ({ "!board first icebreaker" }) );
}

