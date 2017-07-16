/*  A buff Ass Spell */
#include <lib.h>
#include <damage_types.h>
#include <magic.h>
inherit LIB_SPELL;

static void create() {
  spell::create();
  SetSpell("flamestrike");
  SetSpellType(SPELL_COMBAT);
  SetRules("", "LIV");
  SetSkills( ([
     "evokation" : 150,
     "conjuring" : 150,
      ]) );
  SetEnhanceSkills( ({ "fire magic" }) );
  SetDifficulty(120);
  SetAutoDamage(0);
  SetDamageType(HEAT);
  SetMessages( ({
    ({ "burn", "$agent_name%^RED%^ $agent_verb%^RESET%^ $target_name badly with flamestrike." }),
    ({ "scorch", "$agent_name%^RED%^ $agent_verb%^RESET%^ into $target_possessive_noun skin, obviously wounding viscously." }),
    ({ ({ "burn", "scorch" }), "$agent_name%^RED%^ $agent_verb%^RESET%^ $target_name badly, scorching away flesh and crisping hair." })
    }) );
  SetHelp(
     "Creates a rush of flames and death to target either a living opponent or the current enemy."
     );
}
