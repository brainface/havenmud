#include <lib.h>
#include <magic.h>
#include <damage_types.h>
inherit LIB_SPELL;
static void create() {
    spell::create();
    SetSpell("hunger");
    SetRules("LIV", "");
    SetSpellType(SPELL_COMBAT);
    SetSkills( ([
      "conjuring"  : 80,
      "necromancy" : 80,
    ]) );
    SetDifficulty(28);
    SetHelp(
      "This spell causes deep hunger pangs in the target at lower levels, "
      "but at the highest level, it creates a hunger which is almost "
      "insatiable."
    );
}
  
int eventCast(object who, int level, mixed limb, object array targets) {
    object target = targets[0];
    if( CanAttack(who, targets, GetSpellLevel() + level/5) == - 1 ) {
	    who->eventPrint("Your powers fail you.");
	    return 0;
	  }
    target->AddFood(-level);
    send_messages( ({ "point", "are" }),
      "As $agent_name $agent_verb, $target_name $target_verb overcome by a sudden and deep pang of hunger!",
      who, target, environment(who) );
    target->eventReceiveDamage(who, MAGIC, GetDamage(level), 0, target->GetRandomLimb(target->GetTorso()));  
    return 1;
}
