/*  A low level fire spell designed
    to take advantage of fire magic
    booster skill.
    -Melchezidek 6/2/2008
*/

#include <lib.h>
#include <magic.h>
#include <damage_types.h>

inherit LIB_SPELL;

static void create() {
  spell::create();
  SetSpell("flare");
  SetRules("", "LIV");
  SetSpellType(SPELL_COMBAT);
  SetSkills( ([
     "conjuring" : 20,
     "evokation" : 20,
     "fire magic" : 1,
     ]) );
  SetEnhanceSkills( ({ "fire magic" }) );
  SetDifficulty(10);
  SetAutoDamage(0);
  SetDamageType(HEAT);
  SetHelp(
      "This low level fire spell is the staple of the fire mage's spell"
      " book. When mastered, this spell can harness the elemental power of"
      " fire to send a small flare at one's target."
      );
  SetMessages( ({
     ({"shoot",
       "$agent_name $agent_verb a %^RED%^flare%^RESET%^ at $target_name" +
       " to no effect."}),
     ({"slam",
       "$agent_name_possessive %^RED%^flare%^RESET%^ $agent_verb into " +
       "$target_name."}),
     ({"scorch",
       "$agent_name_possessive %^RED%^flare%^RESET%^ $agent_verb $target_name."}),
   }) );    
}
