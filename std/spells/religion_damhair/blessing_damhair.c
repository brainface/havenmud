#include <lib.h>
#include <magic.h>
#include <damage_types.h>
#include <dirs.h>
inherit LIB_SPELL;

static void create() {
  spell::create();
  SetSpell("blessing of damhair");
  SetRules("");
  SetSpellType(SPELL_OTHER);
  SetSkills( ([
     "faith" : 55,
  ]) );
  SetMagicCost(25, 25);
  SetDifficulty(20);
  SetMorality(0);
  SetConjure(DIR_SPELLS "/obj/holy_pole");
  SetMessages( ({
     ({
    ({ "pray", }),
      "%^BLUE%^With palms up and hands outstretched, $agent_name "
      "$agent_verb for the blessings of the Sea God. Droplets of "
      "water begin to appear on $agent_possessive hands and fingers, "
      "gathering into puddles in $agent_possessive palms. The "
      "waters leap up from $agent_possessive hands and take the "
      "form of a fishing pole.%^RESET%^"
     }),
  }) );
  SetHelp(
    "The most devout of Damhair Cleric may receive the blessing of the Sea God "
    "in the form of this most holy fishing pole."
// it dests on drop, cant be stole, 99% success rate and radiates light
  );
}
