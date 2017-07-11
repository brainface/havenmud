#include <lib.h>
#include "../area.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetShort("behind the wall of wood");
  SetExits( ([
    "south" : AREA_ROOM "path01",
    ]) );
  SetLong("The trees seem to grow even more dense here, with a thin path leading "
          "off to the south. Sitting in the middle of the grove here is a small, "
          "ill-kept stone building. It appears to be centuries old and unused. "
          "The path through the wood seems to end here at the base of the building.");
  SetSmell( ([
    "default" : "The tinge in the air is very coppery now.",
    ]) );
  SetListen( ([
    "default" : "Silence reigns here, overpowering any attempts at sound.",
    ]) );
  SetItems( ([
    ({ "tree", "trees" }) : "The trees are thick and foreboding here. There is "
           "a thin path through the trees to the south.",
    "path" : "The path is little more than a way to squeeze through the trees.",
    "building" : "The building is a small but well decorated work.",
    ]) );
  SetItemAdjectives( ([
    "building" : ({ "small", "ill", "kept", "stone", "unused" }),
    ]) );
  SetEnters( ([
    "building" : AREA_ROOM "shrine_entrance",
    ]) );
}
