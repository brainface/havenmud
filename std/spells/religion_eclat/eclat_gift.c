// Yoinked from resurrection
// Davantalus@Haven
// 20040903

#include <lib.h>
#include <magic.h>

inherit LIB_SPELL;

static void create() {
   spell::create();
   SetSpell("eclat gift");
  SetReligions("Eclat");   
  SetRecoveryTime(20);
   SetRules("LIV");
   SetSpellType(SPELL_OTHER);
   SetSkills( ([ 
      "healing" : 75,
      "natural magic"   : 75,
   ]) );
   SetMagicCost(250,250);
   SetDifficulty(60);
   SetStaminaCost(250,250);
   SetHelp(
           "Calling upon the forces of the heavens "
           "and the power of nature, the caster of "
           "this spell attempts to restore life to "
           "the undead.");
}

int CanCast(object who, int level, mixed limb, object array targets) {
   foreach(object target in targets) {
      if( (target == who) && !target->GetUndead()) {
         message("system","But you are not dead!",who);
         return 0;
      }
      else if(!target->GetUndead()) {
         message("system","But "+target->GetName()+" is not "
                 "undead!.",who);
         return 0;
      }
   }
   return spell::CanCast(who, level, limb, targets);
}

int eventCast(object who, int level, string limb, object array targets) {
   foreach(object target in targets) {
      send_messages( ({ "raise" }),"$agent_name $agent_verb "
                        "$agent_possessive hands towards the heavens, "
                        "calling upon nature to restore $target_possessive_noun life!",
                         who,target,environment(who));
      target->eventRevive();
   }
   return 1;
}
