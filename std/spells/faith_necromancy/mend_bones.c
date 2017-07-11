#include <lib.h>
#include <magic.h>
#include <damage_types.h>

inherit LIB_SPELL;

static void create()
{
  spell::create();
  SetSpell("mend bones");
  SetRules("", "LIV");
  SetAutoHeal(1);
  SetSpellType(SPELL_HEALING);
  SetSkills( ([
     "necromancy" : 20,
     "faith"   : 20,
  ]) );
  SetDifficulty(20);
  SetMorality(3);
  SetMessages(({
    ({ "are", "$target_name $target_verb still a %^BOLD%^BLACK%^rattly mess of bones%^RESET%^." }),
    ({ "are", "$target_possessive_noun joints %^BOLD%^BLACK%^creak%^RESET%^ "
       "a little bit less." }),
    ({ ({ "mend", "provide" }), "$agent_name $agent_verb the"
      " %^BOLD%^BLACK%^broken "
      "and chipped bones %^RESET%^of $target_name, restoring fluidity to "
      "$target_possessive joints." }) }));
  SetHelp(
     "This spell mends the bones of a reanimated dead, "
     "restoring their undead vitality.");
}

int CanCast(object who, int level, mixed limb, object array targets) {
   if(!targets[0]->GetUndead()) {
        who->eventPrint("But that creature lives!");
        return 0;
   }
   return ::CanCast(who, level, limb, targets);
}


