#include <lib.h>
#include "../grymxoria.h"
int PreExit(string);
inherit LIB_ROOM;

static void create() {
  room::create();
  SetTown("Grymxoria");
  SetClimate("indoors");
  SetAmbientLight(20);
  SetProperty("no bump",1);
  SetShort("the Grymxoria arena");
  SetLong(
    "Inside the Grymxoria arena. The ceiling slopes up towards "
    "the outer wall, supporting the bleachers of the arena. To the "
    "east is a door leading in to the valkyr and barbarian "
    "meeting room.  While to the west is a training room for "
    "use by the gladiators. To the south is a huge set of iron "
    "doors which lead into the arena waiting room. Right now the "
    "arena is closed, so the doors are shut."
  );
  SetExits( ([
    "west" : G_ROOM + "arena1",
    "out" : G_ROOM + "road12" 
  ]) );
  AddExit("east", G_ROOM + "arena3", (: PreExit :) );
}

int PreExit(string dir) {
  if( (this_player()->GetClass() == "valkyr") ||
    (this_player()->GetClass() == "barbarian") ||
    (creatorp(this_player()))) {
  return 1;
  } else {
    message("my_action","A burly guard shoves you back out "
      "the door.",this_player());
    return 0;
  }
}
