/*  The 'touch' spell */
#include <lib.h>
#include <damage_types.h>
#include <magic.h>
inherit LIB_SPELL;

static void create() {
  spell::create();
  SetSpell("touch of death");
  SetRules("LIV", "");
  SetSpellType(SPELL_COMBAT);
  SetSkills( ([
     "necromancy" : 150,
     "faith"      : 150,
    ]) );
  SetDifficulty(120);
  SetAutoDamage(0);
  SetDamageType(SHOCK);
  SetEnhanceSkills( ({ "shock magic" }) );
  SetHelp(
     "This tool is a powerful attack that is a favorite amongst many necromancers "
     "of Kailie. By channeling the powers of death, the necromancers uses this "
     "power to cause great damage to their target. "
  );
  SetMessages( ({
      ({ "seize", "$agent_name%^RED%^ $agent_verb%^RESET%^ hold of "
                  "$target_name, causing a spasm of pain to pass over "
                  "$target_possessive_noun face." }),
    ({({"grasp", "grab"}),"$agent_name%^RED%^BOLD%^ $agent_verb%^RESET%^ out towards "
                  "$target_name, and $agent_verb on to $target_possessive "
                  "body, causing a wracking moan of pain." }),
           }) );
  }
