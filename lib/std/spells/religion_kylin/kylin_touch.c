/*  Elven Touch Spell */
#include <lib.h>
#include <magic.h>
#include <damage_types.h>
inherit LIB_SPELL;

static void create() {
  ::create();
  SetSpell("kylin touch");
  SetSpellType(SPELL_COMBAT);
  SetRules("", "LIV");
  SetReligions("Kylin");
  SetMagicCost(25, 25);
  SetStaminaCost(5, 5);
  SetDamageType(HEAT);
  SetEnhanceSkills( ({ "fire magic" }) );
  SetSkills( ([
      "faith"       : 80,
      "evokation" : 80,
    ]) );
  SetDifficulty(30);
  SetAutoDamage(0);
  SetMessages( ({
    ({ "brush", "$agent_name%^BLUE%^ $agent_verb%^RESET%^ $target_name lightly." }),
    ({ "grasp", "$agent_name%^YELLOW%^ $agent_verb%^RESET%^ hold of $target_name burning $target_objective badly!" }),
    ({ "burn",  "$agent_name $agent_verb%^RED%^ $target_name%^RESET%^ with a touch of $agent_possessive palm." }),
     }) );
  SetHelp(
          "This spell allows an Kylin follower to use the ancient "
          "arts of searing the unbeliever on a target.");
 }
