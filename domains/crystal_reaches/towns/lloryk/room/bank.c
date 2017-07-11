#include <lib.h>
#include "../path.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("indoors");
  SetAmbientLight(50);
  SetTown("Lloryk");
  SetShort("the Commissariat of Trade");
  SetLong("This hall is a large, well maintained building that houses "
    "the Commissar of Foreign Trade and his staff.  It is here that "
    "commerce between the Shire and other cities.  Hard wooden desks "
    "designed only for functionality line the walls, and the desk of "
    "the Commissar of Trade sits against the far wall."
    );
  SetItems( ([
    ({ "desks", "desk" }) : "The desks are rather plain wooden affairs "
       "that do not look comfortable at all.",
    ]) );
  SetItemAdjectives( ([
    "desk" : ({ "hard", "wooden", }),
    ]) );   
  SetInventory( ([ 
    LLORYK "npc/keller" : 1,
    ]) );
  SetSmell( ([
    "default" : "The smell of old musty papers ruins the coziness "
                "of the Commissariat.",
     ]) );
  SetListen( ([
    "default" : "The hall seems to have coated to reduce noise.",
    ]) );           
  SetExits( ([ 
    "out" : LLORYK "room/uh4", 
    ]) );
}

