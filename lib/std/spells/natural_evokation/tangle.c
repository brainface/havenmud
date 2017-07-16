/*  Ranger Spell that uses SetParalyze();
 * Created 12 Sept 1997
 * Duuktsaryth@Haven
 */
#include <lib.h>
#include <magic.h>
inherit LIB_SPELL;

static void create() {
  spell::create();
  SetSpell("tangle");
  SetRules("LIV","");
  SetSpellType(SPELL_COMBAT);
  SetMagicCost(15, 10);
  SetMagicCost(5, 5);
  SetDifficulty(14);
  SetSkills( ([
      "natural magic" : 12,
      "evokation"     : 12,
    ]) );
  SetHelp(
     "Summons vines to tangle an opponent for a short period of time."
    );
 }

varargs int eventCast(object who, int level, mixed n, object array targets) {
  object target = targets[0];
  if( CanAttack(who, targets, GetSpellLevel() + level/5) == - 1 ) {
	    who->eventPrint("Your powers fail you.");
	    return 0;
  }
  if (target->GetStatLevel("agility") + random(100) < level + random(50)) {
     send_messages( ({ "become", "are" }),
      "$target_name $target_verb tangled in a "
     "%^GREEN%^web of vines%^RESET%^ and $target_verb unable to move!",
     who, target, environment(who));
     target->SetParalyzed(random(4)+1);
     return 1;
  }
  send_messages("dodge",
      "$target_name $target_verb out of the way of $agent_possessive_noun "
      "%^GREEN%^vine%^RESET%^ attack.",
       who, target, environment(who) );
  return 1;
}


/* Approved by Duuktsaryth on Sun Sep 14 22:59:05 1997. */
