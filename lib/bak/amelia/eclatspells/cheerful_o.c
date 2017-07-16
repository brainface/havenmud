// Eclat spell coded by Amelia@Haven, Dec '98
#include <lib.h>
#include <magic.h>
#include <damage_types.h>
inherit LIB_SPELL;

static void create() {
   spell::create();
   SetSpell("cheerful obstacles");
   SetRules("","LIV");
   SetReligions("Eclat");
   SetSpellType(SPELL_DEFENSE);
   SetProtectionTypes(ALL_PHYSICAL);
   SetProtectionAmount(33);
   SetProtectionTime(15);
   SetDifficulty(15);
   SetMagicCost(30,10);
   SetRequiredMagic(40);
   SetSkills( ([
                 "natural"       : 5,
                 "enchantment" : 5,
            ]) );
   SetMessages( ({
                   ({ "","%^BLUE%^A cheerful mist coalesces around "
                      "$target_name.%^RESET%^" }),
                   ({ "","$target_possessive_noun attack "
                      "disappears in the %^BLUE%^mist%^RESET%^ "
                      "surrounding $agent_name." }),
                   ({ "","%^BLUE%^The mist around $agent_name "
                      "fades into nothingness.%^RESET%^" }),
              }) );
  SetHelp(
           "Cheerful obstacles protect the target, or caster if "
           "no target is given, from physical damage.");
}


/* Approved by Dylanthalus on Thu Dec  3 01:50:04 1998. */
