/*
 * The 'paralysis' spell
 * Paralyzes the target
 * Filename: paralysis.c
 * Created by Zaxan@Haven
 * 19th of June, 1997
 * Balanced 090897
 * Duuktsaryth@Haven
 */

#include <lib.h>
#include <magic.h>
#include <damage_types.h>

inherit LIB_SPELL;

static void create() {
	spell::create();
	SetSpell("paralysis");
	SetSpellType(SPELL_COMBAT);
  SetRules("", "LIV");
  SetDifficulty(20);
  SetSkills( ([
      "enchantment" : 45,
      "conjuring" : 45,
    ]) );
  SetMorality(0);
  SetHelp(
		"This spell will paralyze the target specified. The amount "
		"of time "
		"that the target is paralyzed depends on the caster's "
		"knowledge of the spell and the skills required to "
		"cast it.");
}

int CanCast(object who, int level, string limb, object array targets) {
	foreach(object target in targets) {
		if (target->GetParalyzed()) {
			message("my_action","But "+target->GetName()+" is "
				"already paralyzed!",who);
			return 0;
		} else {
			return spell::CanCast(who, level, limb, targets);
		}
	}
}

int eventCast(object who, int level, mixed limb, object array targets) {
	int chance;
        chance = level + random((int)who->GetSkillLevel("enchantment"));
    chance -= targets[0]->GetLevel() * 5;

    if(!present(targets[0]->GetKeyName(),environment(who))) return 0;

        if (chance < 0) {
		send_messages( ({ "look","shake" }), "$target_name "
					 	     "$target_verb somewhat "
						     "stunned, but "
						     "$target_nominative "
						     "$target_verb it off "
						     "immediately.",who,
						     targets,
						     environment(who));
		return 1;
	} else {
		send_messages("put", "$agent_name $agent_verb "
			      "$agent_possessive hands on $target_name, "
			      "paralyzing $target_objective "
			      "from all actions!",who,targets,
			      environment(who));
		targets->SetParalyzed(chance);
		return 1;
	}
}


/* Approved by Duuktsaryth on Mon Sep  8 13:43:32 1997. */
