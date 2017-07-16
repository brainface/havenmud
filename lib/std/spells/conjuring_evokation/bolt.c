/*  Bolt spell.
 *  Basic lightning bolt.
 *  Recoded by Duuktsaryth  3 September 1997
 */
#include <lib.h>
#include <magic.h>
#include <damage_types.h>

inherit LIB_SPELL;

static void create(){
  spell::create();
  SetSpell("bolt");
  SetRules("", "LIV");
  SetSpellType(SPELL_COMBAT);
  SetSkills( ([
    "conjuring" : 75,
    "evokation" : 75,
    ]) );
  SetMorality(0);
  SetDifficulty(30);
  SetAutoDamage(0);
  SetDamageType(SHOCK);
  SetEnhanceSkills( ({ "shock magic" }) );
  SetMessages( ({ 
    ({ "strike", 
      "$agent_name $agent_verb $target_name with a lightning bolt!" }),
    ({ "are",
      "$target_name $target_verb %^RED%^charred%^RESET%^ by " +
      "$agent_possessive_noun lightning bolt." }),
    ({ "fry",
      "$agent_name $agent_verb $target_name with a " +
      "powerful bolt of magical lightning!" }),
    ({ "annihilate",
      "$agent_name%^YELLOW%^ $agent_verb%^RESET%^ $target_name with a " +
      "huge bolt of magically summoned lightning." }),
    }) );
  SetHelp(
    "This more advanced attack spell focuses a bolt of lightning at a target. \n"
    "Default is current enemy." 
    );
}


/* Approved by Duuktsaryth on Wed Sep  3 11:16:11 1997. */
