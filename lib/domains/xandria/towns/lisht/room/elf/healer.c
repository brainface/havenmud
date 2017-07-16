#include <lib.h>
#include <std.h>
#include <domains.h>
#include "../../lisht.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetClimate("indoors");
  SetAmbientLight(35);
  SetExits( ([
    "out" : LISHT_ROOM "elf/ra2",
    ]) );
  SetShort("within the home of Joseph the Healer");
  SetInventory( ([
     STD_OBJ "reztotem" : 1,
    LISHT_NPC "elf_healer" : 1,
    ]) );
  SetLong(
    "This comfortable home is arranged as an obvious makeshift hospital. "
    "Several small sleeping pallets are arranged against a wall to tend "
    "to the elves that may have injuries. Small cloths are neatly stacked "
    "by each pallet to insure a supply of bandage material, and a cabinet "
    "appears to hold some medicinal supplies."
    );
}
