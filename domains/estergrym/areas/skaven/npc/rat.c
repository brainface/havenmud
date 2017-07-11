#include <lib.h>
#include "../skaven.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("rat");
  SetShort("a giant rat");
  SetLong("This massive rat looks incredibly hungry.  Nearly a meter "
          "in length, the rat is covered with dingy brown fur and smells "
          "of death.");
  SetId( ({ "rat","giant rat" }) );
  SetEncounter(100);
  SetMorality(-50);
  SetDie("The rat falls over on its side and convulses wretchedly.");
  SetCombatAction(5,
         ({"!emote circles around you looking for an opening",
           "!emote lunges boldly in your direction.",
           "!emote squeaks hungrily."           
            }) );           
  SetRace("rodent");
  SetClass("animal");
  SetLevel(random(5) + 3);
  SetGender("male");
  }
