#include <lib.h>
inherit LIB_INVASION;
#define DEMON "/domains/westwood/invasions/demon/"
#define START "/domains/westwood/virtual/westwood/26,25"

static void create() {   
  invasion::create();
  SetLeader(DEMON + "barbed");
  SetInvaders( ([
    DEMON + "black_abashai" : 5,
  ]) );
  SetStartLocation(START);
  SetMessages( ([
    "announce" : "A scouting party of demons has entered the WestWood!",
    "leader_died" : "The leader of the demon scouting party has fallen!",
    "defeated" : "The demon scouting party has been destroyed!",
  ]) );
}
