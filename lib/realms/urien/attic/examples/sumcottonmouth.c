// A summoned snake that poisons you!

#include <lib.h>
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("cottonmouth");
  SetId( ({"cottonmouth", "large cottonmouth"}) );
  SetAdjectives( ({"large", "snake"}) );
  SetShort("an angry cottonmouth");
  SetLong("blazy squazay.");
  SetGender("male");
  SetRace("snake");
  SetClass("animal");
  SetLevel(15);
  }
  
void eventMeleeAttack(object target, string limb) {
  npc::eventMeleeAttack(target, limb);
  if(!(random(10))) {
      target->AddPoison(20);
  message("system", 
          "You feel the %^RED%^poison%^RESET%^ moving through your body.",
           target);
  message("system", 
          capitalize(target->GetKeyName()) + " suddenly looks ill.",
          environment(target), target);
       }
  return;
  }
