// Created by anonymous
// Fixed By Rhakz - Angel Cazares
// Summary: Paralyzes a target
// Date: 08/10/98 (Fixing date)
//
#include <lib.h>
#include <magic.h>
#include <damage_types.h>
inherit LIB_SPELL;

static void create() {
  spell::create();
  SetSpell("soultap");
  SetRules("LIV","");
  SetSpellType(SPELL_COMBAT);
  SetDamageType(MAGIC|COLD);
  SetEnhanceSkills( ({ "ice magic" }) );
  SetAutoDamage(0);
  SetStaminaCost(30, 20);
  SetDifficulty(60);
  SetSkills( ([
     "conjuring"  : 135,
     "necromancy" : 135,
     ]) );
  SetMessages( ({
    ({ "laugh", "$target_name $target_verb off $agent_possessive_noun feeble magic." }),
    ({ ({ "gasp", "grasp" }), "$target_name%^BOLD%^RED%^ $target_verb%^RESET%^ as $agent_name loosely $agent_verb a piece of $target_possessive soul!" }),
    ({ ({ "shudder", "sob", "grasp" }), "$target_name%^RED%^ $target_verb and $target_verb as $agent_name firmly $agent_verb $target_possessive soul!" }),
    }) );
  SetHelp(
          "This spell, forgotten long ago by most mages, touches the inner soul of a LIVing target, "
          "doing moderate damage and freezing them in horror and chill."
  );
}


varargs int eventCast(object who, int level, mixed useless, object *targets) {
  int x = ::eventCast(who, level, useless, targets);
  // debug("ST eC: " + x);
  if (x >= 1) targets->AddParalyzed(level/10);
  return x;
}


/* Approved by Dylanthalus on Fri Jan 22 01:46:28 1999. */
