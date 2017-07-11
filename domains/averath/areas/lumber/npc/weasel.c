#include <lib.h>
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("weasel");
  SetShort("a weasel");
  SetId( ({ "weasel"}) );
  SetAdjectives( ({"curious"}) );
  SetRace("rodent");
  SetClass("animal");
  SetLong(
    "This small animal pops its head up to examine you. "
    "It appears curious about you. "
       );
  SetGender("male");
  SetLevel(3);
}
