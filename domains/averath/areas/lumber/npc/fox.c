#include <lib.h>
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("fox");
  SetShort("a rabid fox");
  SetId( ({"fox"}) );
  SetAdjectives( ({ "rabid" }) );
  SetRace("dog", "fox");
  SetClass("animal");
  SetLong(
    "This animal snarls as you approach. "
    "The froth dripping from its mouth indicates "
    "it is infected with rabies.  It seems agitated.  "
    );
  SetGender("male");
  SetLevel(2);
}
