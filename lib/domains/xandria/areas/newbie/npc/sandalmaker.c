//Selket@Haven
//2006
#include <lib.h>
#include "../newbie.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("sandalmaker");
  SetShort("a senile slovenly sandalmaker");
  SetId( ({ "sandalmaker", "lisht_newbie"}) );
  SetAdjectives( ({ "senile", "slovenly" }) );
  SetLong(
    "This old fellow makes his living by weaving rough sandals "
    "for others. He is harsh and unfriendly and quite set in "
    "his ways. He doesn't look like a threat.");
  SetClass("fighter");
  SetMorality(-200);
  SetLevel(5);
  SetGender("male");
  SetRace("gnoll");
  SetBaseLanguage("Rehshai");
  SetCurrency("deben",random(100));
  SetInventory( ([
       NEWBIE_OBJ + "cane" : "wield cane",
       NEWBIE_OBJ + "sandals" : "wear sandals",
         ]) );
  SetWander(1);
  SetLimit(1);
  SetWanderSpeed(2);
  SetAction(6, ({
    "!emote spits on the ground.",
    "!say Stop gawking at me, you two-deben tart.",
    "!say I'll make you some sandals if you leave me alone.",
  }) );
}
