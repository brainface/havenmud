#include <lib.h>
#include <domains.h>
#include "../hospital.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetExits( ([
    "out"   : GUROV_TOWNS "gurov/room/or6",
    ]) );
  SetShort("the Entrance to the Gurov Hospital");
  SetClimate("indoors");
  SetAmbientLight(40);
  SetInventory( ([
    HOS_NPC "raspina" : 1,
    ]) );
  SetProperty("no attack", 1);
  SetProperty("no magic", 1);
  SetLong(
    "The Hospital is a place that is safe for the citizens of Gurov in "
    "times of strife. Here in the foyer of the hospital a permanent "
    "aura has been placed preventing much that can cause harm. Various "
    "halls lead away from the foyer, but the majority of the business "
    "of the hospital is done right here."
    );
  SetSmell("Coming from a hallway is a distinct scent of death.");
  SetListen("The occasional scream from further in the building can be heard.");
}
