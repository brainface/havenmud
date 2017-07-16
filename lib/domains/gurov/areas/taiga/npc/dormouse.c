//Illura@Haven
//Sept 2009
//dormouse
#include <lib.h>
#include "../taiga.h"
inherit LIB_NPC;

static void create(){
    npc::create();
    SetKeyName("dormouse");
    SetId( ({"mouse", "dormouse"}) ); 
    SetAdjectives( ({"fat"}) );
    SetShort("a fat dormouse");
    SetLong("The fat, sleepy dormouse has enormous eyes that "
      "dart around, watching for predators who would make "
      "him into an easy meal.");
    SetRace("rodent");
    SetGender("male");
    SetClass("animal");
    SetLevel(2);
    SetAction(5, ({
    "!emote chitters worriedly.",
     "!emote squeaks in alarm.",
    "!emote scurries into the underbrush and out again.",
                })  );
}
