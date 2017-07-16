// Torak@Haven 2013
// If shields ever get the ability to damage atackers again,
// this shield should get that sort of code.
// Not going to add unused code for no reason.

#include <lib.h>
#include <damage_types.h>
#include <magic.h>

inherit LIB_SPELL;

static void create() {
  ::create();
  SetSpell("superior lightning shield");
  SetRules("", "LIV");
  SetSpellType(SPELL_DEFENSE);
  SetProtectionTypes(ALL_EXTERNAL);
  SetShieldType(SHIELD_TIMED);
  SetSkills( ([
     "faith"     : 200,
     "evokation" : 200,
    ]) );
  SetDifficulty(30);
  SetReligions("Damhair");
  SetMessages( ({

    ({ "", "%^BOLD%^YELLOW%^A sphere of lightning "
           "thunders into being around $target_possessive_noun body.%^RESET%^" }),

    ({ "hit", "%^YELLOW%^BOLD%^The air thunders loudly as $target_name $target_verb "
              "the sphere of lightning around $agent_possessive_noun body.%^RESET%^"}),

    ({ "", "%^YELLOW%^The sphere of lightning around $agent_possessive_noun body blinks out of "
           "existance, leaving the air fesh and crisp.%^RESET%^" }),

    }) );
  SetHelp(
    "A magical defense spell that allows the cleric to create "
    "a superior shield of lightning around self or a target.");
}
