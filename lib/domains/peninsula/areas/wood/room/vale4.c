/*  5/03 Libitina / newbie area / wooded vale  */


#include <lib.h>
#include "../wood.h"
inherit LIB_ROOM;

static void create() {
    ::create();
    SetShort("a small wooded vale");
    SetLong(
      "Tall corsican pine trees blow gently in the breeze. Birds hop "
      "from branch to branch, gathering twigs for their nests or "
      "just looking for something to do. The underbrush is thick, and "
      "has been trampled recently. Flowers and berries lie smashed "
      "on the narrow path."
    );
    SetSmell("default", 
      "The sweet tang of berries mixes with the pince scent."
    );
    SetItems( ([
	({"trees", "pine trees"}) : "One of the most plentiful pine "
	"trees in Rome, the corsican pine is quite lovely.",
	"birds" : "Many birds, such as robins, make their homes here.",
	({ "branch", "branches" }) : "The branches of the trees reach out "
	"towards each other, wearing clusters of needles.",
	({"twigs", "nests"}) : "Fresh pine needles make wonderful nests.",
	({ "path", "flowers", "berries", "underbrush"}) : "The plants "
	"have been trampled, creating this narrow pathway. The white "
	"flowers and berries lie on the floor, smashed and forgotten."
      ]) );
    SetListen("default", 
      "It's almost quiet, except for a rustle here and there."
    );
    SetExits( ([
	"northwest" : WOOD_ROOM "vale6.c",
	"southwest" : WOOD_ROOM "vale3.c",
      ]) );
    SetInventory( ([
	WOOD_NPC "hunter.c" : 1
      ]) );
    SetDayLight(-5);
    AddWarmth(-10);
}
