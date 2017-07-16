#include <lib.h>
inherit LIB_NPC;

static void create() {
  ::create();
  SetKeyName("mirror Alessandra");
  SetRace("human");
  SetGender("female");
  SetShort("mirror Alesssandra is sitting at the adults' table");
  SetId( ({ "alessandra","Alessandra", "mirrorperson","person" }) );
  SetAdjectives( ({ "mirror" }) );
  SetLong(
    "This is a perfectly mirrored reflection of Alessandra! Look out, she's "
    "probably evil or something? Also, she has a fake taped on goatee, because "
    "image is important.",
      );

  SetClass("rogue");
  SetClass("enchanter");

  SetLevel(100);

  SetAction(5, ({
    "!emote moves with absolute grace and perfect balance.",
    "!emote respects her boss and likes her job, which pays well!",
    "!emote recognizes spiders as an essential part of the ecosystem.",
    "!emote doesn't manage to flood her backyard in a desert, what the hell?",
    "!emote ain't afraid of no ghost.",
    "!emote lets be honest here, like totes honest? Probably has a lot less friends.",
    "!emote lifts her totally not bent at all nose in the air, because she's better than you.",
    "!emote is very intimidating, and throws a mean left hook.",
    }) );
}

