#include <lib.h>
inherit LIB_NPC;

static void create() {
  ::create();
  SetKeyName("blergh");
  SetRace("elemental", "ooze");
  SetGender("female");
  SetShort("a morose blergh");
  SetId( ({ "blergh" }) );
  SetAdjectives( ({ "morose" }) );
  SetLong(
    "This dull blue ooze slowly boils and pops around the area, oozing "
    "everything up. It would be utterly disgusting, but thankfully it smells "
    "slightly of windex. A lazily writhing psuedopod in the center possesses "
    "a carictured approximation of YOUR FACE on it, the mouth drawn down into "
    "a giant frown."
  );

  SetClass("animal");
  SetLevel(25);

  SetAction(5, ({
    "!emote unenthusiastically prods you with a pseudopod.",
    "!emote ... sneezes. I'm not gonna lie, it's pretty bad.",
    "!say Blergh",
    "!say Blargh!",
    "!say mergh",
    "!emote bubbles with disdain.",
    "!emote so much as a blob can, displays existential angst.",
    "!emote pops spitefully.",
  }) );
}

