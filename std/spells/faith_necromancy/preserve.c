// mahkefel 2012
//  undead healing

#include <lib.h>
#include <magic.h>
#include <damage_types.h>

inherit LIB_SPELL;

static void create() {
  spell::create();
  SetSpell("preserve");
  SetRules("", "LIV");
  SetAutoHeal(1);
  SetSpellType(SPELL_HEALING);
  SetSkills( ([
    "faith" : 1,
    "necromancy" : 1,
   ]) );
  SetDifficulty(25);
  SetMessages( ({

    ({ ({"fumble","cause"}), "$target_name%^BOLD%^BLACK%^ $target_verb%^RESET^ $agent_possessive channeling of dark energy and "
       "$agent_verb $target_name to stink even more." }),
    ({ "obscure",  "$agent_name%^BOLD%^BLACK%^ $agent_verb%^RESET%^ some of the more grevious wounds on $target_name." }),
    ({ ({"channel"}), "$agent_name carefully%^BOLD%^BLACK%^ $agent_verb%^RESET%^ necrotic energy at the wounds of "
       "$target_name, making $target_objective look almost natural." })
  }));

  SetHelp(
    "This spell treats some minor wounds on a reanimated corpse, making them look a little less rotten."
  );
}

int CanCast(object who, int level, mixed limb, object array targets) {
   if(!targets[0]->GetUndead()) {
        who->eventPrint("But that creature lives!");
        return 0;
   }
   return ::CanCast(who, level, limb, targets);
}

