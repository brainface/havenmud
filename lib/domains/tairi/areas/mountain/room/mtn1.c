
//Selket@Haven
//2006

#include <lib.h>
#include <domains.h>
#include "../mtn.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("at the base of Shatadru Mountain");
  SetLong(
    "Here stands a tall and famed mountain, to where those seeking "
    "enlightenment journey. A winding path starts here, trailing "
    "up the sloping face of the mountain. To the northeast lies the "
    "small Tairi road which leads from the mountain to the city."
  );
  SetItems( ([
    ({ "mountain" }) : 
    "Shatadru Mountain is high, and the path up it seems quite "
    "treacherous for anyone but an experienced climber.",
    ({ "path" }) : 
    "The old path winds around the sides of the mountain, "
    "presumably leading to the summit. ",
    ({ "summit", "cloudbank" }) : 
    "The summit is far above, obscured by silvery clouds. ",
  ]) );
  SetExits( ([
    "up" : MTN_ROOM "/mtn2",
    "northeast" : TAIRI_VIRTUAL "tairi_path/-20,-8",
    "south" : "/domains/tairi/areas/hermitage/room/outside",
  ]) );
  SetListen("The wind whistles coolly around the mountain.");
  SetSmell("The air is scented with a fresh mountain fragrance.");
}
