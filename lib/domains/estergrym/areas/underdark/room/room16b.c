#include <lib.h>
inherit LIB_ROOM;
#include "../underdark.h"

static void create() {
  room::create();
  SetClimate("underground");
  SetAmbientLight(15);
  SetShort("a large chamber");
  SetLong("The southwestern part of a large chamber. The ceiling can barely "
          "be seen and the walls stretch away into the darkness. Huge stalactites "
          "hang down from the ceiling and in some places meet with equally huge "
          "stalagmites forming giant columns of stone. A small tunnel leads away "
          "up to the south.");
  SetExits( ([
          "north" : U_ROOM + "room18b",
          "south" : U_ROOM + "room15b",
          "east" : U_ROOM + "room17b"]) );
  SetItems( ([
          "tunnel" : "A narow sloping tunnel. It runs off up to the south.",
        ({ "roof", "ceiling", "stalactites" }) : "Huge stalactites cover the "
          "ceiling. Formed by hundreds of years of dripping water, they "
          "are a beautifull sight.",    
          ({ "stalagmites", "huge stalagmites" }) : "Huge stalagmites, formed "
         "by water dripping from the ceiling above over thousands of years, "
         "reach up from the floor.",
         ({ "pillars", "huge pillars" "columns"}) : "Huge pillars formed when a stalactite "
         "and its corresponding stalagmite meed. They are truly a awsome "
         "sight." ]) );
  SetSmell( ([
          "default" : "A foul smelling air flows up out of the depths."]) );
  }
