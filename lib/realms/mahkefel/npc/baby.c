#include <lib.h>
inherit LIB_NPC;

static void create() {
  ::create();
  SetKeyName("baby");
  SetRace("drider");
  SetGender("female");
  SetShort("a lost little baby (drider)");
  SetId( ({ "drider", "baby" }) );
  SetAdjectives( ({ "lost","little","baby","drider" }) );
  SetLong(
    "This poor toddler looks lost! And arachnid... ish? Her "
    "round and wide eyes look around tear-filled seemingly "
    "looking for something important."
  );

  SetClass("rogue");
  SetLevel(1);

  SetAction(10, ({
    "!say Mommy?",
    "!say I'm lowst!",
    "!emote holds her hands out for a hug.",
    "!emote chews on something important.",
    "!emote slumps to the ground and breaks down crying.",
    "!toddles around ungangly on eight little legs.",
  }) );
}

