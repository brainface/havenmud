// Cleric Trainer for Karak and Argoth
// Taigis
// April 2005

#include <lib.h>
#include "../argoth.h"
inherit LIB_TRAINER;

static void create() {
  ::create();
  SetKeyName("naguk");
  SetId( ({ "naguk", "trainer" }) );
  SetAdjectives( ({ "cleric", "orc" }) );
  SetShort("naguk, the Trainer of the Saahagoth Faithful");
  SetLong(
    "Naguk radiates an aura of dark power, which seems to crawl "
    "across her grey-green colored skin. From the very front of "
    "her lower jaw project curving fangs. Lanky black hair lies across "
    "her thick, sloping shoulders. Her eyes swirl with an inky "
    "black which obscures their normal red color. The front of her snout "
    "and tips of her ears have a faint pink tinge."
  );
  SetRace("orc");
  SetGender("female");
  SetClass("priest");
  SetSkill("evokation", 1, 1);
  SetSkill("enchantment", 1, 1);
  SetSkill("necromancy", 1, 1);
  SetTown("Karak");
  SetReligion("Saahagoth");
  SetLevel(45);
  SetSpellBook( ([
    "barrier of faith" : 90,
    "ancient might" : 95,
  ]) );
  SetAction(5, ({
    "!speak You could <ask naguk to train>",
    "!cast barrier of faith",
    "!cast barrier of faith",
  }) );
  SetCombatAction(50, ({
    "!cast barrier of faith",
    "!cast harm body",
    "!cast pain touch",
  }) );
}
