#include <lib.h>
inherit LIB_NPC;

static void create() {
  ::create();
  SetKeyName("moth");
  SetRace("insect");
  SetGender("male");
  SetShort("the rare moustache moth");
  SetId( ({ "moth","moustache", }) );
  SetAdjectives( ({ "rare","moustache" }) );
  SetLong(
    "One of the rarer examples of mimicry, this moth "
    "is indistinguishable from a bushy moustache until it "
    "takes to the air, where it appears to be a bushy, "
    "flying moustache, which rather breaks the illusion. "
    "They hide upon the face of the clean shaven and baby faced, who are too "
    "embarrased to admit that their awesome and majestic moustache "
    "is in fact just a bug trying to avoid predators."
  );

  SetClass("rogue");
  SetLevel(1);

  SetAction(5, ({
    "!emote lands softly on your upper lip, instantly steveifying you.",
    "!emote flaps fuzzily around the room.",
    "!emote does not eat brains, but will gladly consume boogers, "
      "as you notice him doing right now to your horror.",
    "!emote flees desperately from an electric razor!",
    "!emote twirls maniacally, tickling your nose.",
  }) );
}

