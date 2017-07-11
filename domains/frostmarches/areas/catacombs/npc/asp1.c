#include <lib.h>
#include <damage_types.h>
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("asp");
  SetId( ({"asp", "snake", "golem_piece", "cata_npc"}) );
  SetShort("a dark red asp");
  SetAdjectives( ({ "dark", "red" }) );
  SetRace("snake");
  SetClass("animal");
  SetLevel(10);
  SetGender("male");
  SetLong(
    "This asp is a dark red color and has huge fangs that"
    " protrude from his mouth. They are dripping with"
    " venom.");
  SetAction(6, ({ 
     "!emote slithers.",
     "!emote hisses softly.",
  }) );
  SetResistance(GAS, "immune");
  SetResistance(HUNGER, "immune");
  SetResistance(POISON, "immune");
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
