/* a tarantula for the jungle
    kyla 11-97
*/
#include <lib.h>
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("tarantula");
  SetId( ({"tarantula", "spider"}) );
  SetAdjectives( ({"hairy", "large"}) );
  SetShort("a large tarantula");
  SetLong("This large hairy spider looks very mean. He is about a foot "
          "across, with very long fangs.");
  SetGender("male");
  SetRace("arachnid");
  SetClass("animal");
  SetLevel(2);
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
