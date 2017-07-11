//Illura@Haven
//lemming
#include <lib.h>
#include "../taiga.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("lemming");
  SetId( ({ "lemming" }) );
  SetAdjectives( ({ "dismal", "polar" }) );
  SetShort("a dismal polar lemming");
  SetLong(
    "This lemming, although grown abnormally large, has eyes "
    "round as Gurovian dinner plates and almost as big, filled "
    "and brimming with ultimate sadness. She has seen many "
    "family members fling themselves over the cliffs and has "
    "yet to decide if she, too, has the guts to end all things. "
    "Because of her melancholia, she probably would make "
    "an easy target for predators."
  );
  SetGender("female");
  SetClass("animal");
  SetLevel(15);
  SetRace("deer");
    SetAction(5, ({
    "!cry",
     "!emote sniffles softly.",

     "!emote scrubs at one eye with her little paw.",
                })  );
  SetCombatAction(10, ({
    "The lemming half-heartedly approaches you.",
    "The lemming attacks without even looking up.",
    }) );
  SetNoCorpse(1);
  SetDie("The lemming jumps over the edge with a squeak.");
}
