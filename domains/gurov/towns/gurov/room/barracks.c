#include <lib.h>
#include "../gurov.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetExits( ([
    "out" : GUROV_ROOM "or6",
    ]) );
  SetShort("inside the Gurov Barracks");
  SetClimate("indoors");
  SetAmbientLight(40);
  SetInventory( ([
    GUROV_NPC "fighter" : 1,
    GUROV_NPC "phys_train" : 1,
    ]) );
  SetLong(
    "The Barracks is a strictly functional building that houses the "
    "training needs of the city watch and the Prince's Own Guards. "
    "The floor is marked with various circles for combat training. "
    "The walls of the barracks are thick grey stone, much like the "
    "town wall, and the various windows are barred with iron."
    );
  SetSmell("The room has a faint odor of old sweat.");
  SetListen("The Barracks sounds like any training hall would.");
}