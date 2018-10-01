#include <lib.h>
#include "../grymxoria.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetAmbientLight(20);
  SetTown("Grymxoria");
  SetShort("abyss lane");
  SetLong(
    "The heart of the city's business quarter. Abyss lane, "
    "named after the black pit that it passes, continues to the "
    "east and west. To the north is a squat stone building with a "
    "sign hung over the door proclaiming it the 'Grymxoria bank.' "
    "To the west looms the Grymxoria arena.");
  SetItems( ([
    ({ "bank", "grymxoria bank" }) : "A large squat stone "
    "block building that is built like a fortress. Hung over the "
    "door is a sign reading: 'Grymxoria Bank'."
  ]) );
  SetExits( ([ 
    "east" : G_ROOM + "road14",
    "west" : G_ROOM + "road12"
  ]) );
  SetEnters( ([ 
    "bank" : G_ROOM + "bank"
  ]) );
}

