//
// valley.c
// Created by Zaxan@Haven
// 23rd of November, 1997
//

#include <lib.h>
#include "path.h"

inherit LIB_ROOM;

static void create() {
    room::create();
    SetClimate("arctic");
    SetDomain("FrostMarches");
    SetShort("a snowy valley");
    SetLong("This snowy valley is conveniently placed in the center of "
      "the mountain. Large cliffs start at the south and slowly "
      "get smaller to the north, making it easy to walk out of "
      "the valley. A small, wooden ladder to the south provides "
      "quick access to the top of the mountain. To the west, a "
      "small, deteriorating wagon sits in deep snow. To the "
      "east, a dark mine shaft drills deep into the mountain.");
    SetItems( ([ ({ "snowy valley", "valley",
	  "landscape" }) : (: GetLong :),
	({ "snow", "powder" }) : "This great white powder "
	"seems to completely control "
	"the landscape of the "
	"valley.",
	({ "large cliffs", "large cliff",
	  "cliff", "cliffs" }) : "These large "
	"cliffs are "
	"covered with "
	"rocks and snow.",
	({ "rocks on the cliff",
	  "rocks on cliff",
	  "rock", "rocks" }) : "These large rocks on the "
	"cliffs are covered with "
	"snow.",
	({ "large mountain",
	  "mountain" }) : "This large mountain dips deep into "
	"the valley and soars high into "
	"the sky.",
	({ "small, deteriorating wagon", 
	  "deteriorating wagon", "wagon",
	  "small wagon" }) : "This old wagon "
	"sits in deep "
	"snow, patiently "
	"waiting to be "
	"gobbled up by "
	"the mountain "
	"storms.",
	({ "dark mine shaft", "mine", "dark shaft", "shaft",
	  "dark mine", "mine shaft" }) : "This dark "
	"mine shaft "
	"drills deep "
	"into the "
	"mountain. It "
	"looks fairly "
	"new." ]) );
    SetObviousExits("north");
    SetExits( ([ "north" : ROOM "/mt5.c" ]) );
    SetEnters( ([ ({ "small wagon", "deteriorating wagon", "wagon",
          "small, deteriorating wagon" }) : ROOM "/wagon",
	({ "mine shaft", "mine", "dark shaft", "shaft",
	  "dark mine", "dark mine shaft" }) : ROOM "/mine"]));
    SetInventory( ([ NPC "/caribou" : random(3)+1,
	NPC "/bear" : random(3)+1,
	NPC "/explorer" : random(2),
	OBJ "/ladder2" : 1 ]) );
}
