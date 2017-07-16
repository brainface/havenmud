#include <lib.h>
#include <domains.h>
#include "../undead.h"
inherit AVERATH_LIB;
int CheckId();


varargs static void create(int x, int y, int z) {
  ::create(-8,-1,-2);
  SetShort("an underground graveyard");
  SetDomain("Averath");
  SetClimate("underground");
  SetAmbientLight(5);
  SetLong(
     "This part of the tunnel has opened up into a large underground cavern. As "
     "far as the eye can see, headstones cover the entire ground. Many graves have "
     "been defiled, while only a few still remain intact. There are fresh footprints "
     "comming out from the empty graves. A small crevice resides in the corner "
     "of the cavern. "
  );
  SetItems( ([
     ({ "tunnel","cavern" }) : (: GetLong :),
     ({ "graves","headstones" }) : "A great deal of the graves have been dug up. "
     "These graves appear to have nothing left inside them, other than broken "
     "remains of coffins from long ago. ",
     ({ "footprints" }) : "These footprints appear to be fresh. They lead out from "
     "the empty graves, showing that something came out from them. ",
     ({ "crevice" }) : "The crevice appears to lead into a cavern below. ",
  ]) );
  SetItemAdjectives( ([
     "cavern" : ({ "large","open" }),
     "graves" : ({ "defiled" }),
     "footprints" : ({ "fresh" }),
  ]) );
  SetListen( ([
     "default" : "It is disturbingly quiet and calm. ",
  ]) );
  SetSmell( ([
     "default" : "The air smells old and unclean. ",
  ]) );
  SetInventory( ([
  ]) );
  SetExits( ([
     "south" : AVERATH_ISLAND + "-8,-2,-2",
     "west" : AVERATH_ISLAND + "-9,-1,-2",
  ]) );
  AddExit("down", AVERATH_ISLAND + "-8,-1,-3", (: CheckId :));
  }


int CheckId() {
  if (this_player()->id("guard_shrine")) return 0;
  return 1;
  }
