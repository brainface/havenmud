#include <lib.h>
#include "../lisht.h"
inherit LIB_NPC;

static void create() {
  ::create();
  SetKeyName("infant");
  SetMorality(5000);
  SetRace("elf");
  SetClass("priest");
  SetSkill("evokation", 1, 1);
  SetSkill("enchantment", 1, 1);
  SetBaseLanguage("Alatherian");
  SetGender("male");
  SetShort("an elven infant");
  SetStat("wisdom", 125, 1);
  SetLevel(1);
  SetStat("durability", -4, 5);
  SetStat("strength", -5, 5);
  SetId( ({ "infant", "moses", "elf" }) );
  SetAdjectives( ({ "elf", "elven", "infant" }) );
  SetLong(
    "This small elven infant is the blessing bestowed upon this hovel. "
    "His small coos of happiness are testiment to his joy."
    );
  SetAction(3, ({
    "An elven infant coos happily.",
    "!smile happily",
    "!beam",
    "!giggle",
  }) );
  SetParalyzed(1100000000);
  SetLimit(1);
}
