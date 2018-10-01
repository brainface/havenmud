#include <lib.h>
#include <damage_types.h>

inherit LIB_NPC;

static void create() {
  ::create();
  SetKeyName("combat dummy");
  SetShort("a combat dummy");
  SetId( ({ "dummy", "melchezidek" }) );
  SetAdjectives( ({ "flying", "severed" }) );
  SetRace("human");
  SetStat("durability", 1000000, 1);
  SetNoCorpse(1);
  SetDie("Now, aren't you impressive?");
  SetClass("fighter");
  SetLevel(1);
  SetResistance(ALL_DAMAGE, "immune");
  SetResistance(MAGIC, "none");
  SetMorality(-100);
  SetGender("neuter");
  SetLong("This is a straw dummy that fights back, rather poorly.");
}
