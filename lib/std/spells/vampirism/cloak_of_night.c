// Cloak of Night
// like invis, but with an insufferable name
// for vapmires!
//

#include <lib.h>
#include <magic.h>

inherit LIB_SPELL;

void eventUnInvis();

static void create() {
   spell::create();
   SetSpell("cloak of night");
   SetSpellType(SPELL_OTHER);
   SetStaminaCost(50, 25);
   SetRequiredStamina(75);
   SetRules("");
   SetSkills( ([ 
     "vampirism" : 30,
     "stealth" : 30,
   ]) );
   SetDifficulty(20);
   SetMorality(0);
   SetHelp(
     "A vampire that survives its first few nights quickly learns "
     "the value of stealth, and can even pull the shadows around "
     "themselves to hide from mortal sight."
	   );
}

int CanCast(object who, int level, string limb, object *targets) {
   if (who->GetInvis() == 1) {
      message("my_action","You are already invisible!",who);
      return 0;
   }
   return spell::CanCast(who, level, limb, targets);
}

int eventCast(object who, int level, mixed limb, object *targets) {
   int chance;
   chance = level + random((int)who->GetSkillLevel("stealth"));

   if(chance < 20) {
      send_messages("disappear", "$agent_name $agent_verb into "
                    "the shadows.",who,0,0);
      return 1;
   }
   if( (chance >= 20) &&
       (chance <  50) ) {
      send_messages("disappear", "$agent_name $agent_verb into "
                    "the shadows.",who,0,environment(who));
      who->SetInvis(1);
      call_out( (: eventUnInvis() :), 100);
      return 1;
   }
   if( (chance >= 50) &&
       (chance <  80) ) {
      send_messages("disappear", "$agent_name $agent_verb into "
                    "the shadows.",who,0,environment(who));
      who->SetInvis(1);
      call_out( (: eventUnInvis() :), 200);
      return 1;
   }
   if (chance >= 80) {
      send_messages("disappear", "$agent_name $agent_verb into "
                    "the shadows.",who,0,environment(who));
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
      send_messages("step", "$agent_name $agent_verb out of "
                    "the shadows.",who,0,environment(who));
   }
}
