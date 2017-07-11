#include <lib.h>
#include <damage_types.h>
#include <magic.h>
inherit LIB_SPELL;

static void create() {
  ::create();
  SetSpell("eclat bite");
  SetReligions("Eclat");  
  SetSpellType(SPELL_COMBAT);
  SetSkills( ([
    "enchantment" : 1,
    "natural magic"   : 1,
    ]) );
  SetRules("", "LIV");
  SetAutoDamage(0);
  SetDamageType(SHOCK|PIERCE);
 SetEnhanceSkills( ({ "shock magic" }) );
  SetDifficulty(10);
  SetHelp("The Eclat Bite is a fairly ineffective form of combat, but "
        "provides opportunities for new Eclat druids. ");
  SetMessages( ({
    ({ "induce", 
          "$agent_name $agent_verb the wind to form the shape of a wolf, "
                "snapping down on $target_name." }),
    ({ "attack",
          "$agent_name $agent_verb $target_name with a wind-formed wolf."
          }),
    ({ "",
          "$agent_possessive wind-wolf bites down on $target_name!",
          }),
     }) );
}
