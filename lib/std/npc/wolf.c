#include <lib.h>
inherit LIB_NPC;
inherit LIB_MOUNT;

static void create() {
  npc::create();
  SetKeyName("grey wolf");
  SetShort("a cunning grey wolf");
  SetId( ({ "wolf", "grey wolf" }) );
  SetAdjectives( ({ "cunning" }) );
  SetRace("wolf");
  SetClass("animal");
  SetLong(
    "This regal animal has a pelt of grey covering a thin yet "
    "strong form. His yellow eyes glow with an intense "
    "and violent light. Minor scars on his body attest "
    "to his history and experience."
  );
  SetGender("male");
  SetLevel(6);
 }
