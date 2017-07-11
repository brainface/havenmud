#include <lib.h>
#include "../gurov.h"
inherit LIB_ROOM;
inherit LIB_TOUCH;

static void create() {
  ::create();
  SetExits( ([
    "out" : GUROV_ROOM "or4",
    ]) );
  SetShort("the home of Baba Yaga the Witch");
  SetLong(
    "Nothing in this domecile seems to serve as more than it needs to serve. Everything is neat and orderly, "
    "with nothing excessive or out of place. The home, while spartan, seems to serve its purpose nicely, with "
    "a small cauldron sitting over a cooking fire near the outside wall and a stout wooden door keeping the draft "
    "from getting inside. A small bed lies near the fire."
    );
  SetClimate("indoors");
  SetAmbientLight(45);
  SetSmell("Something is cooking in the cauldron.");
  SetListen("The crackle of the flames is a quiet backdrop to the home.");
  SetItems( ([
    ]) );
  SetInventory( ([
    GUROV_NPC "practical_train" : 1,
    GUROV_NPC "meta_practical"  : 1,
    ]) );
}
