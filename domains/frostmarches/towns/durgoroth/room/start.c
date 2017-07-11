
#include <lib.h>
#include <domains.h>
#include "../durgoroth.h"

inherit LIB_ROOM;

int PortalEnter();
static void create() {
  room::create();
  SetClimate("indoors");
  SetAmbientLight(45);
  SetShort("the deep recesses of the Cave");
  SetLong("The walls and floor of the cave have been made"
          " smooth and are covered in blood splatter."
          " At the rear of the cave a large glowing"
          "%^BLUE%^ portal%^RESET%^ radiates light"
          " illuminating the whole area in a blue"
          " glow. To the south the opening of the cave"
          " can be seen.");
  SetItems( ([
          ({ "cave", "walls", "floor" }) :
            "The walls and floor of the cave have been made"
            " smooth and are covered in blood splatter."
            " At the rear of the cave a large glowing"
            " %^BLUE%^portal%^RESET%^ radiates light"
            " illuminating the whole area in a blue"
            " glow. To the south the opening of the cave"
            " can be seen.",
          ({ "portal" }) :
            "The portal glows a dark blue, casting"
            " light all around.",
     ]) );
  SetItemAdjectives( ([
     "portal" : ({ "glowing", "blue", "large", "radiating" }),
     "cave" : ({ "smooth", "bloody" }),
     ]) );
  SetProperty("no bump", 1);
  SetProperty("no attack", 1);
  SetProperty("no magic", 1);
  SetProperty("no steal", 1);
  SetExits( ([
           "south" : DURG_ROOM "cave1",
     ]) );
  AddEnter("portal", DOMAIN_PLANES "castles/first/entrance", 
           (: PortalEnter :));

}
  

int PortalEnter() {
  if (this_player()->GetLevel() < 50 || this_player()->GetId() == "durg_wander") {
     message("nogo", "You feel too weak to venture into the"
             " unknown.", this_player());
    return 0;
  }
  return 1;
}
