#include <lib.h>
inherit LIB_INVASION;
#define DEMON "/domains/westwood/invasions/demon/"
#define START "/domains/westwood/virtual/westwood/29,29"

static void create() {   
  invasion::create();
  SetLeader(DEMON + "pf");
  SetInvaders( ([
    DEMON + "black_abashai" : 10,
    DEMON + "barbed" : 5,
    DEMON + "bane" : 3,
    DEMON + "lemure" : 15,
    DEMON + "maralith" : 5,
  ]) );
  SetStartLocation(START);
  SetMessages( ([
    "announce" : "A hoard of demons has entered the WestWood from the northeast!",
    "leader_died" : "The leader of the first wave has fallen!",
    "defeated" : "The first wave of demons has been destroyed!",
  ]) );
  SetDomain("WestWood");
}
