#include <lib.h>
#include <damage_types.h>
#include <magic.h>
inherit LIB_SPELL;
static void create() {
    spell::create();
    SetSpell("wound");
    SetRules("", "LIV");
    SetSpellType(SPELL_COMBAT);
    SetSkills( ([
      "conjuring"  : 10,
      "necromancy" : 10,
    ]) );
    SetDifficulty(30);
    SetAutoDamage(0);
    SetDamageType(MAGIC|SLASH);
    SetMessages( ({
    ({ "feel", "$target_name $target_verb a small scratch appear on "
    "$target_possessive body." }),
    ({ "wince", "$target_name $target_verb in pain as a small cut opens up "
    "on $target_possessive body." }),
    ({ "howl", "$target_name $target_verb in agony as a gaping wound forms "
    "on $target_possessive body." })
}) );
  SetHelp(
    "This spell is the primary attack of a young necromancer.  Drawing "
    "the forces of pain and injury, it causes a gash to rip itself open "
    "on the target's body.");
}
