#include <lib.h>
inherit LIB_NPC;

static void create() {
  ::create();
  SetKeyName("gammit");
  SetRace("dog");
  SetGender("female");
  SetShort("Dog Gammit (Superdog)");
  SetId( ({ "dog","gammit","superdog" }) );
  SetAdjectives( ({ "dog" }) );
  SetLong(
    "This determined looking shiba is wearing a cloak with "
    "a pitchfork motif. A red bandit mask covers her eyes, "
    "and cheap plastic devil horns sit lopsided on her face."
  );

  SetClass("cavalier");
  SetLevel(10);

  SetAction(5, ({
    "!emote barks heroically!",
    "!emote sniffs around, looking for crime.",
    "!emote finds something long forgotten lying around to eat.",
    "!emote charges valiantly after a shadow!",
  }) );
}

