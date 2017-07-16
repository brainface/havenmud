#include <lib.h>
#include "../tairi.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetClimate("indoors");
  SetAmbientLight(50);
  SetShort("the audience chamber of Clan Minamoto");
  SetExits( ([
    "south" : "p2",
    ]) );
  SetInventory( ([
       TAI_RI_NPC + "samurai_leader" : 1,
       TAI_RI_NPC "daimyo" : 1,
    ]) );
  SetLong("The audience chamber of the daimyo of Clan Minamoto is a huge "
          "and imposing room.  Arrayed on the walls are standards and "
          "honors from battles through the ages. The flags of defeated "
          "houses are nailed to the walls and all have a large and painted "
          "red slash through them, signifying their defeat. To the south "
         "is the central hallway of the palace.");
  SetItems( ([
    ({ "wall", "walls" }) : "The walls are covered with battle trophies.",
    ({ "standards", "standard", "trophy", "trophies" }) :
          "The standards of fallen houses all have a red slash across "
          "them to signify their fate.",
    ]) );
  SetSmell( ([
    "default" : "The scent of flowers in the room is intense.",
    ]) );
  SetListen( ([
    "default" : "The slightest whisper echoes from the high ceilings.",
    ]) );
}
