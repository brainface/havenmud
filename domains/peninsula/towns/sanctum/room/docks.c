#include <lib.h>
#include <domains.h>
#include "../rome.h"
#include <std.h>
inherit LIB_FISHING;

int PreExit();

static void create() {
        ::create();
  SetShort("the Sanctum docks and wharf");
  SetProperty("coastal", 1);
  SetExits( ([
          "north" : ROME_ROOM "vi08",
          ]) );
  AddExit("south",INNERSEA_VIRTUAL + "ocean/-32,-12",(: PreExit :) );
  SetLong("The Inner Sea reaches out and touches the city of Sanctum "
          "here.  Stone docks jut out into the sea, making docking "
          "large boats here fairly easy. Off to the north, "
          "the Via Imperialis leads into the city of Sanctum. "
          "The reddish waters of the Ruined Sea beckon to the "
          "foolhardy traveller.");
        SetItems( ([
          "road" : "The road is made of small to medium sized pieces of stone. "
                   "It continues to the north.",
    ({ "stone", "stones" }) : "The stones are normal, but well smoothed, "
             "pieces of rock layed out for ease of travel.",
     ({ "dock", "docks" }) : "The docks are wooden and stone structures "
                             "jutting out into the sea as a challenge. There is "
                             "hole in one of the docks about big enough to fit a human.",
        "hole" : "It looks like the hole has handles to allow someone to enter it. ",
    ]) );
  SetItemAdjectives( ([
    "stone" : ({ "piece", "of", "pieces" }),
    ]) );
  SetInventory( ([
    ROME_NPC "hugh" : 1,
    ROME_OBJ "strireme" : 2,
    ROME_NPC "t_fisher" : 1,
    ]) );
  SetSmell( ([
    "default" : "The smell of the sea wafts from the south.",
    ]) );
  SetListen( ([
    "default" : "The sounds of the city swell from the north.",
    ]) );
  SetMaxFishing(10);
  SetFish( ([
    STD_FISH "guppy" : 100,
    STD_FISH "trout" : 50,
    STD_FISH "boot" : 1,
    ]) );
  SetChance(25);
  SetSpeed(5);
  SetEnters( ([
    "hole" : ROME_ROOM "guild1",
    ]) );
}



int PreExit() {
  if (this_player()->id("wander")) {
    if (this_player()->GetOwner() == "")
      return 0;
    }
  return 1;
}
