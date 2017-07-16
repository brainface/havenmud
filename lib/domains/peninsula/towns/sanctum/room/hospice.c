#include <lib.h>
#include "../rome.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetShort("the Sanctum Hospice");
  SetLong("Beds and benches of all sizes line this small house. "
          "The building serves as a hospice to those in need of "
          "healing, but relies on the charity and goodwill of "
          "local clerics to stop in and heal those in need.");
  SetExits( ([
    "out" : ROME_ROOM "rd10",
    ]) );
  SetClimate("indoors");
  SetAmbientLight(35);
  SetInventory( ([
    ROME_NPC "hospice_citizen" : 3,
    ]) );
  SetSmell("The smell of death is rich in this place.");
  SetListen("The moans of the ill and dying echo around the room.");
  }
