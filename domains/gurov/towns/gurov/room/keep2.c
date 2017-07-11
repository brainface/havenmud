#include <lib.h>
#include "../gurov.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetExits( ([
    "west"  : GUROV_ROOM "keep3",
    "east"  : GUROV_ROOM "keep4",
    "north" : GUROV_ROOM "keep1",
    ]) );
  SetShort("a main reception hall in the Keep");
  SetClimate("indoors");
  SetAmbientLight(40);
  SetLong(
    "The reception hall in the Prince's Keep is a large affair "
    "with ceilings that seem to rise into the darkness. Grey "
    "stone walls seem a flat and unappealing way to greet a "
    "visitor, but for the Principality nothing else would do. "
    "Off to the east lies the office of the treasurer of Gurov "
    "while to the west lies the throne room."
    );
  SetSmell("There is a faint hint of dust in the air.");
  SetListen("Light music comes from the west.");
}