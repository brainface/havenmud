// A mortal level npc to slay
// The poison is in the attack not the barbs
// To add to the world roadmap package
// Urien@Haven 06JUN23

#include <lib.h>
inherit LIB_NPC;
static void create(){
  ::create();
  SetId(({"scorpion"}));    
  SetAdjectives( ({ "trispike" }) );  
  SetShort("a trispike scorpion");
  SetLong("The scorpion has a hard bight orange carapace covered "
          "in erect brown hairs. Three spikes usually are associated "
          "with this breed that jut from the head, body and tail "
          "region. The claws are usually various in size and have "
          "different roles for the activities of survival. It "
          "has a bright purple lipid that secrete from its carapace "
          "connections slightly. It lacks the conventional needle "
          "a sterotypical scorpion usually posess on the tail segment.");
  SetRace("lobster","scorpion");
  AddLimb("tail spike","abdomen",3, ({ }) );
  AddLimb("body spike","abdomen",3, ({ }) );
  AddLimb("head spike","head",3, ({ }) );
  SetGender("male");
  SetClass("animal");
  SetKeyName("scorpion");
  SetLevel(random(4) + 5);
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
