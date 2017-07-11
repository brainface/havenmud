#include <lib.h>
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("porcupine");
  SetShort("a prickly porcupine");
  SetId( ({ "porcupine" }) );
  SetAdjectives( ({ "prickly" }) );
  SetRace("rodent");
  SetClass("animal");
  SetLong(
    "This porcupine seems skiddish and moves "
    "away timidly as you approach. "
    "His sharp quills quiver with anxiety.  "
    );
  SetGender("male");
  SetLevel(2);
}
