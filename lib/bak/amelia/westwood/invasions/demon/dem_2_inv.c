#include <lib.h>
inherit LIB_INVASION;
#define DEMON "/domains/westwood/invasions/demon/"
#define START "/domains/westwood/virtual/westwood/29,0"

static void create() {   
  invasion::create();
  SetLeader(DEMON + "pf_leader");
  SetInvaders( ([
    DEMON + "black_abashai" : 10,
    DEMON + "barbed" : 5,
    DEMON + "bane" : 3,
    DEMON + "lemure" : 15,
    DEMON + "maralith" : 5,
  ]) );
  SetStartLocation(START);
  SetMessages( ([
    "announce" : "A second wave of demons has entered the WestWood from the southeast!",
    "leader_died" : "The leader of the second wave has fallen!",
    "defeated" : "The second wave has been destroyed!",
  ]) );
  SetDomain("WestWood");
}
