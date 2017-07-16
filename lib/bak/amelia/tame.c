#include <lib.h>
#include <magic.h>
#include <rooms.h>
inherit LIB_SPELL;

static void create() {
  ::create();
  SetSpell("tame");
  SetSpellType(SPELL_OTHER);
  SetRules("LIV");
  SetSkills( ([
    "natural magic"   : 20,
    ]) );
  SetDifficulty(25);
  SetMagicCost(50, 30);
  SetHelp(
    "This spell attempts to tame an animal that has been called out of the "
	"wilderness by the castor.  Taming gives castors the ability to "
	"command the animal to follow them."
    );
}
 
varargs int CanCast(object who, int level, mixed limb, object *targets) {
  object t = targets[0];
  if (!t->CheckCreator()) {
    who->eventPrint("You didn't call " + t->GetShort() + "!");
    return 0;
  }
  if (t->GetInCombat()) {
    who->eventPrint(capitalize(t->GetShort()) + " must be rescued from combat "
		"before you can charm " + objective(t)+ "!");
    return 0;
    }
  if (t->GetOwner() != "") {
	if(t->GetOwner() == t->GetCreator()) {
           who->eventPrint(capitalize(t->GetShort()) + " has already been tamed by "
	      	+ capitalize(t->GetCreator()) + ".");
        return 0;
        }
        who->eventPrint(capitalize(t->GetShort()) + " has already been charmed by "
		"someone!");
	return 0;
  }
  return ::CanCast(who, level, limb, targets);
}

int eventCast(object who, int level, mixed limb, object *targets) {
  object t = targets[0];
  int resistance, offense;
  
  offense    = (level + who->GetSkillLevel("natural magic"));
  resistance = (t->GetLevel()*random(50));
  if (offense > resistance) {
    send_messages( ({ "move","gaze" }),
      "$target_name $target_verb next to $agent_name and $target_verb lovingly "
	"at $agent_objective.",
      who, t, environment(t) );
    t->SetOwner(who->GetKeyName());
    return 1;
  }
  send_messages( ({ "ignore" }),
    "$target_name $target_verb the effects of $agent_possessive_noun taming spell!",
    who, t, environment(who) );
  return 1;
}
