/* MADE by iunno
 * Mahkefel 2017--changed to damage shield, making faith necro damage shields only
 */
#include <lib.h>
#include <damage_types.h>
#include <magic.h>
inherit LIB_SPELL;

static void create() {
  ::create();
  SetSpell("wall of souls");
  SetRules("", "LIV");
  SetSpellType(SPELL_DEFENSE);
  SetShieldType(SHIELD_DAMAGE);
  SetSkills( ([
    "faith"      : 100,
    "necromancy" : 100,
    ]) );
  SetDifficulty(120);
  SetProtectionTypes(ALL_EXTERNAL);
  SetMessages( ({
   ({ ({"rip","wrap"}) , "$agent_name $agent_verb tormented souls from their rest and $agent_verb them around $target_name into a %^CYAN%^wall%^RESET%^ as they begin to %^BOLD%^%^RED%^SCREAM!%^RESET%^" }),
   ({ "assault", "The %^RED%^wall of souls%^RESET%^ around $agent_name screams in anger as $target_name $target_verb it." }),
   ({ "souls", "The %^RED%^souls %^RESET%^around $agent_name manage to free themselves and fade into nothingness." }),
   }) );
  SetHelp(
    "Using his evil power over the dead the priest "
    "manages to call fourth souls to form a wall around "
    "the target to protect them from a certain amount of "
    "magical and physical damage."
    );
}

