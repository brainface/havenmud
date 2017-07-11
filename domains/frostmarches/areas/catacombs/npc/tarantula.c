#include <lib.h>
#include <damage_types.h>
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("tarantula");
  SetId( ({ "tarantula", "spider", "golem_piece", "cata_npc" }) );
  SetAdjectives( ({ "hairy", "large", "black" }) );
  SetShort("a large black tarantula");
  SetLong("This is a monsterously large black tarantula. It's legs"
          " are nearly six inches in length and it sits high off"
          " the ground. Large yellowish fangs adorn it's mouth.");
  SetGender("male");
  SetRace("arachnid");
  SetClass("animal");
  SetLevel(12);
  SetResistance(GAS, "immune");
  SetResistance(HUNGER, "immune");
  SetResistance(POISON, "immune");
  }
  
void eventMeleeAttack(object target, string limb) {
  npc::eventMeleeAttack(target, limb);
  if(!(random(10))) {
      target->AddPoison(1);
  message("system", 
          "You feel the %^RED%^poison%^RESET%^ moving through your body.",
           target);
  message("system", 
          capitalize(target->GetKeyName()) + " suddenly looks ill.",
          environment(target), target);
       }
  return;
  }
