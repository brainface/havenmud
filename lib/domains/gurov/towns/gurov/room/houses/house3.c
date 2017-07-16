#include <lib.h>
#include "../../gurov.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetExits( ([
    "out" : GUROV_ROOM "pr4",
    ]) );
  SetShort("inside a wealthy domicile");
  SetClimate("indoors");
  SetAmbientLight(40);
  SetSmell("The room smells of an exotic spice.");
  SetListen("The room's thick walls dampen much of the sound from outside.");
  SetLong(
    "This room serves as the town dwelling of a local merchant. His importance "
    "is apparent from the proximity to the Keep. Thick wooden walls muffle noise "
    "from outside and do an excellent job of insulating the house from the often "
    "bitter cold. Thick rugs sit on the floor near the fireplace."
    );
  SetInventory( ([
    GUROV_NPC "merchant" : 1,
    ]) );
}