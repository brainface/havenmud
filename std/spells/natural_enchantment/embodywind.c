// haste for druids
// Thoin@haven
#include <lib.h>
#include <magic.h>
inherit LIB_SPELL;

static void create() {
  spell::create();
  SetSpell("embodiment of wind");
  SetSkills( ([
     "natural magic" : 50,
     "enchantment" : 50,
  ]) );
  SetRules("", "LIV");
  SetMagicCost(30, 30);
  SetSpellType(SPELL_OTHER);
  SetDifficulty(55);
  SetHelp(
          "This allows a natural magic user to become one with the wind and air "
          "greatly increasing their targets speed.");
  }

varargs int eventCast(object who, int level, mixed b, object array targets){
  object target = targets[0];
  
     send_messages("concentrate",
        "A gust of wind wraps around "
        "$target_possessive_noun body slightly blurring $target_possessive movements for a moment.",
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

