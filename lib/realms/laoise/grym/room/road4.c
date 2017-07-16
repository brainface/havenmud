#include <lib.h>
#include "../grymxoria.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetAmbientLight(20);
  SetTown("Grymxoria");
  SetShort("exile avenue");
  SetLong(
    "In the rogues quarter of Grymxoria. Exile avenue, "
    "named both after the event in Nosferatu history and "
    "after its denizens, leads off to the east and west. The "
    "cavern wall can be dimly seen to the west. There is a "
    "large building to the south which appears to be an " 
    "unowned inn."
  );
  SetItems( ([
    ({ "inn", "building" }) : "A large stone building under "
    "construction, a sign in front states that it is an inn. "
    "Workmen rush back and forth carrying blocks of stone "
    "and wheelbarrows of mortar."
  ]) );
  SetExits( ([ 
    "west" : G_ROOM + "road3",
    "east" : G_ROOM + "road5" 
  ]) );
  SetEnters( ([
    ({ "building", "inn" }) : G_ROOM + "p_inn",
  ])  );
}

