/*  Venomous Blood */
#include <lib.h>
#include <damage_types.h>
#include <magic.h>
inherit LIB_SPELL;

static void create() {
  spell::create();
  SetSpell("venomous blood");
  SetRules("", "LIV");
  SetSpellType(SPELL_COMBAT);
  SetSkills( ([
     "conjuring" : 75,
     "evokation" : 75,
           ]) );
  SetAutoDamage(0);
  SetDamageType(POISON);
  SetEnhanceSkills( ({ "poison magic" }) );
  SetMessages( ({
   ({ "reach", "$agent_name $agent_verb out and grabs $target_possessive_noun body infusing it with poison."}),
   ({ "explode", "$agent_name $agent_verb out with hands of pure poison and %^GREEN%^grasp%^RESET%^"
                 " $target_possessive_noun neck causing it to vein up momentarily." }),
   ({ "", "$agent_possessive_noun veins %^RED%^pulse%^RESET%^ out as "
          "the blood flow thickens until finally toxins are "
          "unleashed through a stream of %^GREEN%^venomous%^RESET%^ "
          "blood %^RED%^scorching%^RESET%^ $target_name causing an "
          "enormous amount of pain." })
   }) );
  SetHelp(
    "This spell calls forth the energy of poison to cause"
    " an explosion of venomous damage to the target."
   );
  SetDifficulty(40);
}
