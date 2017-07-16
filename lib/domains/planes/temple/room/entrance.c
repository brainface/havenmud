/*  Entrance to the Lamrani Temple */
#include <lib.h>
#include "../temple.h"
inherit LIB_ROOM;
int out_hook(string dir);

static void create() {
  ::create();
  SetClimate("indoors");
  SetProperty("lower plane", 1);
  SetAmbientLight(35);
  SetExits( ([
     "east" : TEMPLE_ROOM "e1",
     "south" : TEMPLE_ROOM "s1",
    ]) );
  AddExit("out", FIRST_PLANE "-6,1", (: out_hook :) );
  SetShort("inside the black temple");
  SetLong("From inside, the temple appears even more bleak and "
         "unpleasant. Hallways lead off to both the south and "
         "east, and neither direction seems much different than "
         "the other. Outside is the dull grey nothingness that "
         "is a lower plane. Along the walls are various symbols "
         "which denote death in all its forms.");
  SetItems( ([
    ({ "symbol", "symbols" }) : "The symbols of death and despair "
                                "that line the walls are graphic, "
                                "but not evil looking.",
    ({ "wall", "walls" }) : "The walls are covered in symbols of death.",
    ]) );
  SetSmell( ([
      "default" : "The smell of incense is overpowering.",
    ]) );
  SetListen( ([
      "default" : "The sounds of chanting come from the south.",
    ]) );
  SetInventory( ([
      TEMPLE_NPC "lamrani1" : 2,
    ]) );

 }

int out_hook(string dir) {
  if (this_player()->id("lamrani_temple_npc")) return 0;
  return 1;
 }
