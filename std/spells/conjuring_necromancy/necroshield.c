//
// Low Level Necro/conj shield
// Thoin@haven
//
#include <lib.h>
#include <magic.h>
#include <damage_types.h>
inherit LIB_SPELL;

static void create() {
  ::create();
  SetSpell("necromantic shield");
  SetRules("", "LIV");
  SetSpellType(SPELL_DEFENSE);
  SetSkills( ([
     "necromancy" : 60,
     "conjuring"  : 60,
    ]) );
  SetDifficulty(20);
  SetProtectionTypes(ALL_EXTERNAL);
  SetShieldType(SHIELD_TIMED);
  
  SetMessages( ({
   ({ "use", "$agent_name $agent_verb necromantic energies to create a shell around $target_name." }),
   ({ "strike", "The %^BOLD%^%^RED%^shell%^RESET%^ surrounding $agent_name wails as "
           "$target_possessive_noun attack $target_verb it." }),
   ({ "", "The %^RED%^energies%^RESET%^ around $agent_name fade." }),
    }) );
  SetHelp(
                "This spell allows an aspiring necromancer to transform their necromantic "
           "energies into a physical barrier that offers them little protection from "
           "physical damage.");           
 }

