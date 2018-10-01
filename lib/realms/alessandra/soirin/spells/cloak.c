/*   Portia  12-4-98
    A non-targetable defense spell for the Soirin faith.
    Removed necromancy to work for clerics again by Alessandra
*/

#include <lib.h>
#include <magic.h>
#include <damage_types.h>
inherit LIB_SPELL;

static void create() {
  spell::create();
  SetSpell("cloak of darkness");
  SetSpellType(SPELL_DEFENSE);
  SetRules("");
  SetSkills( ([
     "evokation"  : 15,
     "faith"      : 15,
    ]) );
  SetDifficulty(30);
  SetMagicCost(40,40);
  SetShieldType(SHIELD_TIMED);
  SetProtectionTypes(ALL_PHYSICAL);
  SetHelp("This is a non-targetable spell that protects the "
    "caster in a cloak of darkness, shielding her from physical "
    "damage for a length of time.");
  SetMessages( ({
    ({"", "A %^CYAN%^BOLD%^cloak%^RESET%^ of protective darkness falls over "
        "$target_name."}),
    ({"strike", "The cloak protecting $agent_name %^BLUE%^shimmers%^RESET%^ "
        "as $target_name $target_verb it."}),
    ({"", "The protective cloak %^RED%^dissapates%^RESET%^."}),
  }) );
  }
