// Monastery
// Aerelus
// 06/05/2006

#include <lib.h>
#include <domains.h>
#include "../monastery.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetAmbientLight(30);
  SetClimate("indoors");
  SetShort("inside a training building");
  SetLong(
    "This building appears to be a place for the monks to train their combat "
    "skills. The walls are lined with decorative swords and shields. An open "
    "training area in the center of the building is covered with sand that "
    "looks like it may have absorbed a lot of blood. The door leads out to "
    "the monastery courtyard."
  );
  SetItems( ([
  ({ "walls", "swords", "shields" }) :
    "There are some decorative swords and shields firmly attached to the walls.",
  ({ "area", "sand", "blood", "center" }) :
    "The training area is where the monks practice their skills. It is covered with "
    "sand, which seems to have absorbed the blood of careless trainees.",
  ({ "door" }) :
    "This wooden door leads out into the courtyard.",
  ({ "courtyard" }) :
    "The courtyard lies out, beyond the wooden door.",
  ]) );
  SetItemAdjectives( ([
    "area" : ({ "training", "open" }),
    "swords" : ({ "decorative" }),
    "shields" : ({ "decorative" }),
    "door" : ({ "wooden" }),
  ]) );
  SetInventory( ([
    AREA_NPC "warrior_monk" : 3,
  ]) );
  SetListen( ([
    "default" : "The grinding sound of swords being sharpened is almost painful.",
  ]) );
  SetSmell( ([
    "default" : "The smell of sweat is most prominent.",
  ]) );
  SetExits( ([
    "out" : AREA_ROOM "courtyard",
  ]) );
}
