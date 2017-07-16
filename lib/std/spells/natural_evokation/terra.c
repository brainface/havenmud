/*  Terra Spell
 * Sends chunks of dirt and such in an attack.
 * Balanced and recoded 3 Sep 1997
 * Duuktsaryth @ Haven
 */
#include <lib.h>
#include <magic.h>
#include <damage_types.h>

inherit LIB_SPELL;

static void create() {
  spell::create();
  SetSpell("terra");
  SetRules("", "LIV");
  SetSpellType(SPELL_COMBAT);
  SetSkills( ([
    "natural magic" : 25,
    "evokation"     : 25,
   ]) );
  SetDifficulty(20);
  SetMorality(0);
  SetAutoDamage(0);
  SetDamageType(BLUNT);
  SetMessages( ({
    ({ "bruise",
      "$agent_name%^GREEN%^ $agent_verb%^RESET%^ $target_name with flying debris." }),
    ({ "are", "$target_name $target_verb %^GREEN%^scratched badly%^RESET%^ by the earth and rocks thrown by $agent_name." }),
    ({ "wound", "$agent_name%^RED%^ $agent_verb%^RESET%^ $target_name %^RED%^badly%^RESET%^ with $agent_possessive attack." }),
    }) );
   SetHelp(
            "This spell will attempt to tear small chunks of earth "
            "out of the ground and toss them at the opponent.  If cast "
            "without specifying a target in combat, the chunk of "
            "earth is targetted at your current enemy." );
}


/* Approved by Duuktsaryth on Wed Sep  3 19:19:57 1997. */
