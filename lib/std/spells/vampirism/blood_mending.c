// mahkefel 2021
//  vampire self-heal

#include <lib.h>
#include <magic.h>
#include <damage_types.h>

inherit LIB_SPELL;

static void create() {
  spell::create();
  SetSpell("blood mending");
  SetRules("");
  SetAutoHeal(1);
  SetSpellType(SPELL_HEALING);
  SetSkills( ([
    "vampirism" : 1,
  ]) );
  SetDrinkCost(50,50);
  SetMagicCost(0,0);
  //SetStaminaCost(100,50);
  SetDifficulty(25);
  SetMessages( ({
    ({ ({"scrunch", "puke"}), "$agent_name $agent_verb up $agent_objective face, then suddenly%^RED%^ $agent_verb a little blood%^RESET%^."}),
    ({ ({"concentrate","appear"}), "$agent_name $agent_verb for a brief moment and $agent_verb slightly more %^GREEN%^life-like%^RESET%^."}),
    ({ "flush", "$agent_possessive_noun body%^BOLD%^RED%^ flushes red with blood%^RESET%^ as $agent_objective wounds close."}),
  }));

  SetHelp(
    "Even a fledgling vampire can draw upon their stolen blood to heal the wounds their undead body has incurred. "
    "Doing so can cause great thirst, however.\n"
    "This spell scales with level."
  );
}

int CanCast(object who, int level, mixed limb, object array targets) {
   if(targets[0]->GetUndeadType() != "vampire") {
        who->eventPrint("You are not a vampire!");
        return 0;
   }
   return ::CanCast(who, level, limb, targets);
}

