#include <lib.h>
#include "../lisht.h"
inherit LIB_NPC;

static void create() {
  ::create();
  SetKeyName("Miriam");
  SetRace("elf");
  SetBaseLanguage("Alatherian");
  SetReligion("Anteky");
  SetGender("female");
  SetClass("priest");
  SetSkill("healing", 1, 1);
  SetSkill("enchantment", 1, 1);
  SetReligion("Anteky");
  SetShort("a small elven girl");
  SetId( ({ "miriam", "elf", "girl" }) );
  SetLevel(2);
  SetAdjectives( ({ "small", "elf", "elven" }) );
  SetLong(
    "Miriam is a small girl with a deeply rooted faith. Her elven heritage "
    "is to her a source of great pride and also great suffering."
    );
  SetSpellBook( ([
    "sting" : 15,
    "touch" : 20,
    ]) );
  SetAction(10, ({
    "!say Someday, he'll deliver us.",
    "!emote mutters a little prayer.",
    "!sigh wistfully",
  }) );
  SetCombatAction(10, ({
    "!cast touch",
    "!cast sting",
  }) );
  SetMorality(1000);
  SetLimit(1);
}