#include <lib.h>
#include <music.h>
#include <damage_types.h>

inherit LIB_SONG;

int DestroyShield(object env);

static void create() {
   song::create();
   SetSong("drowning music");
   SetSongType(SONG_OTHER);
   SetRules("");
   SetSkills( ([
     "instrumental music" : 65
   ]) );
   SetMagicCost(100,160);
   SetStaminaCost(10, 10);
   SetDifficulty(30);
   SetMorality(0);
   SetHelp(
           "This song allows the singer to flood the area around him "
           "with a song so loud and brain racking that it prevents "
           "concentration and makes it impossible to cast spells.");
}

int eventSing(object who, int level, mixed limb, object array targets) {
   object env = environment(who);
   int chance = level + random(who->GetSkillLevel("instrumental music"));
   int dur = level * 5;
   chance += random(who->GetSkillLevel("instrumental music"));

   if(chance < 40) {
      send_messages(({"choke","cough"}), "$agent_name starts "
                      "singing and $agent_verb violently.",
                       who,0, environment(who));
      return 1;
   } else {
      send_messages("flood","$agent_name $agent_verb the area with "
                    "a drowning song that is difficult "
                    "to concentrate around.",
                     who,0,environment(who));
      env->SetProperty("no magic",1);
      call_out((:DestroyShield:), dur, environment(who));
      return 1;

   }
}

int DestroyShield(object env) {
/*
   object array people;
   if (!env) return; 
   people = filter(all_inventory(environ), (: playerp :));
  if (!sizeof(people)) return;
*/
   send_messages("","The song filling the area suddenly disapates.",
                 env, 0);
   env->RemoveProperty("no magic");
   return 1;
}
