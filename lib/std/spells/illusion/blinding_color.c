#include <lib.h>
#include <magic.h>
#include <damage_types.h>
inherit LIB_SPELL;

static void create() {
  ::create();
  SetSpell("blinding color");
  SetSpellType(SPELL_COMBAT);
  SetDamageType(MAGIC);
  SetRules("", "LIV");
  SetHelp("Using this simple illusion, the illusionist targets a spew of "
    "color that causes pain in the mind of the target."
          );
  SetSkills( ([
    "illusion" : 1,
    ]) );
  SetEnhanceSkills( ({ "fire magic" }) );
  SetAutoDamage(0);
  SetMessages( ({
    ({ "send", "$agent_name $agent_verb forth an "
      "%^BLUE%^a%^RED%^r%^YELLOW%^c%^RESET%^ of color at $target_name!" }),
    ({ "", "$agent_possessive_noun %^BLUE%^a%^RED%^r%^YELLOW%^c%^RESET%^ of "
      "color strikes $target_name quickly!" }),
    ({ "are", "$target_name $target_verb deeply pained by"
      " $agent_possessive_noun %^BLUE%^a%^RED%^r%^YELLOW%^c%^RESET%^ of "
      "color!" }),
  }) );
  SetDifficulty(5);
}

