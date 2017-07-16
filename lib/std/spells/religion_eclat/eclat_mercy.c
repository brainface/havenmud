//Davantalus@Haven
//20040903

#include <lib.h>
#include <magic.h>

inherit LIB_SPELL;

static void create() 
{
  spell::create();
  SetSpell("eclat mercy");
  SetReligions("Eclat");  
  SetRecoveryTime(60);
  SetRules("LIV");
  SetSpellType(SPELL_OTHER);
  SetSkills( ([ 
    "healing"       : 300,
    "natural magic" : 300,
  ]) );
  SetMagicCost(350, 350);
  SetDifficulty(75);
  SetStaminaCost(300, 300);
  SetHelp(
    "Calling on the forces of their god and nature, the caster "
    "of this spell can attempt to restore life to the target.  "
    "This spell is powerful and takes a great toll on the caster.");
}

int CanCast(object who, int level, mixed limb, object array targets) {
   foreach(object target in targets) {
      if ( (target == who) && !target->GetUndead()) {
          message("system", "But you are not undead!",who);
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
  foreach(object target in targets) 
  {
    send_messages( ({ "call" }),"$agent_name $agent_verb "
      "out to the heavens in prayer.  The ground trembles "
      "as a shaft of brilliant %^BOLD%^BLUE%^blue%^RESET%^ "
      "light envelopes $target_name, restoring $target_objective to life!",
      who,target,environment(who));
    
    who->AddHealthPoints( -(who->GetHealthPoints() - 10) );
    who->AddMagicPoints( -who->GetMagicPoints() );
    who->AddStaminaPoints( -who->GetStaminaPoints() );
    target->SetUndead(0);
   }
   return 1;
}
