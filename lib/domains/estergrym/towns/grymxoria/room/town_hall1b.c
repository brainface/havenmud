#include <lib.h>
#include "../grymxoria.h"
inherit LIB_ROOM;

 
static void create() {
  room::create();
  SetProperty("no bump",1);
  SetClimate("indoors");
  SetAmbientLight(20);
  SetTown("Grymxoria");
  SetShort("the Town Hall of Grymxoria");
  SetLong(
    "This is a small library in the western wing of the Grymxoria "
    "town hall. Shelves of books line the walls."
  );
  SetItems( ([
    ({ "shelves" }) : "Shelves of books lined up along the walls.",
    ({ "books" }) : "Many dusty books, most seem to be about the "
    "history and language of the Nosferatu."
  ]) );
  SetInventory( ([
    G_NPC "justin" : 1,
  ]) );
  SetExits( ([ 
    "north" : G_ROOM + "church1b",
    "east" : G_ROOM + "town_hall2b",
    "down" : G_ROOM + "town_hall1a"
  ]) );
}
