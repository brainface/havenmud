#include <lib.h>
#include "../gurov.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetExits( ([
    "out"   : GUROV_ROOM "pr2",
    "south" : GUROV_ROOM "keep2",
    ]) );
  SetClimate("indoors");
  SetAmbientLight(40);
  SetLong(
    "The Keep of the Prince of Gurov is an imposing structure built for only one "
    "reason: defense. The entrance hall to the keep is spartan in decoration, but "
    "has thick, imposing walls that could obviously repel all but the most insistant "
    "attackers. To the south, the hall opens into the keep proper where more of the "
    "pomp associated with the Principality takes place."
    );
  SetSmell("The smell of dust hangs thick on the air.");
  SetListen("The sounds of crackling fires echo in from the south.");
  SetShort("the entrance to the Prince's Keep");
}