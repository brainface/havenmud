/*  5/03 Libitina / newbie area / wooded vale  */

#include <lib.h>
#include "../wood.h"
inherit LIB_ROOM;

static void create() {
    ::create();
    SetShort("a small wooded vale");
    SetLong(
      "The main trail leads west and south here. A smaller path "
      "heads southwest. Light filters through the tree branches, casting "
      "a hazy glow through the area. The trunks of the trees stand tall, with "
      "the occasional squirrel dashing upwards. Pine needles litter the "
      "ground with a pine cone here and there. "
    );
    SetItems( ([
	"trail" : "The mail trail leads west and south.",
	"path" : "An overgrown path leads southwest",
	"branches" : "Covered in clusters of pine needles, they allow a decent "
	"amount of light to dart through.",
	"area" : "This is a small wooded vale.",
	"trunks" : "The pine trees are big, but not overly huge. The trunks "
	"average "
	"about two or three feet in diameter.",
	"squirrel" : "Small animals love this peaceful area.",
	({"needles", "pine needles"}) : "Pine needles fall to the ground.",
	({"pinecones", "pine cone", "pine cones", "pinecone"}) : "Long "
	"slender cones fall from the trees carrying seeds."
      ]) );
    SetSmell("default", 
      "The rich scent of pine fills the air."
    );
    SetListen("default", 
      "The forest is filled with the quiet sounds of life."
    );
    SetExits( ([
	"west" : WOOD_ROOM "vale8.c",
	"south" : WOOD_ROOM "vale2.c",
	"southwest" : WOOD_ROOM "vale1.c"
      ]) );
    SetInventory( ([ WOOD_NPC "squirrel.c" : 1 ]) );
    SetDayLight(-5);
    AddWarmth(-10);
}
