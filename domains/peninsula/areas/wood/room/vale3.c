/* 5/03 Libitina / newbie area / wooded vale  */


#include <lib.h>
#include "../wood.h"
inherit LIB_ROOM;

static void create() {
    ::create();
    SetShort("a small wooded vale");
    SetLong(
      "Branches from the trees hang low overhead. A needle or "
      "pinecone drops occasionally to the ground. The path curves "
      "northward, since a large boulder is blocking the way to "  
      "the east. A small path has been trampled into the bushes "
      "to the northeast.");
    SetItems( ([ 
      ({ "branches", "trees" }) : 
      "The corsican pine trees that grow in this area have sprawling branches "
      "covered in needles and cones.",
      "needles" : 
      "Long, thin needles from the trees fall to the ground.",
      "pinecones" : 
      "Slender pinecones grow on the branches, sometimes dropping to the ground.",
      "path" : 
      "The main path leads north and west. A smaller path leads northwest and "
      "doesnt look used too often.",
      "boulder" : 
      "A large rock, about seven feet tall sits oddly out of place.",
      "bushes" : 
      "The bushes nearby have been trampled and broken, creating a path to "
      "the northeast.",
      ]) );
    SetSmell("default", 
      "The fresh scent of pine hovers in the air."
       );
    SetListen("default", 
      "It is oddly quiet."
      );
    SetExits( ([
      "north"     : WOOD_ROOM "vale5.c",
      "west"      : WOOD_ROOM "vale2.c",
      "northeast" : WOOD_ROOM "vale4.c",
      ]) );
    SetInventory( ([
      WOOD_NPC + "squirrel" : 1,
      ]) );
    SetDayLight(-5);
    AddWarmth(-10);
}
