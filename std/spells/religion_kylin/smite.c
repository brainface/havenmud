/*  A spell for the Kylin clerics.
 *  Duuktsaryth
 */
#include <lib.h>
#include <damage_types.h>
#include <magic.h>
inherit LIB_SPELL;

static void create() {
  spell::create();
  SetSpell("smite");
  SetReligions("Kylin");
  SetDifficulty(15);
  SetRules("LIV", "");
  SetSpellType(SPELL_COMBAT);
  SetDamageType(HEAT);
  SetEnhanceSkills( ({ "fire magic" }) );
  SetAutoDamage(0);
  SetSkills( ([
     "faith"       : 5,
     "evokation" : 5,
    ]) );
  SetHelp(
          "This spell is a Kylin faithful's primary attack spell. "
          "The spell summons a bolt of holy light from the fingertips "
          "of the caster and damages the core of the target's being.");
  SetMessages( ({
    ({ "are", "$agent_name $agent_verb ineffective with $agent_possessive feeble attack on $target_name." }),
    ({ "burn", "$agent_name%^YELLOW%^ $agent_verb%^RESET%^ $target_name with $agent_possessive smiting attack." }),
    ({ "", "The %^YELLOW%^bolts%^RESET%^ of pure divine justice that flow from $agent_possessive_noun fingers %^RED%^sear%^RESET%^ $target_name with their power." }),
    }) );
}
