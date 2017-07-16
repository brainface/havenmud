#include <lib.h>
#include <magic.h>
#include <magic_protection.h>
#include <message_class.h>
inherit LIB_SPELL;

int RoomStart(object who);
int RoomEnd(object env, mapping daprops);

void create() {
   ::create();
   SetAreaSpell(1);
   SetAutoHeal(1);
   SetHealing(50,25);
   SetSpell("cloud of happiness");
   SetRules("");
   SetSkills( ([
                 "faith"       : 19,
                 "enchantment" : 17,
                 "healing"     : 17,
            ]) );
   SetDifficulty(55);
   SetRequiredMagic(50);
   SetRequiredStamina(20);
   SetMagicCost(40,10);
   SetStaminaCost(15,5);
   SetSpellType(SPELL_HEALING);
   SetMessages( ({
                   ({ ({ "appear","be" }), "$target_name $target_verb "
                         "to be uneffected by the cloud, even though "
                         "$target_name $target_verb smiling." }),
                   ({ ({ "smile" }), "$target_name $target_verb with "
                         "great happiness as the cloud touches "
                         "the area." }),
                   ({ ({ "grin" }), "$target_name $target_verb broadly "
                         "as the cloud of happiness floats in." }),
              }) );
   SetHelp("Syntax:  <cast cloud of happiness>\n\n"
           "The area around the caster is shrouded in a cloud of "
           "happiness called down from Amelia, the Goddess of Joy.  "
           "It creates peace in the area and heals the living "
           "creatures present.");
}

object *GetTargets(object who, mixed args...) {
   object *targets = filter(all_inventory(environment(who)), (: living :));
   return targets - ({ who });
}

varargs int eventCast(object who, int level, string limb, object *targets) {
   call_out((:RoomStart, who:),random(3)+2);
   send_messages( ({""}), "A mist begins to form in the area.",
                 ({ targets, environment(who) }));
   return spell::eventCast(who, level, limb, targets);
}

int RoomStart(object who) {
   int dalength;
   mapping daprops = ([ ]);
   object env = environment(who);
   if( !(env->GetProperty("sanctified")) ) {
      dalength = ( (random(5) + who->GetSkillLevel("faith") + 
                    who->GetSkillLevel("enchantment") ) / (2 + 1/2) );
      send_messages( ({ "ignite" }), "%^BOLD%^%^BLUE%^$agent_name "
                        "$agent_verb the powers of $agent_possessive "
                        "Goddess, causing the cloud of happiness to "
                        "end the aggression of the area.",who,0,
                        env);
      send_messages( ({ "" }),"You feel a little healthier.",
                      who,0,env);
      if(env->GetProperty("no attack")) daprops[0] = 1;
      if(env->GetProperty("no bump")) daprops[1] = 1;
      if(env->GetProperty("no steal")) daprops[2] = 1;
      if(env->GetProperty("no magic")) daprops[3] = 1;
      if(env->GetProperty("no teleport")) daprops[4] = 1;
      env->SetProperty("no attack",1);
      env->SetProperty("no bump",1);
      env->SetProperty("no steal",1);
      env->SetProperty("no magic",1);
      env->SetProperty("no teleport",1);
      env->SetProperty("sanctified",1);
      call_out( (: RoomEnd :), dalength, env, daprops);
      return 1;
   }
   else {
      send_messages( ({""}),"The aggression has already been ended in this "
                    "area.",who,0,who);
      return 0;
   }
}

int RoomEnd(object env, mapping daprops) {
   send_messages( ({""}), "%^RED%^The cloud of happiness fades out.%^RESET%^", env, 0);
   if (!daprops[0])
      env->SetProperty("no attack",0);
   if (!daprops[1])
      env->SetProperty("no bump",0);
   if (!daprops[2])
      env->SetProperty("no steal",0);
   if (!daprops[3])
      env->SetProperty("no magic",0);
   if (!daprops[4])
      env->SetProperty("no teleport",0);
   env->SetProperty("sanctified",0);
   return 1;
}