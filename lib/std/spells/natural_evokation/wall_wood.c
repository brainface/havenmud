/*  Wall of Wood v 2.0 */
#include <lib.h>
#include <magic.h>
#include <damage_types.h>
inherit LIB_SPELL;

static void create() {
  ::create();
  SetSpell("wall of wood");
  SetRules("", "LIV");
  SetSpellType(SPELL_DEFENSE);
  SetSkills( ([
    "natural magic" : 120,
    "evokation"   : 120,
    ]) );
  SetShieldType(SHIELD_TIMED);
  SetProtectionTypes(ALL_EXTERNAL);
  SetDifficulty(25);
  SetMessages( ({
    ({ "", "A %^GREEN%^wall of wood%^RESET%^ rises from the ground "
          "to surround $target_name." }),
    ({ "strike", "%^GREEN%^Wood%^RESET%^ flies as $target_name "
                 "$target_verb the %^GREEN%^wall of wood%^RESET%^ "
                 "around $agent_name." }),
    ({ "", "The %^RED%^wall of wood%^RESET%^ around $agent_name "
           "withers and turns to dust." }),
    }) );
  SetHelp(
          "This spell summons a protection wall of plant life to "
          "surround a living target and protect them from physical "
          "damage.");
  }
