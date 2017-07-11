// Monastery
// Aerelus
// 07/05/2006

#include <lib.h>
#include "../monastery.h"

inherit LIB_NPC;

static void create() {
  ::create();
  SetKeyName("monk");
  SetShort("a warrior monk");
  SetId( ({ "monk" }) );
  SetAdjectives( ({"warrior"}) );
  SetLong(
    "This monk has specialized in combat. He is one of the best fighters "
    "in the monastery and is always prepared to go to battle when "
    "commanded. Like many of the more experienced Kylin monks, his skill "
    "with a sword is quite formidable. He looks entirely focused on his "
    "training."
  );  
  SetRace("human");
  SetClass("janissary");
  SetLevel(75);
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
    "!emote swings his sword around in a deadly fashion.",
    "!say I am undefeated. You should leave.",
  }) );
  SetCombatAction(10, ({
    "!shout Now you die, infidel!",
  }) );
 }
