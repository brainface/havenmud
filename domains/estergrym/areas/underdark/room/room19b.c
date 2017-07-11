#include <lib.h>
inherit LIB_ROOM;
#include "../underdark.h"
#define UNDERDARK 0
int PreExit();

static void create() {
  room::create();
  SetClimate("underground");
  SetAmbientLight(15);
  SetShort("a large chamber");
  SetLong("The southwestern part of a large chamber. The ceiling can barely "
          "be seen and the walls stretch away into the darkness. Huge stalactites "
          "hang down from the ceiling and in some places meet with equally huge "
          "stalagmites forming giant columns of stone. A small tunnel leads off "
          "sloping steeply down to the north.");
  SetExits( ([
          "south" : U_ROOM + "room17b",
          "west" : U_ROOM + "room18b"]) );
  //AddExit("down", U_ROOM +  "room3c", (: PreExit :) );//
    AddExit("down", U_ROOM+ "room3c", (: PreExit :) );
  SetItems( ([
         "tunnel" : "A narrow tunnel sloping steeply down to the north.",
        ({ "roof", "ceiling", "stalactites" }) : "Huge stalactites cover the "
          "ceiling. Formed by hundreds of years of dripping water, they "
          "are a beautifull sight.",    
          ({ "stalagmites", "huge stalagmites" }) : "Huge stalagmites, formed "
         "by water dripping from the ceiling above over thousands of years, "
         "reach up from the floor.",
         ({ "pillars", "huge pillars" }) : "Huge pillars formed when a stalactite "
         "and its corresponding stalagmite meed. They are truly a awsome "
         "sight." ]) );
  SetSmell( ([
          "default" : "A foul smelling air flows up out of the depths."]) );
  SetInventory( ([
          U_NPC + "dwarf_soldier" : 8,
          U_NPC + "dwarf_lieutenant" : 2 ]) );
  }
int PreExit() {
        if (UNDERDARK) {
        return 1;
        } else {
                message("system","The tunnel is blocked by "
                "a cave in. Come back another time and maybe the "
                "dwarves will have cleared the rubble.",this_player());
                return 0;
  }
}
