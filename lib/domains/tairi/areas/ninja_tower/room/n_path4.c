// Coded by Zeratul
// 1-20-2000
// Ninja tower path4
#include <lib.h>
#include "../ninja.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  
  SetShort("on a path leading to a tower");
  SetLong(
     "The path here leads upwards in the northwestern direction. A tower can "
     "be seen to the northwest, while the Taisoka Temple is seen to "
     "the southwest. The path is lined with flowers here which bloom in the "
     "always pleasant valley lands of Tai. "
  );
  SetItems( ([
     ({"buildings"}) : "The buildings to the southwest are small and wood "
     "framed with paper walls. One building appears to be some kind of office, "
     "while the other one is the Taisoka Temple.",
     ({"tower","building"}) : "The tower is a tall and imposing sight on this "
     "path. It is remote from the rest of the town, off up in the northeastern "
     "direction. ",
     ({"flowers"}) : "The path is lined with flowers here which bloom in the "
     "always pleasant valley lands of Tai. ",
     ({"temple","building"}) : "The Taisoka Temple is a small wooden "
     "building with paper walls that are well maintained.",
     ({"office","building"}) : "The local post office is a dull building of "
     "little charm.",
  ]) );
  SetItemAdjectives( ([
     "office" : ({"dull","local","post"}),
     "temple" : ({"humble"}),
     "tower" : ({"large"}),
  ]) );
  SetSmell( ([
     "default" : "the scent of flowers is mixed with incense here.",
  ]) );
  SetListen( ([
     "default" : "The path is peaceful and quiet.",
  ]) );
  SetInventory( ([
  ]) );
  SetExits( ([
     "northwest" : N_ROOM + "n_path5",
     "southwest" : N_ROOM + "n_path3",
  ]) );
  }
