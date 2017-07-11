//Illura@Haven
//Sept 2009
//moorfrog
#include <lib.h>
#include "../taiga.h"
inherit LIB_NPC;

static void create(){
    npc::create();
    SetKeyName("moorfrog");
    SetId( ({"moorfrog", "frog" }) ); 
  SetShort("a moorfrog");
    SetLong(
      "The frog is massive, and its slick skin is dark green "
      "like the pine trees in its habitat. Although large, it "
      "isn't much of a combatant.");
  SetRace("amphibian");
    SetClass("animal");
    SetLevel(5);
    SetGender("male");
    SetAction(5, ({
    "!emote jumps into a puddle.",
    "!emote splashes around.",
    "!emote whistles tunelessly through his froggy lips."
         }) );
  SetCombatAction(10, ({
    "The frog lashes out at you.",
    "The moorfrog slaps at you with his webbed feet.",
    }) );
}
