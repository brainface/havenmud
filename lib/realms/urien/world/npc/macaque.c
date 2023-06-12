// Indochinese rhesus Macaque
// They usually hunt in packs of 80-100
// To add to the world roadmap package
// Urien@Haven 11JUN2023

#include <lib.h>
#include <std.h>
#include <damage_types.h>
#include "../world.h"

inherit LIB_SENTIENT;

void eventSummon();

static void create(){
  ::create();
  SetId(({"macaque"}));
  SetAdjectives( ({ "rhesus" }) );  
  SetShort("a rhesus macaque");
  SetLong("The small humanoid primate has white silver above the "
          "waistline and dark brown fur of his lower half. He "
          "looks satisfactorily groomed, free of any tree debris "
          "or food matter. Bright brown eyes with narrow iris "
          "rest sunken in the fur free humanoid shaped face. Its "
          "body resembles a tiny human with much longer digits "
          "and flexibility than its much larger comparison.");
  SetRace("primate","macaque");
  SetGender("male");
  SetClass("animal");
  SetKeyName("macaque");
  SetLevel(random(7) + 2);
 SetAction(2, ({
    "!looks around picking something off the ground.",
    "!searches for something.",
  }) );
  SetCombatAction(2, (: eventSummon :) );
}

void eventSummon() {
  object buddy;
  eventForce("emote loudly screeches with primal emotion!");
  buddy = new(WORLD_NPC "macaque");
  buddy->eventMove(environment());
  buddy->SetFriends( ({ "macaque" }) );
  message("system", "A new aggressive macaque arrives assisting "
                    "the call of distress!", environment());
}
