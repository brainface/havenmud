#include <lib.h>
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("dog");
  SetShort("a wiry dog");
  SetLong(
    "This dog is small and wiry, but ropes of muscle "
    "beneath his tight fur attest to his fortitude. "
    "Although his fur is matted and unkempt, "
    "something about his demeanor suggests "
     "an ability to stand his ground.",
  );
  SetId( ({ "dog" }) );
  SetAdjectives( ({ "wiry" }) );
  SetRace("dog");
  SetClass("animal");
  SetLevel(3);
  SetGender("male");
  }
