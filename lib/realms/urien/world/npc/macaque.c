// Indochinese rhesus Macaque
// They usually hunt in packs of 80-100
// To add to the world roadmap package
// Urien 6/3/23

#include <lib.h>
#include <std.h>
#include <damage_types.h>
#include "../world.h"

inherit LIB_SENTIENT;

void eventSummon();

static void create(){
  ::create();
  SetId(({"macaque"}));
  SetAdjectives( ({ "rhesus" , "primate" }) );  
  SetShort("a rhesus macaque");
  SetLong(".");
  SetRace("primate");
  SetGender("male");
  SetClass("animal");
  SetKeyName("macaque");
  SetLevel(random(7) + 2);
  SetCombatAction(2, (: eventSummon :) );
}

void eventSummon() {
  object buddy;
  eventForce("emote screeches with primal emotion!");
  buddy = new(WORLD_NPC "macaque");
  buddy->eventMove(environment());
  buddy->SetFriends( ({ "macaque" }) );
  message("system", "A new macaque arrives.", environment());
}
