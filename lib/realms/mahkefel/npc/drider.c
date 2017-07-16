#include <lib.h>
inherit LIB_NPC;

static void create() {
  ::create();
  SetKeyName("drider");
  SetRace("drider");
  SetGender("male");
  SetShort("a dreaded mayonnaise drider");
  SetId( ({ "drider" }) );
  SetAdjectives( ({ "dreaded","mayonnaise" }) );
  SetLong(
    "Oh. Oh dear. This appears to be a dark elf who greatly angered his god, "
    "and was then turned into a drider. And then turned into mayonnaise."
      );

  SetClass("rogue");
  SetLevel(100);

  SetAction(15, ({
    "!say What did I /do/?",
    "!say Please end me!",
    "!emote whimpers",
    "!emote moan",
    "!say I've been turned into a condiment!",
  }) );
}

