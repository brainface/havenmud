#include <lib.h>
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("crane bird");
  SetShort("a large bog crane");
  SetId( ({ "bird", "crane" }) );
  SetAdjectives( ({ "large", "bog" }) );
  
  SetMorality(200);
  SetRace("bird");
  SetClass("animal");
  SetLevel(1);
  SetGender("female");
  SetLong(
  "This is a large white bird which stands on slender"
  " stick legs.  Its head is capped with red and it has"
  " small yellow eyes.  It has a sharp yellow beak"
  " which looks dangerous."
);
}

