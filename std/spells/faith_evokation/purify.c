/*  Purify-high level cleric spell 
    Coded by Malak@Haven
    Christopher H. Hays
    6/23/99
*/
#include <lib.h>
#include <damage_types.h>
#include <magic.h>
inherit LIB_SPELL;

static void create() {
  spell::create();
  SetSpell("purify");
  SetRules("", "LIV");
  SetSpellType(SPELL_COMBAT);
  SetSkills( ([
     "faith" : 150,
     "evokation" : 150,
     ]) );
  SetDifficulty(60);
  SetAutoDamage(0);
  SetDamageType(HEAT);
  SetEnhanceSkills( ({ "fire magic" }) );
  SetMessages( ({
    ({ "howl", "$agent_name $agent_verb angrily, channeling "
               "sacred energies, attempting to %^RED%^smite%^RESET%^ "
               "$target_name with %^YELLOW%^Divine Rage%^RESET%^!" }),
    ({ "chant", "$agent_name $agent_verb words of faith, "
                "causing a blast of incredible power to"
                " %^BLUE%^ravage%^RESET%^ $target_name." }),
    ({ "chant", "$agent_name $agent_verb "
                "loudly amidst crackling energy, summoning a mighty"
                " %^BOLD%^%^RED%^blast%^RESET%^ of %^YELLOW%^purifying%^RESET%^ "
                "flames against $target_name!" })
      }) );
  SetHelp(
     "This powerful holy spell is taught only to the most faithful of clerics, "
     "as it is capable of supreme damage.");
}


/* Approved by Rhakz on Sat Jun 26 04:28:49 1999. */
