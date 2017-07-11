// mahkefel january 2011
#include <lib.h>
#include <daemons.h>
#include <damage_types.h>
inherit LIB_NPC;
void eventSpecial();

static void create() {
  ::create();
  SetKeyName("mummy");
  SetShort("a mummy");
  SetDie("The mummy collapses into a tattered pile of old bandages and bonedust.");
  SetNoCorpse(1);
  SetUndead(1);
  SetUndeadType("mummy");

  // note that racial resistances will override this e.g. mummy demons/angels.
  SetResistance(ALL_PHYSICAL, "low");

  SetCombatAction(5,
    (: eventSpecial :)
  );
}

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

