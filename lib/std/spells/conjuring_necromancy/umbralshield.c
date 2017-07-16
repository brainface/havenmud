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
  SetSpell("umbral shield");
  SetRules("");
  SetSpellType(SPELL_DEFENSE);
  SetSkills( ([
     "necromancy" : 150,
     "conjuring"  : 150,
    ]) );
  SetDifficulty(50);
  SetProtectionTypes(ALL_EXTERNAL);
  SetShieldType(SHIELD_DAMAGE);
  SetMessages( ({
   ({ "begin", "%^BOLD%^%^BLACK%^Shadows%^RESET%^ spread out from $agent_name forming a barrier of darkness around $agent_objective." }),
    ({ "strike", "The %^BOLD%^%^BLACK%^shadows%^RESET%^ surrounding $agent_name bend as "
           "$target_possessive_noun attack $target_verb it." }),
    ({ "", "The %^BOLD%^%^WHITE%^shadows%^RESET%^ around $agent_name fade into the light." }),
    }) );
  SetHelp(
           "The necromancer creates an umbra around themselves and then uses the darkness "
           "in combination with their necromantic powers to give the shadows form "
           "and matter allowing them to provide protection from physical attacks "
           "for a small amount. This spell can only effect the caster.");           
 }

