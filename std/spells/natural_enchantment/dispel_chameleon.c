// Artanis@Haven (July 4, 2004)

#include <lib.h>
#include <magic.h>

inherit LIB_SPELL;

static void create() {
   spell::create();
   SetSpell("dispel chameleon");
   SetSpellType(SPELL_OTHER);
   SetMagicCost(25,25);
   SetRules("");
   SetSkills( ([ 
     "natural magic" : 35,
     "enchantment" : 35,
   ]) );
   SetDifficulty(22);
   SetMorality(0);
  SetHelp(
     "This spell allows the currently disguised player to shed their "
     "chameleon skin at any time of their choosing. "
  );
}

int CanCast(object who, int level, string limb, object *targets) {
   if (!who->GetInvis()) {
      message("my_action", "You aren't wearing a chameleon skin!", who);
      return 0;
   }
   return spell::CanCast(who, level, limb, targets);
}

int eventCast(object who, int level, mixed limb, object *targets) {
   who->SetInvis(0);
   send_messages("emerge", "$agent_name $agent_verb out of "
                            "the environment.",who,0,environment(who));
   return 1;
}
