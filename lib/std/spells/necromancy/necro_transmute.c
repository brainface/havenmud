#include <lib.h>
#include <magic.h>
#include <conditions.h>

inherit LIB_SPELL;

static void create() {
  spell::create();
  SetSpell("transmutation");
  SetSpellType(SPELL_OTHER);
  SetRules("");
  SetHealthCost(20, 10);
  SetSkills( ([
     "necromancy" : 10,
    ]) );
  SetDifficulty(25);
  SetHelp( 
     "The necromancer attempts to transmutate his own life force into magical energy. This spell "
     "is known to be extremely dangerous to the caster. Only those who would have no worry "
     "of tainting their skin or soul can use this demonic spell."
    );
}

varargs int eventCast(object who, int level, mixed limb, object array tars) {
  int amt, base, rat;

  switch (level) {
    case 0..20:
       rat = 5;
       break;
    case 21..40:
       rat = 4;
       break;
    case 41..60:
       rat = 3;
       break;
    case 61..80:
       rat = 2;
   default:
       rat = 1;
       break;
    }
  amt = 30 / rat;
  who->AddMagicPoints(amt);
  send_messages("transmutate", 
    "$agent_name $agent_verb some life force into magical energy. ",
    who, 0, environment(who) );

  // mahk 2017: prevents casting healing spells for 10s
  // in a thematic attempt to stop thorian/ennaie from having
  // dumb infinite exp loops.
  who->AddCondition("Tainted Magic",CONDITION_PREVENT_MAGIC_HEALING,10);

  who->eventDisplayStatus();
  return 1;
}

