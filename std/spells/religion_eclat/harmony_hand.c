//
// The 'harmony hand' spell
// Created by Zaxan@Haven
//

#include <lib.h>
#include <magic.h>

inherit LIB_SPELL;

static void create() {
   spell::create();
   SetSpell("harmony hand");
   SetSpellType(SPELL_HEALING);
   SetRules("", "LIV");
   SetSkills( ([ 
     "healing" : 25,
     "natural magic"   : 25,
      ]) );
   SetAutoHeal(1);
   SetHealing(100,100);
   SetMagicCost(25,50);
   SetDifficulty(40);
   SetMessages( ({
      ({ ({ "lay" }), "$agent_name $agent_verb his hands on $target_name, "
                      "but nothing happens." }),
      ({ ({ "wave","look" }), "$agent_name $agent_verb $agent_possessive "
                              "hands in the air. Suddenly, $target_name "
                              "$target_verb much healthier." }),
      ({ ({ }), "$agent_possessive_noun hands suddenly turn a bright "
                "%^YELLOW%^BOLD%^golden%^RESET%^ color as they put more "
                "health into $target_name." }),
      }) );
  SetReligions("Eclat");
  SetHelp(
           "This spell uses the great power of the Eclat natural magic to instil "
           "healing abilities into the hands of the caster. Using a simple "
           "touch of those hands will cause health to increase and wounds "
           "to shrink.");
}
