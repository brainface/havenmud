//Illura@Haven
//Sept 2009
//windrider
#include <lib.h>
#include <damage_types.h>
#include "../taiga.h"
inherit LIB_SENTIENT;

static void create() {
  sentient::create();
  SetKeyName("windrider");
  SetId( ({ "windrider", "nymph", "rider" }) );
  SetAdjectives( ({ "floating", "silvery", "silver" }) );
  SetShort("a floating silvery windrider");
  SetRace("nymph");
  SetGender("male");
  SetClass("evoker");
  SetLevel(40);
  SetLong(
    "The windrider seems formed of the most gossamer of silvery "
    "strands of magic and conscienceness. His floating presence "
    "seems to move almost jellyfish-like with the winds of the "
    "tundra. His eyes, however, crackle with the ancient power "
    "of a thousand thunderstorms. Perhaps he is not as passive as "
    "he seems."
  );
  SetBaseLanguage("archaic");
  SetAction(5, ({
    "!emote keens an unearthly song.",
    "!say in archaic all things eventually waste away. I was not always as you see me.",
    "!say in archaic fully corporeal form gives you no advantage, mortal.",
      "!cast sphere",
    }) );
  SetCombatAction(10, ({
    "!cast chain lightning",
    "!cast bolt",
    "!cast sphere",
    }) );
  SetInventory( ([
    TAIGA_OBJ "evokerknife" : "wield shard",
  ]) );
  SetNoCorpse(1);
  SetDie("The windrider's essence unravels into thin air.");
  }
