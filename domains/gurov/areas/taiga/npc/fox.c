//Illura@Haven
//Sept 2009
//fox
#include <lib.h>
#include "../taiga.h"
inherit LIB_NPC;

static void create(){
    npc::create();
    SetKeyName("fox");
    SetId( ({"flurryfox", "fox"}) ); 
    SetAdjectives( ({"stealthy"}) );
    SetShort("a stealthy flurryfox");
    SetLong(
      "This flurryfox, native to the taiga, has patches of color "
      "in an otherwise snowy coat to help her blend almost "
      "seamlessly with her environs. She is larger than any "
      "fox you have ever seen, enough to easily take on "
      "a wolf or lynx.");
    SetRace("rodent");
    SetGender("female");
    SetClass("animal");
    SetLevel(10);
    SetAction(5, ({
    "!emote stalks the shadows.",

    "!emote twitches her noise slightly, smelling your presence.",
     "!emote turns her curious, ice-blue eyes upon you.",
                })  );
}
