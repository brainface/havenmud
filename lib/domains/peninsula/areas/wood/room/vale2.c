/*  5/03 Libitina  / newbie area / wooded vale  */


#include <lib.h>
#include "../wood.h"
inherit LIB_ROOM;

static void create() {
    ::create();
    SetShort("a small wooded vale");
    SetLong(
      "Beams of light dart down through the tree "
      "branches, illuminating the path in odd patterns. The trail splits "
      "to the north and east, each way overgrown with vegitation that "
      "obscures the view. The occasional pinecone sits on the ground, "
      "surrounded by needles from the trees. Small birds fly through the "
      "area, dancing around the branches."
    );
    SetSmell("default", 
      "The strong pine scent drifts on the breeze."
    );
    SetListen("default", 
      "The wind rustles the leaves."
    );
    SetItems( ([
	({"beams", "light" "branches"}) : "Golden light filters down through "	
	"the branches of the trees.",
	"vegitation" : "Various sorts of plants grow wildly at the "
	"base of the trees.",
	"pinecone" : "Small and dark in color, the pinecones fell from "
	"the several corsican pines in the forest.",
	"needles" : "Fallen from the trees, the needles cover the path.",
	"birds" : "Rather small, and too quick to see clearly... obviously "
	"not worth hunting.",
	({"path", "patterns", "trail"}) : "The light from above "
	"dances across the trail, creating distorted patterns.",
      ]) );
    SetExits( ([
	"north" : WOOD_ROOM "vale7.c",
	"east" : WOOD_ROOM "vale3.c",
	"west" : WOOD_ROOM "vale1.c",
      ]) );
    SetInventory( ([
	WOOD_NPC + "chipmunk" : 1,
      ]) );
    SetDayLight(-5);
    AddWarmth(-10);
}
