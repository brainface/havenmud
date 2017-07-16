#include <lib.h>
#include <domains.h>
#include "../../lisht.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetClimate("indoors");
  SetAmbientLight(25);
  SetExits( ([
    "out" : LISHT_ROOM "elf/fp9",
    ]) );
  SetShort("in a small but clean house");
  SetLong(
    "This house is small and sparsely furnished by is clean and tidy. "
    "It is apparent that the owner has an organized mind. Sitting neatly "
    "on a shelf are several sheets of paper with odd notations. Hanging "
    "on a wall is a picture of a female elf playing a flute."
    );
  SetSmell("The smell of the floodplains barely penetrates here.");
  SetItems( ([
    ({ "sheet", "sheets", "paper" }) : "The papers seem to be musical notation and songs.",
    "picture" : "The picture portrays a female elf playing a flute.",
    ]) );
  SetInventory( ([
    LISHT_NPC "elf_bard" : 1,
    ]) );
}
