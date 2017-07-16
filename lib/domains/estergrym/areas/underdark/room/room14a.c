#include <lib.h>
inherit LIB_ROOM;
#include "../underdark.h"

static void create() {
  room::create();
  SetClimate("underground");
  SetAmbientLight(15);
  SetShort("a large chamber");
  SetLong("A large chamber, the unnatural darkness seems to lift a little "
          "here. It feels almost peaceful here. In the darkness the roof can "
          "barely be seen. Three tunnels branch off from here. One to the "
          "southeast, one to the southwest, and one to the northeast. There "
          "is also a small hole in the ceiling surrounded by large stalactites "
          "hanging down. A small stream of water falls down from the hole "
          "into a pool in the center of the chamber.");
  SetExits( ([
          "northeast" : U_ROOM + "room15a",
          "southwest" : U_ROOM + "room13a",
          "southeast" : U_ROOM + "room12a"]) );
  SetItems( ([
          "tunnels" : "several small tunnels branching off from the main "
          "chamber.",
          "chamber" : "A large chamber. Several tunnels branch off of it. "
          "As well as a hole in the ceiling, through which  a small stream of "
          "water flows. There is a pool of crystal clear water and large "
          "Stalactites hang down all around.",
          "hole" : "A small hole in the ceiling, nothing can be seen "
          "beond it, but fresh air is coming down through it and a small "
          "stream of water is flowing down out of it.",
          ({ "roof", "ceiling", "stalactites" }) : "Huge stalactites cover the "
          "ceiling. Formed by hundreds of years of dripping water, they are "
          "a beutifull sight.",
          ({ "water", "stream of water", "small stream of water" }) : "A small "
          "stream of clear, fresh, and presumably clean water falls down "
          "from the hole in the ceiling. It lands with a pleasant tinkling sound "
          "in the pool of water in the center of the chamber.",
          ({ "pool", "pool of water" }) : "A good sized pool of crystal clear "
          "water. The bottom of the pool is lined by algae and small aquatic "
          "funguses. A host of small aquatic snails feed on these and are in "
          "turn fed upon by several small, bulging eyed, blind fish."]) );
  SetSmell( ([
          "default" : "A fresh breeze flows in through the hole in the ceiling."]) );
  SetListen( ([
          "default" : "There is a relaxing sound of water falling into a pool."]) );
  SetInventory( ([
          U_NPC + "distraught_dwarf" : 3 ]) );
  }
