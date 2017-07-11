// Monastery
// Aerelus
// 07/05/2006

#include <lib.h>
#include "../monastery.h"
inherit LIB_NPC;

static void create() {
  ::create();
  SetKeyName("peasant");
  SetShort("a simple peasant");
  SetId( ({ "peasant" }) );
  SetAdjectives( ({"simple"}) );
  SetLong(
    "This poorly-dressed man seems to have had a hard life. Finding food "
    "and water in the desert isn't easy, so he has come to the monastery "
    "for help. He is covered in dirt and smells like he hasn't bathed in "
    "months."
  );  
  SetRace("human");
  SetClass("fighter");
  SetSkill("melee combat",1,1);
  SetLevel(15);
  SetGender("male");
  SetReligion("Kylin");
  SetBaseLanguage("Padashi");
  SetMorality(30);
  SetFriends ( ({ "monk", "imam", "warrior_monk", "guard" }) );
  SetInventory( ([
    AREA_OBJ "shirt" : "wear shirt",
    AREA_OBJ "pants" : "wear pants",
  ]) );
  SetAction(6, ({
    "!emote looks like he hasn't eaten in days.",
    "!say Do you have anything to eat?",
  }) );
  SetCombatAction(10, ({
    "!say Don't hurt me!",
  }) );
 }
