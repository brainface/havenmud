#include <lib.h>
#include "../area.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetShort("a small path off the Via Esteros");
  SetLong("A small path curves off the Via Esteros here, leading off the "
          "road and into a small grove. Back to the south, the Via Esteros "
          "runs east and west, connecting the various parts of the Empire "
          "with each other. Small trees line the path, almost hesitant to "
          "intrude along the pathway. The path continues to the north.");
  SetItems( ([
    ({ "tree", "trees" }) : "The trees here are small and seem to deliberately "
                "be planted away from the pathway.",
    ]) );
  SetSmell( ([
    "default" : "The scent of tree sap fills the air in a healthy manner.",
    ]) );
  SetListen( ([
    "default" : "Birds chirp merrily in the trees.",
    ]) );
  SetExits( ([
    "south" : "/domains/peninsula/towns/sanctum/room/rd05",
    "north" : AREA_ROOM "path01",
    ]) );
}
