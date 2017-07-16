#include <lib.h>
#include "ginvade.h"

inherit LIB_INVASION;

static void create() {   
invasion::create();
SetLeader(GOBLIN_DIR + "orc_leader");
SetInvaders( ([
        GOBLIN_DIR + "goblin_mercenary" : 5,
        GOBLIN_DIR + "goblin_soldier2" : 15,
]) );
SetStartLocation("/domains/westwood/towns/soleil/room/gate");
SetMessages( ([
        "announce" : "An invasion force of goblins approaches Soleil!",
        "leader_died" : "The leader of the invasion has been killed!",
        "defeated" : "Soleil is once again safe!",
]) );
SetPlayerTitle("Defender of Soleil");
SetDomain("WestWood");
}
