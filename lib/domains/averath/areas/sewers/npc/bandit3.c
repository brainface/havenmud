// Averath Sewers
// Aerelus

#include <lib.h>
#include <damage_types.h>
#include "../sewers.h"
inherit LIB_NPC;

static void create() {
  ::create();
  SetKeyName("shady bandit");
  SetShort("a shady bandit");
  SetId( ({ "bandit" }) );
  SetAdjectives( ({ "shady" }) );
  SetLong(
    "This tough looking man blends into the shadows with ease. His face is "
    "hidden, though a scar on his upper lip remains noticeable. He glances "
    "around, checking for movement in the shadows, as if paranoid."
  	);  
  SetRace("human");
  SetClass("fighter");
  SetGender("male");
  SetBaseLanguage("Avera");
  SetLevel(4);  
  AddCurrency("ducats", random(50)+1);
  SetCombatAction(1, ({
    "!say You had better be carrying some ducats.",
    "!emote moves almost gracefully, seeking an opportunity to strike.",
  }) );
  SetAction(3, ({
    "!emote methodically checks the shadows for movement.",
    "!glance",
  }) );
  SetInventory( ([ 
     "std/weapon/pole/baton.c" : "wield batons",
     "std/weapon/pole/baton.c" : "wield batons",       
  ]) );
  SetEncounter(0);
  SetMorality(-200);
}