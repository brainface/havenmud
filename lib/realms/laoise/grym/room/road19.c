#include <lib.h>
#include "../grymxoria.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetAmbientLight(20);
  SetTown("Grymxoria");
  SetShort("abyss lane");
  SetLong(
    "The heart of the city's business quarter. "
    "Abyss lane, named after the black pit that it passes, "
    "continues to the east and west. To the north is a unremarkable "
    "stone building with a sign proclaiming it 'Grymxoria City Post "
    "Office'. To the east the Grymxoria library can be seen, looming "
    "up into the air."
  );
  SetItems( ([
    ({ "post office", "office" }) : "The Grymxoria Post Office. "
    "It is an unremarkable building of the typical stone "
    "construction. Hung over the door is a sign reading: "
    "'Grymxoria City Post Office.'"
  ]) );
  SetItemAdjectives( ([
    "office" : ({ "post", "Grymxoria", "city", "City", "grymxoria" }),
  ]) );
  SetExits( ([ 
    "east" : G_ROOM + "road20",
    "west" : G_ROOM + "road18"
  ]) );
  SetEnters( ([ 
    "post office" : G_ROOM + "post_office"
  ]) );
}

