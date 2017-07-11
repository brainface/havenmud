#include <lib.h>
#include <damage_types.h>
#include <magic.h>
inherit LIB_SPELL;

static void create() {
  spell::create();
  SetSpell("poison sphere");
  SetRules("", "LIV");
  SetSpellType(SPELL_COMBAT);
  SetSkills( ([
     "conjuring" : 50,
     "evokation" : 50,
     ]) );
  SetAutoDamage(0);
  SetDamageType(POISON);
  SetEnhanceSkills( ({ "poison magic" }) );
  SetMessages( ({
   ({ "form", "With a small movement of $agent_possessive_noun hands a small globe "
                "is formed and then suddenly %^GREEN%^hurled%^RESET%^ "
                "at $target_name causing $target_objective to look ill." }),
   ({ "summon", "$agent_name $agent_verb particles from the air that begin "
                "forming a large sphere of a green substance that is "
                "sent crashing into $target_name causing $target_possessive skin "
                "to begin boiling. " }),
   ({ "", "After a slew of incantations $agent_possessive_noun eyes begin glowing "
          "causing bacteria to be stripped from the air and forged into an "
          "enormous spherical object in the sky that crashes in to $target_name "
          "causing %^GREEN%^extreme damage%^RESET%^." })
   }) );
  SetHelp(
    "This spell creates a large sphere of pure poison and attempts to strike "
    "a target leaving them extremely damaged."
   );
  SetDifficulty(30);
}
