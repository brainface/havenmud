#include <lib.h>
#include <damage_types.h>
#include <magic.h>
inherit LIB_SPELL;

static void create() {
  spell::create();
  SetSpell("divine retribution");
  SetSpellType(SPELL_COMBAT);
  SetRules("", "LIV");
  SetSkills( ([
     "evokation" : 100,
     "faith" : 100,
      ]) );
  SetDifficulty(120);
  SetAutoDamage(0);
  SetDamageType(MAGIC|HEAT);
  SetEnhanceSkills( ({ "fire magic" }) );
  SetMessages( ({
     ({ "", "$agent_name prays to $agent_possessive god, calling "
                "down %^BOLD%^%^YELLOW%^retribution%^RESET%^ on "
                "$target_name harming them slightly." }),
     ({ "scorch", "$agent_possessive_noun god hears $agent_possessive prayers "
                 "and $target_possessive_noun skin begins to burn and "
                 "bubble with the %^BOLD%^%^CYAN%^divine retribution%^RESET%^ from "
                 "$agent_possessive god." }),
           ({ ({ "burn", "scorch" }), 
                "$agent_name calls out for %^BOLD%^%^RED%^divine retribution%^RESET%^ "
                "and $target_name screams as $target_possessive is immolated in "
                "divine flames." })
           }) );
  SetHelp(
          "A skilled cleric can call out to their god to immolate "
         "their oppenent with divine flames.");
  }
