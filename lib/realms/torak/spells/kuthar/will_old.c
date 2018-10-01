//--  Torak@Haven  --//
//--  Will of Old  --//
//--    Kuthar     --//

// edited by torak 10/28/12

#include <lib.h>
#include <magic.h>
#include <damage_types.h>

inherit LIB_SPELL;

static void create() {
  spell::create();
  SetSpell("will of old");
  SetRules("", "LIV");
  SetSpellType(SPELL_COMBAT);
  SetSkills( ([ 
    "faith" : 150,
    "natural magic" : 150,
    "evokation" : 150,
    ]) );
  SetDifficulty(60);
  SetMorality(0);
  SetDamageType(MAGIC|BLUNT|HEAT);
  SetEnhanceSkills( ({ "fire magic" }) );
  SetMessages(({ ({ "", "$agent_name fails to use the superior "
                    "power of the ancients properly and the attack "
                    "against $target_name fails." }),

                 ({ "", "$agent_name uses the superior "
                    "%^BOLD%^power of the ancients%^RESET%^ "
                    "to will a mystical "
                    "force into being that slams hard into "
                    "$target_name." }),

                 ({ "", "$agent_name uses the superior "
                    "%^BOLD%^power of the ancients%^RESET%^ "
                    "to will a mystical "
                    "force into being that slams hard into "
                    "$target_name, pummeling $target_possessive "
                    "body and %^RED%^burning%^RESET%^ "
                    "$target_possessive skin." }),

    }) );
  SetHelp(
          "Will of Old harnesses the mighty and awesome "
          "power of vengeful ancestors, pummeling and focusing the "
          "energy flow onto a single target, consuming it with fire.");
  }
