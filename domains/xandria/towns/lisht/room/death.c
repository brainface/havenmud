#include <lib.h>
#include "../lisht.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetShort("Someplace unpleasant");
}

void init() {
  ::init();
  if (this_player()->GetRace() == "elf") {
    this_player()->eventMove(LISHT_ROOM "elf/healer");
  }
  else this_player()->eventMove(LISHT_ROOM "gnoll/graveyard");
}
