#include <lib.h>
inherit LIB_BASENPC;

static void create() {
  ::create();
  SetKeyName("whiny guy");
  SetRace("dark-elf");
  SetId( ({ "guy", "reno" }) );
  SetAdjectives( ({ "whiny" }) );
  SetShort("a whiny guy");
  SetLong("This is a whiny guy.");
  SetMorality(-100);
  SetClass("evoker");
  SetLevel(200);
}

varargs int eventInflictDamage(object agent, int type, int amt, int i, mixed limbs) {
  if (!limbs) limbs = ({});
  if (!arrayp(limbs)) limbs = ({ limbs });
  if (agent)
    eventForce("speak Dammit! " + agent->GetCapName() + " hit me for " + amt + " in my " + implode(limbs, ",") + "!");
  return ::eventInflictDamage(agent, type, amt, i, limbs);
}

int AddParalyzed(int x) { 
  int y = ::AddParalyzed(x);
  eventForce("speak Damn, paralyzed for " + x + " more. Total of " + GetParalyzed());
  return y;
}
