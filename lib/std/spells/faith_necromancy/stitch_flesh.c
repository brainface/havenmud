// mahkefel 2012
//  undead healing

#include <lib.h>
#include <magic.h>
#include <damage_types.h>

inherit LIB_SPELL;

static void create() {
  spell::create();
  SetSpell("stitch flesh");
  SetRules("", "LIV");
  SetAutoHeal(1);
  SetSpellType(SPELL_HEALING);
  SetSkills( ([
    "faith" : 75,
    "necromancy" : 75,
   ]) );
  SetDifficulty(25);
  SetMessages( ({

    ({ "continue",   "$target_name%^BOLD%^BLACK%^ $target_verb%^RESET^ to unravel." }),
    ({ "sew",  "$agent_name%^BOLD%^BLACK%^ $agent_verb%^RESET%^ the withered flesh covering $target_possessive_noun wounds." }),
    ({ "stitch", "$agent_name expertly%^BOLD%^BLACK%^ $agent_verb%^RESET%^ the flesh covering $target_name into a passable semblance of life." })
  }));

  SetHelp(
    "This spell magically stitches together open wounds of an undead target."
  );
}

int CanCast(object who, int level, mixed limb, object array targets) {
   if(!targets[0]->GetUndead()) {
        who->eventPrint("But that creature lives!");
        return 0;
   }
   return ::CanCast(who, level, limb, targets);
}

