// Monastery
// Aerelus
// 06/05/2006

#include <lib.h>
#include <domains.h>
#include "../monastery.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetAmbientLight(30);
  SetClimate("indoors");
  SetShort("a large dormitory");
  SetLong(
    "This room is where the monks spend the night. There are many plain-"
    "looking wooden beds arranged in rows. Each has a blanket, pillow and "
    "little else, showing how the monks place little value in material "
    "possessions, focusing on the study of their faith.  There is a "
    "bookshelf against the southern wall, containing tomes of Kylin "
    "knowledge. To the east, an archway leads out into the garden."
  );
  SetItems( ([
  ({ "room" }) : (: GetLong :),
  ({ "beds" }) :
    "The beds are neatly arranged in rows. ",
  ({ "blanket", "pillow" }) :
    "Each bed has a blanket and a pillow. ",
  ({ "bookshelf", "tomes", "books", "shelf" }) :
    "The bookshelf is filled with books for the monks to study in their "
    "spare time.",
  ({ "archway" }) :
    "The archway leads east into the garden.",
  ({ "garden" }) :
    "There is a beautiful garden beyond the eastern archway.",
  ({ "wall" }) :
    "There is a bookshelf against the southern wall.",
  ]) );
  SetItemAdjectives( ([
    "beds" : ({ "plain", "plain-looking", "wooden" }),
    "wall" : ({ "southern" }),
    "tomes" : ({ "kylin" }),
  ]) );
  SetInventory( ([
    AREA_NPC "monk" : 2,
  ]) );
  SetListen( ([
    "default" : "The sounds of deep chanting can be heard.",
  ]) );
  SetSmell( ([
    "default" : "The smell of plant life blows into the dormitory from the "
    "east.",
  ]) );
  SetExits( ([
    "east" : AREA_ROOM "garden",
  ]) );
}
