#include <lib.h>
#include "../grymxoria.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("sub-arctic");
  SetAmbientLight(20);
  SetTown("Grymxoria");
  SetShort("Crusade court");
  SetLong(
    "This is the heart of Grymxoria's merchant quarter. Crusade court, "
    "named after the event in nosferatu history, extends off to the "
    "east and meets with Blood River road to the west. North of here "
    "sits a building with a sign above the door depicting a beer stein."
  );
  SetItems( ([
    ({ "building", "bar", "tavern" }) :
    "A building stands to the north with a sign above its door which shows "
    "a full beer stein and appears to house a tavern.",
    ({ "sign" }) :
    "The sign suggests this might be a place to purchase alcohol.",
  ]) );
  SetExits( ([
    "west" : G_ROOM + "road26",
    "east" : G_ROOM + "road28"
  ]) );
  SetEnters( ([
    "bar" : G_ROOM + "tavern",
  ]) );
}
