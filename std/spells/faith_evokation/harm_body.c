//
// The 'harm body' spell
// Created by Zaxan@Haven
// Balanced by Ranquest 02/06/99
//

#include <lib.h>
#include <magic.h>
#include <damage_types.h>

inherit LIB_SPELL;

static void create() {
   spell::create();
   SetSpell("harm body");
   SetMorality(0);
   SetSpellType(SPELL_COMBAT);
   SetRules("", "LIV");
   SetAutoDamage(0);
   SetSkills( ([
     "faith" : 75,
     "evokation" : 75,
   ]) );
   SetDamageType(MAGIC|BLUNT);
   SetDifficulty(60);
   SetMessages( ({
      ({ ({ "wave" }), "$agent_name $agent_verb $agent_possessive hands "
        "in the air, but nothing happens." }),
      ({ ({ "direct" }), "By waving $agent_possessive hands in the "
        "air, $agent_name $agent_verb a strong force "
        "which %^RED%^harms%^RESET%^ $target_possessive_noun body." }),
      ({ ({ "summon" }), "The sky flashes as $agent_name $agent_verb "
        "powerful godly forces to %^RED%^harm%^RESET%^ "
        "$target_possessive_noun body with full force." }),
      }) );
  SetHelp(
           "Using the ultimate powers from the gods, the "
           "caster is able to extremely harm the body of his/her target "
           "using this spell, doing large amounts of damage.");
}
