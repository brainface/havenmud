#include <lib.h>

inherit LIB_NPC;

static void create() {
  ::create();
  SetKeyName("goat");
  SetShort("Mr Hoofy, an angry mountain goat");
  SetLong(
    "Mr Hoofy is an often abused, but loveable, mountain goat. He looks "
    "like he is a little angry after months of being pushed around and is "
    "glad to have been taken in by his new master."
  );
  SetId( ({ "goat", "Mr Hoofy", "Hoofy" }) );
  SetAdjectives( ({"Mr", "Hoofy", "angry", "mountain"}) );
  SetRace("mammal");
  SetLevel(1);
  SetGender("male");
  SetBaseLanguage("Goatish");
  SetMorality(100);
  SetAction(6, ({
    "!snuggle",
    "!say Bleat bleat, and such.",
  }) );
 }
