#include <lib.h>
inherit LIB_INVASION;
#define DEMON "/domains/westwood/invasions/demon/"
#define START "/domains/westwood/virtual/westwood/0,0"

static void create() {   
  invasion::create();
  SetLeader(DEMON + "pf_leader");
  SetInvaders( ([
    DEMON + "black_abashai" : 20,
    DEMON + "barbed" : 10,
    DEMON + "bane" : 5,
    DEMON + "lemure" : 25,
    DEMON + "maralith" : 10,
  ]) );
  SetStartLocation(START);
  SetMessages( ([
    "announce" : "A third wave of demons has entered the WestWood from the southwest!",
    "leader_died" : "The leader of the demon army has fallen!",
    "defeated" : "The demon army has been routed and lies in ruins!",
  ]) );
  SetDomain("WestWood");
}
