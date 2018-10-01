// A summoned snake that poisons you!

#include <lib.h>
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("viper");
  SetId( ({"viper", "large viper"}) );
  SetAdjectives( ({"large", "snake"}) );
  SetShort("an angry viper");
  SetLong("This large viper looks very angry. His long fangs protrude from "
          "from his mouth dripping with green liquid. His body is covered "
          "in a dark green scale skin and his eyes are tiny beads. His hood "
          "has horizontal lines that are shadowed white and black. In his "
          "movement he slithers side to side.");
  SetGender("male");
  SetRace("snake");
  SetClass("animal");
  SetLevel(10);
  }
  
void eventMeleeAttack(object target, string limb) {
  npc::eventMeleeAttack(target, limb);
  if(!(random(10))) {
      target->AddPoison(5);
  message("system", 
          "You feel the %^RED%^poison%^RESET%^ moving through your body.",
           target);
  message("system", 
          capitalize(target->GetKeyName()) + " suddenly looks ill.",
          environment(target), target);
       }
  return;
  }
