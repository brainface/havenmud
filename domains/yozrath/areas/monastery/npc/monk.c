// Monastery
// Aerelus
// 06/05/2006

#include <lib.h>
#include "../monastery.h"
inherit LIB_NPC;

static void create() {
  ::create();
  SetKeyName("monk");
  SetShort("a kylin monk");
  SetId( ({ "monk" }) );
  SetAdjectives( ({ "kylin", "powerfully", "built" }) );
  SetLong(
    "This monk has lived in the monastery for a long time. He is tall "
    "and powerfully built, clearly capable of defending himself and his "
    "home. His smile reflects the years of contemplation he has "
    "undertaken, whilst multiple scars show he is no stranger to combat."
  );  
  SetRace("human");
  SetClass("janissary");
  SetLevel(50);
  SetGender("male");
  SetReligion("Kylin");
  SetBaseLanguage("Padashi");
  SetMorality(100);
  SetFriends ( ({ "monk", "imam", "warrior_monk", "guard" }) );
  SetInventory( ([
    AREA_OBJ "robe" : "wear robe",
    AREA_OBJ "sword" : "wield longsword",
  ]) );
  SetAction(6, ({
    "!emote looks deep in thought.",
    "!say Death to the infidels!",
    "!say All glory to Duuktsaryth!",
  }) );
  SetCombatAction(10, ({
    "!shout Now you die, infidel!",
  }) );
 }

/** Approved by Laoise at Sun May 21 17:03:51 2006. **/