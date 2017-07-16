#include <lib.h>
inherit LIB_INVASION;
#define pirdir "/domains/westwood/invasions/ogre_soleil"
#define startspot "/domains/westwood/towns/soleil/room/gate"

static void create() {   
  invasion::create();
  SetLeader(pirdir + "/leader");
  SetInvaders( ([
    pirdir + "/ogre1" : 17,
    pirdir + "/ogre2" : 17,
    pirdir + "/ogre3" : 5,
  ]) );
  SetStartLocation(startspot);
  SetMessages( ([
    "announce" : "Ogres have come to attack Soleil!",
    "leader_died" : "The shaman has been killed!",
    "defeated" : "Soleil has beaten back the invasion!"
  ]) );
  SetPlayerTitle("the Defender of the Joyful");
  SetDomain("westwood");
}
