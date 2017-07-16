//Illura@Haven
//Nov 2010
#include <lib.h>
#include "../oil.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("lizard");
  SetShort("a deformed lizard");
  SetId( ({"lizard"}) );
  SetAdjectives( ({"deformed"}) );
  SetLong(
    "This little lizard slithers in the sands on her belly, which "
    "is distended and strange looking. Her tail is also overly "
    "long, and her head is misshapen. There is something "
    "very wrong with this large lizard, which seems wary of "
    "both you and her surroundings."
    );
  SetRace("lizard");
  SetClass("animal");
 SetLevel(10);
 SetGender("male");
 SetAction(5, ({
    "!emote slithers.",
    "!emote croaks loudly.",
    "!emote hisses at you dangerously."
  }) );
}
