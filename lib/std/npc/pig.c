#include <lib.h>
inherit LIB_NPC;

static void create() {
  ::create();
  SetKeyName("pig");
  SetRace("pig");
  SetGender("female");
  SetShort("a nice pig");
  SetId( ({ "pig" }) );
  SetAdjectives( ({ "nice" }) );
  SetLong("This vaguely pinkish-grey pig looks like "
          "it is quite content with its life.");
  SetClass("animal");
  SetLevel(2);
  SetAction(5, "!emote oinks.");
}
