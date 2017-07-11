//coded by Syra 8/97
#include <lib.h>
#include <domains.h>
inherit LIB_NPC;
#include "../wood.h"

static void create(){
    npc::create();
    SetKeyName("tarandus");
    SetId( ({"hind","tarandus","centaur","deer"}) ); 
    SetAdjectives( ({"golden","majestic","beautiful"}) );
    SetShort("Tarandus, the golden hind");
    SetLong("Standing majestically, the golden hind is a mythical cross "
            "between a deer and a human. Its beautiful golden coat glints "
            "in the light.");
    SetRace("centaur");
    SetGender("male");
    SetClass("rogue");
    SetLevel(60);
    SetInventory( ([
              HWD_OBJ + "/goldenbow" : "wield bow",
       ]) );
}


void eventDie(object killer)
{
  object goldenhide;

  goldenhide = new(HAVENWOOD_AREAS "wood/obj/goldenhide");
  goldenhide->eventMove(this_object());
  npc::eventDie(killer);
}
