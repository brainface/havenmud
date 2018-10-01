#include <lib.h>
inherit LIB_NPC;

static void create() {
  ::create();
  SetKeyName("roses");
  SetRace("plant");
  SetGender("male");
  SetShort("a bouquet of only slightly bloodthirsty roses");
  SetId( ({ "roses","bouquet" }) );
  SetAdjectives( ({ "bouquet","of","only","slightly","bloodthirsty","audreyii" }) );
  SetLong(
    "A beautiful and elegant bouquet of silky red roses sits on the ground, "
    "thorns atwitch and petals flapping together like some sort of animatronic "
    "puppet from a Rick Moranis movie as its twirly roots try to scoot it a "
    "leeeel bit closer to you bit by bit."
  );

  SetClass("bard");
  SetStat("strength", 100, 1);
  SetLevel(1);

  SetAction(5, ({
    "!say FEED ME ALLIBATSIES",
    "!emote wiggles about hungrily.",
    "The pleasant aroma of these roses fills your nostrils as it "
      "tries to bite your nose off.",
    "!emote eats some paperwork.",
    "!emote has found cords! Delicious cords, omnomnom.",
    "!emote tries to nibble your toes but is confused by the concept of shoes.",
    }) );
}

