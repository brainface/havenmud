#include <lib.h>
#include <domains.h>
#include "../undead.h"
inherit AVERATH_LIB;

varargs static void create(int x, int y, int z) {
  ::create(-10,-2,-2);
  SetShort("an underground graveyard");
  SetDomain("Averath");
  SetClimate("underground");
  SetAmbientLight(5);
  SetLong(
     "This part of the tunnel has opened up into a large underground cavern. As "
     "far as the eye can see, headstones cover the entire ground. Many graves have "
     "been defiled, while only a few still remain intact. There are fresh footprints "
     "comming out from the empty graves. "
  );
  SetItems( ([
     ({ "tunnel","cavern" }) : (: GetLong :),
     ({ "graves","headstones" }) : "A great deal of the graves have been dug up. "
     "These graves appear to have nothing left inside them, other than broken "
     "remains of coffins from long ago. ",
     ({ "footprints" }) : "These footprints appear to be fresh. They lead out from "
     "the empty graves, showing that something came out from them. ",
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
     "north" : AVERATH_ISLAND + "-10,-1,-2",
     "south" : AVERATH_ISLAND + "-10,-3,-2",
     "east" : AVERATH_ISLAND + "-9,-2,-2",
  ]) );
  }
