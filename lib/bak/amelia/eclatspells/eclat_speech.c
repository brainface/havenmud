#include <lib.h>
#include <magic.h>
inherit LIB_SPELL;

void RemoveChannelEclat(object targ,string channel);

static void create() {
   spell::create();
   SetSpell("eclat speech");
   SetGlobalSpell(1);
   SetSpellType(SPELL_OTHER);
   SetRules("LIV","STR");
   SetMagicCost(20,10);
   SetRequiredMagic(30);
   SetSkills( ([
                 "natural magic"      : 17,
                 "enchantment" : 17,
            ]) );
   SetDifficulty(30);
   SetHelp("Syntax:  <cast eclat speech on LIVING>\n\n"
           "This spells grants a channel of communication between "
           "the target and the caster.  Any creatures given this "
           "means of communication are able to converse "
           "with each other from any distance and in any "
           "language, but the words will be clear and translated.");
}

int eventCast(object who, int level, mixed useless, object *targets) {
   object targ = targets[0];
   int poss = 0;
   if(member_array((who->GetKeyName()+targ->GetKeyName()),targ->GetChannels()) != -1) {
      message("spell","But that person is already communicating with you!",who);
   return 0;
   }
   poss += level/2;
   poss += (who->GetStatLevel("wisdom"));
   if(poss > (random(30) + 20)) {
      who->AddChannel( ({ (who->GetKeyName()+targ->GetKeyName()) }) );
      targ->AddChannel( ({ (who->GetKeyName()+targ->GetKeyName()) }) );
      call_out( (: RemoveChannelEclat, targ,(who->GetKeyName()+
                   targ->GetKeyName()) :),poss*10);
      call_out( (: RemoveChannelEclat, who,(who->GetKeyName()+
                   targ->GetKeyName()) :),poss*10);
      if(who == targ) {
         send_messages( ({ "open" }),"$agent_name $agent_verb a "
                           "channel of communication called " +
                           who->GetKeyName()+targ->GetKeyName() + " for "
                           "$agent_reflexive.",who,0,environment(who));
         return 1;
      } 
      send_messages( ({ "open" }),"$agent_name $agent_verb a channel "
                       "of communication between $agent_reflexive and "
                       "$target_name.",who,targ,
                       environment(who));
      send_messages("","Your new channel is called " + who->GetKeyName()+
              targ->GetKeyName() + ".  Use it just like the ooc channel.",
              who,targ,0);
      return 1;
   }
   message("spell","You fail to open the channel of communication.",
           who);
   return 0;
}

void RemoveChannelEclat(object targ, string channel) {
   if(!targ) return;
   if(!channel) return;
   targ->RemoveChannel( ({ channel }) );
   message("spell","You loose knowledge of the " + channel + " channel.",targ);
   return;
}
