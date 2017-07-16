// General Cleric Healing Spell by Amelia@Haven

#include <lib.h>
#include <spell.h>
#include <damage_types.h>
inherit LIB_SPELL;

static void create() {
   spell::create();
   SetSpell("heal");
   SetRules("","LIV");
   SetAutoHeal(1);
   SetSpellType(SPELL_HEALING);
   SetSkills( ([
                 "healing" : 17,
                 "faith"   : 17,
            ]) );
   SetRequiredMagic(15);
   SetMagicCost(10,5);
   SetDifficulty(30);
   SetHealing(35,30);