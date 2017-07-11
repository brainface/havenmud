#include <lib.h>
#include "../grymxoria.h"
inherit LIB_ROOM;

int BarRace(string);

static void create() {
  room::create();
  SetClimate("sub-arctic");
  SetAmbientLight(20);
  SetTown("Grymxoria");
  SetShort("crusade court");
  SetLong(
    "The heart of the city's merchants quarter. "
    "Crusade court, named after the event in Nosferatu history, "
    "extends off to the east and west. To the north there is a "
    "small stone building. A sign over the door proclaims the "
    "building an armoury."
  );
  SetItems( ([
    ({ "armoury", "shop", "store", "building", "small building" }) :
    "A small squat building constructed of large stone blocks. "
    "Hung over the door is a sign reading \"Berton's Armoury\"." 
  ]) );
  SetInventory( ([
    G_NPC + "citizen" : 1 
  ]) );
  SetExits( ([ 
    "west" : G_ROOM + "road23",
    "east" : G_ROOM + "road25" 
  ]) );
  AddEnter("armoury", G_ROOM + "armoury");
}
 