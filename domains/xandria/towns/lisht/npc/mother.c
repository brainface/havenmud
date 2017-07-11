#include <lib.h>
#include "../lisht.h"
inherit LIB_NPC;

static void create() {
  ::create();
  SetKeyName("Yeheved");
  SetShort("a stooped elven mother");
  SetRace("elf");
  SetBaseLanguage("Alatherian");
  SetGender("female");
  SetId( ({ "yeheved", "mother", "elf" }) );
  SetAdjectives( ({ "elf", "elven", "stopped" }) );
  SetLimit(1);
  SetLong(
    "This eldery elven woman seems to have been stooped by her toils. "
    "This burden's journey is almost over for her however."
    );
  SetClass("merchant");
  SetLevel(4);
  SetMorality(1000);
}