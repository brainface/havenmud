// 
// The 'anti-magic field' spell
// Created a field in a room that disables all spellcasting
// Created by Zaxan@Haven
//

#include <lib.h>
#include <magic.h>
#include <damage_types.h>

inherit LIB_SPELL;

int DestroyShield(object env);

static void create() {
   spell::create();
   SetSpell("anti magic field");
   SetSpellType(SPELL_OTHER);
   SetRules("");
   SetSkills( ([
     "conjuring"   : 50,
     "enchantment" : 50,
   ]) );
   SetMagicCost(100,100);
   SetStaminaCost(10, 10);
   SetDifficulty(30);
   SetRecoveryTime(10 + random(10));
   SetMorality(0);
   SetHelp(
     "This spell creates a field around the caster that "
     "nullifies all magic in that room. The duration of the "
     "field is dependant upon the level of the caster's knowledge "
     "of the spell."
     );
}

int eventCast(object who, int level, mixed limb, object array targets) {
   object env = environment(who);
   int chance = level + random(who->GetSkillLevel("enchantment"));
   int dur = level * 5;
   chance += random(who->GetSkillLevel("conjuring"));

   if(chance < 40) {
      send_messages(({"stop","begin"}), "$agent_name $agent_verb "
                      "casting and $agent_verb to look confused.",
                       who,0, environment(who));
      return 1;
   } else {
      send_messages("create","$agent_name $agent_verb a large "
                    "%^MAGENTA%^purple%^RESET%^ shield "
                    "which promptly surrounds the area.",
                     who,0,environment(who));
      env->SetProperty("no magic",1);
      call_out((:DestroyShield:), dur, environment(who));
      return 1;
   }
}

int DestroyShield(object env) {
   if (!env) return 0;
   send_messages("","The %^MAGENTA%^purple%^RESET%^ shield "
                 "surrounding the area suddenly vanishes.",
                 env, 0);
   env->RemoveProperty("no magic");
   return 1;
}
