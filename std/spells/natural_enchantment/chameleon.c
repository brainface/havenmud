/* renny boy : for druids : copy of invisibility by Zaxan@Haven */
#include <lib.h>
#include <magic.h>
inherit LIB_SPELL;
   void eventUnInvis();
   static void create() {
     spell::create();
     SetSpell("chameleon");
     SetSpellType(SPELL_OTHER);
     SetRequiredMagic(90);
     SetMagicCost(70, 20);
     SetRequiredStamina(90);
     SetMagicCost(70, 20);
     SetRules("");
     SetSkills( ([ 
       "natural magic" : 35,
       "enchantment"   : 35,
     ]) );
     SetDifficulty(20);
  SetHelp(
       "This spell causes the caster's skin and inventory "
       "to act like a chameleon and blend in with the "
       "surrounding environment.");
   }

   int CanCast(object who, int level, string limb, object *targets) {
     if (who->GetInvis() == 1) {
       message("my_action","You already have chameleon skin!",who);
       return 0;
     }
   return spell::CanCast(who, level, limb, targets);
   }

   int eventCast(object who, int level, mixed limb, object *targets) {
     int chance;
     chance = level + random((int)who->GetSkillLevel("natural magic"));

   if(chance < 20) {
     send_messages("blend", "$agent_name $agent_verb into "
                   "the environment.",who,0,0);
       call_out( (: eventUnInvis() :), 100);
     return 1;
     }
   if( (chance >= 20) &&
       (chance <  50) ) {
       send_messages("blend", "$agent_name $agent_verb into "
                     "the environment.",who,0,environment(who));
       who->SetInvis(1);
       call_out( (: eventUnInvis() :), 100);
       return 1;
     }
   if( (chance >= 50) &&
       (chance <  80) ) {
      send_messages("blend", "$agent_name $agent_verb into "
                   "the environment.",who,0,environment(who));
      who->SetInvis(1);
      call_out( (: eventUnInvis() :), 200);
      return 1;
   }
   if (chance >= 80) {
      send_messages("blend", "$agent_name $agent_verb into "
                   "the environment.",who,0,environment(who));
      who->SetInvis(1);
      call_out( (: eventUnInvis() :), 300);
      return 1;
   }
}

void eventUnInvis() {
   object who;
   who = this_player();

   if( (who) &&
       (who->GetInvis()) ) {
      who->SetInvis(0);
      send_messages("emerge", "$agent_name $agent_verb out of "
                    "the environment.",who,0,environment(who));
   }
}
