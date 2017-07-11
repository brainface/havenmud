#include <lib.h>
#include "../lumber.h"
inherit LIB_NPC;
static void create() {
  npc::create();
    SetKeyName("fur trader");
    SetShort("a fur trader");
    SetId( ({"trader"}) );
    SetAdjectives( ({"fur"}) );
    SetRace("human");
 SetBaseLanguage("Avera");
    SetGender("male");
    SetClass("ranger");
    SetLevel(10);
  SetTown("Averath");
    SetLong("Dark hair pokes out from under his animal skin hat. His skin appears tan "
                        "and leathery. His skin bears the scars of many animal "   
                        "scratches and bites. He squats close to the ground "
                        "examining animal tracks."
                                 );
    SetInventory( ([
                        LUMBER_OBJ "knife" : "wield knife",
      ]) );
    SetCurrency("ducats", 13);
    SetAction(2, ({
                        "!emote turns his head at a slight noise.",
                        "!emote takes a silent step forward.",
                        "!emote cocks his head, listening to something.",
                        "!emote looks off in the distance.",
      }) );
    SetCombatAction(2, ({
                        "!emote scowls at you.",
                     "!say What are you doing here? I claimed this area!",
      }) );
}
