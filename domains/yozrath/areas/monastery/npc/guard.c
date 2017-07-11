// Monastery
// Aerelus
// 06/05/2006

#include <lib.h>
#include "../monastery.h"

inherit LIB_NPC;

static void create() {
  ::create();
  SetKeyName("guard");
  SetShort("a monastery guard");
  SetId( ({ "guard" }) );
  SetAdjectives( ({"monastery"}) );
  SetLong(
    "This well-built man's only purpose is to protect the monastery from "
    "invaders. He has no expression on his face while he concentrates on "
    "his duties. He looks more than capable of defending the monastery "
    "with deadly force."
  );  
  SetRace("human");
  SetClass("janissary");
  SetLevel(60);
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
    "!emote glances around, looking for potential trouble.",
    "!say Come in peace and no harm will come to you.",
  }) );
  SetCombatAction(10, ({
    "!say You are not welcome here! Die!",
  }) );
 }
