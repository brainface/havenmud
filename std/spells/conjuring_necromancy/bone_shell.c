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
  SetSpell("bone shell");
  SetRules("", "LIV");
  SetSpellType(SPELL_DEFENSE);
  SetSkills( ([
     "necromancy" : 25,
     "conjuring"  : 25,
    ]) );
  SetDifficulty(20);
  SetProtectionTypes(ALL_EXTERNAL);
  SetShieldType(SHIELD_DAMAGE);
  SetMessages( ({
   ({ "use", "$agent_name $agent_verb dark powers to create a bone shell around $target_name." }),
   ({ "", "The %^BOLD%^%^RED%^bone shell%^RESET%^ surrounding $agent_name creaks as $target_possessive_noun attack strikes it." }),
   ({ "", "The %^RED%^bone shell%^RESET%^ around $agent_name crumbles to dust." }),
   }) );
  SetHelp(
           "This spell allows an aspiring necromancer to transform their necromantic "
           "energies into a physical barrier that offers them some protection from "
           "damage."
           );           
 }

