//Alex@Haven
//2006
#include <lib.h>
#include <std.h>
#include "../area.h"
inherit LIB_NPC;

static void create(){
  npc::create();
  SetKeyName("salamander");
  SetId( ({ "salamander" }) );
  SetShort( "a yellow salamander" );
  SetAdjectives( "yellow" );
  SetLong(
     "This little salamander has made his home here. Although small, "
     "he is brightly colored from a steady diet of kumquats. His baleful "
     "red eyes seem to guarantee that his bite is poisonous.");
  SetRace("amphibian");
  SetClass("animal");
  SetLevel(2);
  SetGender("male");
}
void eventMeleeAttack(object target, string limb) {
  npc::eventMeleeAttack(target, limb);
  if(!(random(10))) {
    target->AddPoison(3);
  message("system",
        "You feel the %^RED%^poison%^RESET%^ moving through your body.",
        target);
    message("system",
        capitalize(target->GetKeyName()) + " suddenly looks ill.",
        environment(target), target);
    }
  return;
}

