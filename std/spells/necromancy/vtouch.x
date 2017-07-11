//
// Vampiric Touch
// Thoin@haven
//
#include <magic.h>
#include <lib.h>
#include <damage_types.h>
inherit LIB_SPELL;

static void create() {
  spell::create();
  SetSpell("vampiric touch");
  SetRules("", "LIV");
  SetSpellType(SPELL_COMBAT);
  SetRecoveryTime(random(2)+1);
  SetDifficulty(75);
  SetSkills( ([
    "necromancy" : 120,
    "conjuring"  : 120,
    ]) );
  SetHelp(
    "This powerful spell allows an experienced necromancer to drain "
    "a target of their life energies while replenishing their own.");
  
}

varargs int eventCast(object who, int level, mixed x, object *t) {
  object target = t[0];
  int damage = GetDamage(level);
  int hpsteal = (level*2);
    if( CanAttack(who, t, GetSpellLevel() + level/5) == - 1 ) {
	    who->eventPrint("Your powers fail you.");
	    return 0;
	  }  
  send_messages(({"scream","appear"}),
         "$target_name $target_verb in agony as %^RED%^blood%^RESET%^ flows "
         "freely from $target_possessive body into $agent_possessive_noun hand."
         ,who, target, environment(who) );
 target->eventReceiveDamage(who, MAGIC, damage, 0, target->GetRandomLimb(target->GetTorso()));      
 who->AddHealthPoints(hpsteal);
 return 1;
}
