// Coded by Zeratul
// 1-20-2000
// Ninja tower path9
#include <lib.h>
#include "../ninja.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  
  SetShort("on a path outside a tower");
  SetLong(
     "The path ends here, leading up to a tower which stands here. The path "
     "leads back down to the town to the west. The path is lined with "
     "flowers here which bloom in the always pleasant valley lands of Tai. "
  );
  SetItems( ([
     ({"tower","building"}) : "The tower is a tall and imposing sight on this "
     "path. It is remote from the rest of the town, off up here in the "
     "northeastern part of the town. ",
     ({"flowers"}) : "The path is lined with flowers here which bloom in the "
     "always pleasant valley lands of Tai. ",
  ]) );
  SetItemAdjectives( ([
     "tower" : ({"large"}),
  ]) );
  SetSmell( ([
     "default" : "The scent of flowers is mixed with incense here.",
  ]) );
  SetListen( ([
     "default" : "The path is peaceful and quiet.",
  ]) );
  SetInventory( ([
  ]) );
  SetEnters( ([
     "tower" : N_ROOM + "tower1",
  ]) );
  SetExits( ([
     "west" : N_ROOM + "n_path8",
  ]) );
  }
