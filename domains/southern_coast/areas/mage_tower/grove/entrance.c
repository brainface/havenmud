/*  The entrance to the Grove of Terror */
#include "../mage_tower.h"
#include <domains.h>
#define HAVEN  SOUTHERN_COAST_TOWNS "haven/room/imperial_road/ir1"
inherit LIB_GROVE;

static void create() {
  ::create();
  SetExits( ([
     "south" : HAVEN,
     "north" : TOWER_GROVE "path1",
    ]) );
  SetShort("the entrance to the Tower Grove");
  SetClimate("arctic");
  SetDayLight(-20);
  SetNightLight(-20);
  SetInventory( ([
    TOWER_NPC "wraith" : 3,
    ]) );
  SetLong("The entrance to the grove is a terrifying and mind-numbing "
          "place filled with horrors. Its dark wood seems to be turned "
          "as if to defend the tower at all costs, while the trees "
          "themselves look to be warped and twisted in mute rage against "
          "the evils conducted here since the GodsWar. A trail here "
          "leads off towards the tower, while off to the south the "
          "gate leading back onto the warm streets of Haven Town lies "
          "beckoning the weak at heart.");
  SetSmell( ([
      "default" : "A smell of lingering death attacks the senses.",
     ]) );
  SetListen( ([
      "default" : "The wail of the undead guardians of the tower echoes.",
     ]) );
  SetItems( ([
     ({ "tree", "trees", "wood" }) : "The trees are terrible guardians of "
                                     "evil grove.",
     ({ "gate", "south", "street", "streets" }) : "The streets of "
                                     "Haven Town seem very inviting.",
     ({ "tower" }) : "The tower itself rises like a dark and evil "
                     "spire against the Gods, defying even them to "
                     "tread upon the haunted grounds of the tower.",
     ({ "grove" }) : (: GetLong() :),
      ]) );
  }
