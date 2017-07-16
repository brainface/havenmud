/*  First Floor, Room One of the Tower */
#include <lib.h>
#include "../mage_tower.h"
inherit LIB_ROOM;
int OutExit(string);

static void create() {
  
  ::create();
  SetProperty("no teleport", 1);
  SetProperty("no teleport", 1);
  SetClimate("indoors");
  SetShort("inside the Mage Tower");
  SetExits( ([
     "east" : "1-2",
     "north"  : "1-6",
    ]) );
  AddExit("out", TOWER_GROVE "path2", (: OutExit :) );
  SetLong("The tower is a dark and twisted place, long avoided by "
          "the civilized folk of Haven Town. In the south wall of "
          "this section of the Tower are two large blackened doors "
          "which seem to lead back out into the horrid grove which "
          "protects the tower from trespassers. To the east, the hall "
          "continues along the outer edges of the tower, not yet leading "
          "into its heart, while to the north the hallway seems to "
          "decline slightly into the earth. A thick layer of dust "
          "covers everything, giving the honest appearance of a place "
          "which has lain unmolested for centuries.");
  SetItems( ([
     ({ "dust", "layer" }) : "The dust is thick and oppressive.",
     ({ "doors", "door" }) : "The doors are huge metal things which "
                             "long ago lost any hope of being "
                             "beautiful.",
     ]) );
  SetListen( ([
    "default" : "The still quiet of the ages rests the air.",
    ]) );
  SetSmell( ([
     "default" : "The smell of rot and dust chokes off your senses.",
    ]) );
  }

int OutExit(string dir) {
  if (this_player()->id("tower_wander")) return 0;
  else return 1;
  }
