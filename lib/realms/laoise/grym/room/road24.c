#include <lib.h>
#include "../grymxoria.h"
inherit LIB_ROOM;

int BarRace(string);

static void create() {
  room::create();
  SetAmbientLight(20);
  SetTown("Grymxoria");
  SetShort("crusade court");
  SetLong(
    "The heart of the city's Merchant Quarter. "
    "Crusade court, named after the event in Nosferatu history, "
    "extends off to the east and west. To the north there is a "
    "small stone building. A sign over the door proclaims the "
    "building an armoury."
  );
  SetExits( ([ 
    "west" : G_ROOM + "road23",
    "east" : G_ROOM + "road25"
  ]) );
  SetItems( ([
    ({ "armoury", "shop", "store", "building", "small building" }) :
    "A small squat building constructed of large stone blocks.  "
    "Hung over the door is a sign reading \"Berton's Armoury\"." 
  ]) );
  SetInventory( ([
    G_NPC + "citizen" : 1 
  ]) );
  AddEnter("armoury", G_ROOM + "/armoury", (: BarRace:) );
}

int BarRace(string dir) {
    if((this_player()->GetRace() == "elf") ||
      (this_player()->GetRace() == "half-elf")) {
      write("As you enter the shop Berton takes one look "
      "at you, bellows %^BOLD%^CYAN%^"
      "'I don't serve your kind here!'%^RESET%^ and "
      "shoves you back out the door.");
    return 0;
    } else {
  return 1;
  }
}
