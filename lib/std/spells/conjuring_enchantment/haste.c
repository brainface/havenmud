// Coded by Vanyel@Haven 10/27/97
#include <lib.h>
#include <magic.h>
inherit LIB_SPELL;

static void create() {
  spell::create();
  SetSpell("haste");
  SetSkills( ([
     "conjuring" : 60,
     "enchantment" : 60,
  ]) );
  SetRules("", "LIV");
  SetMagicCost(20, 20);
  SetSpellType(SPELL_OTHER);
  SetDifficulty(25);
  SetHelp(
          "Speeds up the target's heartbeat.  If cast without a target, it will "
          "speed up the caster's heartbeat.");
  }

varargs int eventCast(object who, int level, mixed b, object array targets) 
  {
  object target = targets[0];
  if (target->GetCaffeine() > target->GetStatLevel("durability") * 10)
     {who->eventPrint("That person is too wired right now without "
      "your help.");
     return 1; }
  if (target==who) {
     send_messages("speed",
        "$agent_name $agent_verb $agent_reflexive up.",
         who, 0, environment(who));
     }
  else {
    send_messages("speed",
     "$agent_name $agent_verb $target_name up.",
      who, target, environment(target));
  }
  target->AddCaffeine(level/4 );
  return 1;
}

int CanCast(object who, int level, mixed b, object *targets) {
	object target = targets[0];
   if (target->GetCaffeine() > target->GetStatLevel("durability") * 10) {
   	  who->eventPrint("That person is too wired right now without "
                      "your help.");
     return 0; 
     }
   return ::CanCast(who, level, b, targets);
}
  
/* Approved by Balishae on Wed Oct 29 20:26:22 1997. */
