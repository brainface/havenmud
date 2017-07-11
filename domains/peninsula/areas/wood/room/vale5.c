/* 5/03 Libitina / newbie area / wooded vale */


#include <lib.h>
#include "../wood.h"
inherit LIB_ROOM;

static void create() {
    ::create();
    SetShort("a small wooded vale");
    SetLong(
      "The well-trodden path leads north and south. Beams of light "
      "pierce through the canopy overhead. Small rocks mix with the "
      "needles and pinecones, although they've been kicked off to the "
      "side. Small forest creatures peek out from their hiding spots "
      "curiously."
    );
    SetItems( ([
	"path" : "Only about two feet wide, its not the best forest trail, but "
	"obviously someone or something uses it often enough.",
	({ "light", "canopy" }) : "Light from above dances its way through the "
	"canopy of tree branches.",
	({ "rocks", "needles", "pinecones" }) : "Typical of what you would "
	"find on a path in such a forest, although whoever or whatever "
	"uses this path kicks the majority of the rocks to the edge "	
	"of the trail.",
	"creatures" : "Every now and then a furry head peeks around a tree, "
	"or out from under a bush.",
      ]) );
    SetSmell("default", 
      "An invigorating pine fragrance dances through the air."
    );
    SetListen("default", 
      "The plants rustle occasionally."
    );
    SetExits( ([
	"north" : WOOD_ROOM "vale6.c",
	"south" : WOOD_ROOM "vale3.c"
      ]) );
    SetDayLight(-5);
    AddWarmth(-10);
}
