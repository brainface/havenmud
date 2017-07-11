//-- Torak@Haven --//
//-- Flaming Arrow, made poisonous for Rath Cult --//
//-- Original done by Dunedain --//
//-- Modified by Thoin 11-26-05 --//

#include <lib.h>
#include <magic.h>
#include <damage_types.h>

inherit LIB_SPELL;

static void create() {
  spell::create();
  SetSpell("poison arrow");
  SetRules("", "LIV");
  SetSpellType(SPELL_COMBAT);
  SetSkills( ([
    "evokation" : 10,
    "faith"      : 10,
  ]) );
  SetDifficulty(20);
  SetMorality(-10);
  SetAutoDamage(0);
  SetDamageType(POISON);
  SetHelp("This spell allows a faithful priest to summon and hurl "
          "a poisonus arrow at the target which will hurt and "
          "poison them."
          );
  SetEnhanceSkills( ({ "poison magic" }) );
  SetReligions("Soirin");
  SetMessages(({ 
    ({ "are", "$target_name $target_verb unharmed by $agent_possessive_noun poison arrow." }),
    ({ "", "$agent_possessive_noun poison arrow%^GREEN%^ stings%^RESET%^ $target_name." }),
    ({ "", "$agent_possessive_noun poison arrow%^BOLD%^GREEN%^ slams%^RESET%^ $target_name." })
    }) );
}
