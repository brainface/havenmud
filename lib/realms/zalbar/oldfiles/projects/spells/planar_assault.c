/* Planar Assault Spell
 * Originally Created by <PERSON>
 * Balanced 8 Sept 1997 by Duuktsaryth@Haven
 */
#include <lib.h>
#include <magic.h>
#include <damage_types.h>

inherit LIB_SPELL;

static void create() {
    spell::create();
    SetSpell("planar assault");
    SetRules("", "LIV");
    SetSpellType(SPELL_COMBAT);
    SetRequiredMagic(40);
    SetSkills( ([
    "conjuring" : 35,
    "enchantment" : 35,
    ]) );
    SetMagicCost(20, 20);
    SetDifficulty(15);
    SetAutoDamage(0);
    SetDamage(MAGIC, 50, 30);
    SetMessages(({ ({ "shrug", "$target_name $target_verb off "
                                "$agent_possessive_noun planar assault "
                                "without difficulty." }),
                         ({ "shudder", "$target_name $target_verb "
                                "in pain from $agent_possessive_noun "
                                "planar assault." }),
                         ({ "", "$agent_possessive_noun "
                                "spell assaults  $target_name"
                                " with cold raw energy from another "
                                "plane!" }),
                         ({ "are", "$target_name $target_verb racked by "
                                "spasms by $agent_possessive_noun "
                                "planar assault." }) }));
  SetHelp(
            "This spell opens a small gate into one of the elemental "
            "planes and channels energy from there into the core of the "
            "caster's oponent.  As with all planar magic spells, the "
            "effects are somewhat uncertain.");
}


/* Approved by Duuktsaryth on Mon Sep  8 12:33:25 1997. */
