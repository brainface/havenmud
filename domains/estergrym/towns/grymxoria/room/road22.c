#include <lib.h>
#include "../grymxoria.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("sub-arctic");
  SetAmbientLight(20);
  SetTown("Grymxoria");
  SetShort("blood River road");
  SetLong(
    "Blood River road continues to the north and south. "
    "Looming up in the darkness to the north the huge "
    "gothic style cathedral dedicated to the religion of Aberach "
    "can be seen. To the east is Kintara's House of Bargains."
  );
  SetItems( ([
    ({ "cathedral", "church" }) : "The cathedral looms up to "
    "the south. Its tallest spire nearly touching the roof of "
    "the cavern. Colored patches of light can be seen shining "
    "eerily through the stained glass windows of the cathedral.",
    ({"house of bargains", "kintara's", "house", "store", "shop" }) :
    "Kintara's House of Bargains is a general store.",
  ]) );
  SetExits( ([ 
    "north" : G_ROOM + "road21",
    "south" : G_ROOM + "road26"
  ]) );
  SetEnters( ([
    ({ "house", "store", "shop" }) : G_ROOM + "g_store",
  ]) );
}

