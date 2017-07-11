//Selket@Haven
//2006
#include <lib.h>
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("asp");
  SetId( ({"asp", "snake"}) );
  SetShort("a green asp");
  SetAdjectives( ({ "green" }) );
  SetRace("snake");
  SetClass("animal");
  SetLevel(10);
  SetGender("male");
  SetLong(
    "This is a small green asp. His sharp fangs are filled "
    "with venom.");
  SetAction(6, ({ 
     "!emote slithers.",
     "!emote hisses softly.",
  }) );
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
