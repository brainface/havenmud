#include <lib.h>
#include "../lodge.h"
 inherit LIB_ROOM;

 static void create() {
 room::create();
  SetShort("in a cozy bedroom");
  SetDayLong("By the looks of this room, a good nights sleep can take place here. "
         "An enormous bed lies in the middle of this room adjacent to a broken "
         "table. An interesting window overlooks here, leaving a big shadow to "
         "loom across the area from the sunlight. A sudden chill lingers around "
         "which makes the looks of the stone fireplace in the corner very "
         "welcoming. This room is neatly kept and does not seem to have been "
         "used in awhile.");
   SetNightLong("By the looks of this room, a good nights sleep can take place here. "
         "An enormous bed lies in the middle of this room adjacent to a broken "
         "table. An interesting window overlooks here, leaving a big shadow to "
         "loom across the area from the moonlight. A sudden chill lingers around "
         "which makes the looks of the stone fireplace in the corner very "
         "welcoming. This room is neatly kept and does not seem to have been "
         "used in awhile.");
   SetAmbientLight(27);
   SetClimate("indoors");
   SetItems( ([
         ({"room","bedroom"}) : (:GetLong:),
         ({"bed"}) : "This bed is great in size.  It's covered with skin "
         "blankets that would make sleeping very warm.  It looks "
         "quite comfortable considering this place is run down.",
         ({"table"}) : "This table is broken.  There is nothing on it and it's missing a leg.",
         ({"window"}) : "This window is shaped to the shape of the same "
         "clan symbol as the door entering the room.  It casts a gloomy "
         "shadow over the room",
         ({"shadow"}) : "This shadow is being casted by the shape of the window "
         "above.  It looks like the Clan symbol.  Rather creepy looking.",
         ({"fireplace"}) : "There is no fire in this fireplace.  It looks like it "
         "hasn't been used in ages, which it probably hasn't.  It looks good "
         "enough to heat up the room though.",
   ]) );
   SetItemAdjectives( ([
         "bed" : ({"great","comfortable"}),
         "table" : ({"broken"}),
         "shadow" : ({"creepy"}),
   ]) );
   SetExits( ([
      "west" : L_ROOM + "hallway.c",
   ]) );
   SetSmell( ([
         "default" : "This room has no smell in particular.",
   ]) );
   SetListen( ([
         "default" : "This room is silent",
   ]) );
 }

