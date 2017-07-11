#include "main.h"
#include <lib.h>
 inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("disused quarters");
  SetLong("This room was obviously the sleeping quarters for the guards "
    "as there are several overturned beds with rotting mattresses. The "
    "paint is still recognizable as dark green, though the majority has"
    " flaked off over time. There is a strange, dark red stain on one "
    "of the walls, next to a curtain. There is a funny feeling about "
    "this place, as if there was something special about it.");
  SetClimate("underground");
  SetAmbientLight(1);
  SetItems( ([
    "quarters" : (:GetLong:),
    ({"paint","walls","wall"}) :
      "The walls are carved from solid rock, yet strangely smooth "
      "and unworn. The paint which covers them has mostly flaked off, "
      "yet was clearly made from a substance we have no knowledge of "
      "today.",
    ({"stain","blood"}) :
      "Closer inspection reveals this to be a spatter of blood. It "
      "has crusted over, yet must have been fairly recent to "
      "still be present.",
    "curtain" : "The curtain is of red crushed velvet and tattered.",
    ({"beds","bed","mattresses","mattress"}) :
      "The beds consist of an iron frame, which has rusted, and"
      " mattresses stuffed with some kind of birdsfeather, which"
      " has almost completely rotted. It doesn't look like anyone"
      " has been sleeping in them for quite a while.",
    ]) );
   SetItemAdjectives( ([
    "stain" : ({"blood","red","dark"}),
    "mattress" : "rotting",
    "overturned" : "beds",
    "paint" : ({"dark","green"}),
    ]) );
  SetSmell( ([
    "default" : "It smells like rotting fish in here.",
    "stain" : "The stain smells like clotted blood.",
    ]) );
  SetInventory( ([
    RNQ_NPC + "skeleton2" : 2,
    RNQ_OBJ + "scroll.c" : 1,
    ]) );
  SetSearch( ([
    "curtain" :
      "Behind the curtain there is a hidden store room.",
    ]) );
  SetExits( ([
    "east" : RNQ_RM + "guardhs.c",
    "west" : RNQ_RM + "storeroom.c",
    ]) );
  SetObviousExits("east");
}
