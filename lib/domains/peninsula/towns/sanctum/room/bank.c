#include <lib.h>
#include "../rome.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetShort("inside the Sanctum Moneychanger's");
  SetExits( ([ 
    "out" : ROME_ROOM "rd01",
    ]) );
  SetWarmth(50);
  SetAmbientLight(40);
  SetClimate("indoors");
  SetSmell( ([
    "default" : "The room has a pleasant smell of incense.",
    ]) );
  SetListen( ([
    "default" : "The moneychanger maintains a somber tone of quiet.",
    ]) );
  SetLong("The office of the moneychanger of Sanctum is a very "
          "dignified estate. Around the room, various scrolls neatly "
          "fill bookshelves, some detailing deposits, some withdrawls. "
          "A large marble desk sits along the north wall, lying near "
          "a huge window overlooking a stately garden.");
  SetItems( ([
    ({ "scroll", "scrolls" }) : "The scrolls of parched vellum seem to "
           "be records of the business of the Moneychanger.",
    ({ "bookshelf", "bookshelves" }) : "These large stone bookshelves "
           "are filled with scrolls.",
    ({ "desk" }) : "This huge marble desk is lined with inlaid gold "
                   "and other precious minerals. Surely it cost a small "
                   "fortune.",
    ]) );
  SetInventory( ([
    ROME_NPC "banker" : 1,
    ]) );
}
