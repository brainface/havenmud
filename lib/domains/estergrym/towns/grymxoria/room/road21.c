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
    "To the north and partially to each side looms the "
    "Grymxoria town hall. The large gothic style building "
    "straddles the road with a large archway leading into "
    "the central courtyard of the church and town hall "
    "complex. To the south is Kintara's House of Bargains."
  );
  SetItems( ([
    ({ "town hall" }) :  "A large gothic style building made of large "
    "blocks of crudely carved black stone."
  ]) );
  SetExits( ([ 
    "north" : G_ROOM + "road16",
    "south" : G_ROOM + "road22"
  ]) );
  SetInventory( ([
    G_OBJ + "fountain" : 1 
  ]) );
}
