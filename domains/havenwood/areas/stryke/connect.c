/*  The connection room that attachs Stryke's lair to the HavenWood.
 */
#define STRYKE 1
#include <lib.h>
#include <domains.h>
#include "stryke.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("an open glen in the HavenWood");
  SetDomain("HavenWood");
  SetObviousExits("southeast, down");
  SetExits( ([
     "southeast" : HAVENWOOD_AREAS "wood/rooms/wood1",
      ]) );
  SetInventory( ([
     STRYKE_OBJ + "sign" : 1,
     ]) );
  SetLong("The glen is a peaceful place, with trees and various plants "
          "growing freely in the area.  To the southeast is the main "
          "section of the HavenWood, while in the middle of the glen "
          "is a large mound that look as if it might have a hole leading "
          "down into the earth.");
  SetSmell( ([
     "default" : "The smells of the forest make this glen pleasant.",
      ]) );
  SetListen( ([
      "default" : "The sounds of animal life chitter in the background.",
      ]) );
  SetItems( ([
      "mound" : "The mound appears to have a hole leading down, but "
                "sometimes it is blocked.",
     ({ "tree", "trees" }) : "The trees are the normal, if large, HavenWood "
                             "variety.",
       ]) );
  if (STRYKE)
       AddExit("down", "lair/1_a");
  }
