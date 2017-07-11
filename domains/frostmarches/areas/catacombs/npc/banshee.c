#include <lib.h>
#include <damage_types.h>
#include "../cata.h"

inherit LIB_NPC;

void eventWail();
string DoDie();

static void create() {
  ::create();
  SetKeyName("banshee");
  SetId( ({ "banshee", "cata_npc" }) );
  SetShort("a banshee");
  SetLong("This wispy apparition was once a lovely young lady"
          " who appears to be pregnant. Her lamentable cry"
          " is known to be a harbinger of death and as such"
          " can cause pain to those who come in close contact"
          " with it.");
  SetGender("female");
  SetRace("human");
  SetUndead(1);
  SetUndeadType("ghost");
  SetNoCorpse(1);
  SetMeleeDamageType(COLD|BLUNT);  
  SetMeleeAttackString("wispy hand");
  SetClass("horror");
  SetMorality(-100);
  SetLevel(85);
  SetResistance(SLASH, "immune");
  SetResistance(PIERCE, "immune");
  SetResistance(BLUNT, "immune");
  SetDie( (: DoDie :) );
  SetAction(5, ({
            "!emote cries out.",
            "!wail",
    }) );
  SetCombatAction(20, (: eventWail :) );  
  SetResistance(GAS, "immune");
  SetResistance(HUNGER, "immune");
  SetResistance(POISON, "immune");
}


void eventWail(object target) {
  int amt;
  target = GetCurrentEnemy();
  amt = target->GetMaxHealthPoints() / 10;
  target->eventReceiveDamage(this_object(), SOUND, amt, 0);
  send_messages("wail", "$agent_name%^RED%^ $agent_verb %^RESET%^a cry"
                      " of severe anguish at $target_name.", this_object(),
                      target, environment());
 }

string DoDie() {
  environment()->AddPosionGas(5);
  message("die", "The banshee fades into a cloud of gas.", environment() );
  return "";
 }
