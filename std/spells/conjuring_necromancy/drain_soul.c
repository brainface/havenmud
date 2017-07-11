/* edited by renny boy rto make the f ing message display */
#include <lib.h>
#include <magic.h>
#include <damage_types.h>

inherit LIB_SPELL;

static void create() {
  spell::create();
  SetSpell("drain soul");
  SetRules("", "LIV");
  SetSpellType(SPELL_COMBAT);
  SetSkills( ([ 
    "conjuring"   : 60,
    "necromancy" : 60,
    ]) );
  SetDifficulty(50);
  SetMorality(-10);
  SetAutoDamage(0);
  SetDamageType(MAGIC);
  SetMessages(({ ({ "are", "$target_name $target_verb "
                                   "unharmed by $agent_possessive_noun "
                       "drain." }),
                ({ "", "$agent_possessive_noun %^ORANGE%^drain%^RESET%^ brings "
                         "pain to $target_name." }),
                ({ "", "$agent_possessive_noun %^BLUE%^drain%^RESET%^ sucks "
                        "the life out of $target_name!" }) }));
  SetHelp(
         "This necromantic spell inflicts tremendous damage by "
         "draining the target's soul.");
}
