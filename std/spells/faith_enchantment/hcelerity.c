// haste for clerics
// Thoin@haven
#include <lib.h>
#include <magic.h>
inherit LIB_SPELL;

static void create() {
  spell::create();
  SetSpell("holy celerity");
  SetSkills( ([
     "faith" : 40,
     "enchantment" : 40,
  ]) );
  SetRules("", "LIV");
  SetMagicCost(30, 30);
  SetSpellType(SPELL_OTHER);
  SetDifficulty(25);
  SetHelp(
          "Speeds up the target.  If cast without a target, it will "
          "speed up the caster. This spell speeds up the heartbeat of the target.");
  }

varargs int eventCast(object who, int level, mixed b, object array targets){
  object target = targets[0];
  
     send_messages("concentrate",
        "Ethereal wings suddenly appear and wrap around "
        "$target_possessive_noun body only to fade moments later.",
         who, target, environment(who));
  target->AddCaffeine(level/4 );
  return 1;
}

int CanCast(object who, int level, mixed b, object *targets) {
        object target = targets[0];
   if (target->GetCaffeine() > target->GetStatLevel("durability") * 10) {
          who->eventPrint("That person cannot move any faster even with "
                      "your help.");
     return 0; 
     }
   return ::CanCast(who, level, b, targets);
}
