#include <lib.h>
#include "../grymxoria.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetAmbientLight(20);
  SetTown("Grymxoria");
  SetShort("abyss lane");
  SetLong(
    "Abyss lane continues to the east and west. "
    "Looming up in the darkness to the northwest the huge "
    "gothic style cathedral of Saahagoth can be seen. "
    "And to the southwest the Town Hall building. "
    "To the east the Grymxoria Post Office can be seen."
  );
  SetItems( ([
    ({ "cathedral", "church" }) : "The cathedral looms up to "
    "the south. Its tallest spire nearly touching the roof of "
    "the cavern. Colored patches of light can be seen shining "
    "eerily through the stained glass windows of the cathedral.",
    ({ "cemetery" }) : "The Grymxoria cemetery, in the darkness, "
    "only the faint outline of large tombs can be seen.",
    ({ "hall", "town hall" }) : "A large stone block building "
    "similar in architecture to the church, but not quite as "
    "large."
  ]) );
  SetExits( ([ 
    "east" : G_ROOM + "road19",
    "west" : G_ROOM + "road17"
  ]) );
  SetInventory( ([
    G_NPC + "citizen" : 1 
  ]) );
}

