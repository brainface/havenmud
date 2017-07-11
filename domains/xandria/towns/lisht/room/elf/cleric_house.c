// updated lib chapel 2/june/2017 torak@haven

#include <lib.h>
#include <domains.h>
#include "../../lisht.h"
inherit LIB_CHAPEL;

static void create() {
  ::create();
  SetClimate("indoors");
  SetAmbientLight(35);
  SetShort("inside the Priest's house");
  SetExits( ([
    "out" : LISHT_ROOM "elf/ra3",
    ]) );
  SetSmell("A faint smell of old incense lazily drifts in the air.");
  SetInventory( ([
    LISHT_NPC "elf_priest" : 1,
    ]) );
  SetReligion("Anteky");
  SetLong(
    "This small building serves as the home of the local Priest of Anteky. "
    "The room is neat and tidy, if small. A small sleeping pallet in a corner "
    "shows the modesty of the occupant. A wooden table in the middle of the room "
    "serves as an altar, and has several incense sticks on it."
    );
  SetItems( ([
    "pallet" : "The sleeping pallet is poor but tidy.",
    "altar"  : "The altar is plain and unadorned.",
    "incense": "The incense appears to be already burnt.",
    ]) );
  SetItemAdjectives( ([
    "pallet" : ({ "sleeping" }),
    ]) );
}
