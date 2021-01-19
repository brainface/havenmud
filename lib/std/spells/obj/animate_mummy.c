// mahkefel january 2011
#include <lib.h>
#include <daemons.h>
#include <damage_types.h>
inherit LIB_NPC;
void eventSpecial();

static void create() {
  ::create();

  // spells lib autoreplaces $race with race
  SetShort("a tattered and shambling $r mummy");
  SetLong("This is a heavily bandaged corpse of $r that has been preserved "
	  "and animated by necromatic rituals.");
  SetId("mummy");
  SetKeyName("mummified $r");
  SetAdjectives( ({"tattered","shambling","mummified"}) );
  SetDie("The mummy collapses into a tattered pile of old bandages and bonedust.");

  SetResistance(HEAT,"weakness");
  SetResistance(ALL_PHYSICAL,"low");
  SetResistance(GAS|POISON|HUNGER|DISEASE,"immune");
  
  SetNoCorpse(1);
  SetUndead(1);
  SetUndeadType("mummy");
 
  SetCombatAction(5,
    (: eventSpecial :)
  );
}

/*
 * Mummy curse special
 */
void eventSpecial() {
  object who = this_object();
  object target = GetCurrentEnemy();
  send_messages("curse",
    "$agent_name%^MAGENTA%^ $agent_verb%^RESET%^ $target_name "
    "with a touch of $agent_possessive bandaged hands!", who, target, environment() );
  target->eventReceiveDamage(who, MAGIC, random(100), 0,
    target->GetRandomLimb("head") );
  if (target->GetCursed() < 50) {
    target->AddCursed(random(20));
  }
  return;
}

