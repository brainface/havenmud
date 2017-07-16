// Amelia@Haven, 2005
#include <lib.h>
#include <music.h>
inherit LIB_SONG;

static void create() {
   song::create();
   SetSong("song of the dance");
   SetRules("","LIV");
   SetMagicCost(50,5);
   SetSongType(SONG_COMBAT);
   SetSkills( ([
                 "vocal music" : 75,
            ]) );
   SetDifficulty(55);
   SetHelp("The song of the dance causes the target to dance uncontrollably, "
	"tiring them out.");
}

varargs int eventSing(object who, int level, mixed limb, object *targets) {
   object targ = targets[0];
  level = (level/2) + random(level/2) + who->GetSkillLevel("vocal music");
   level -= 2*targ->GetLevel();
   if(level > 125) level = 125;
   if(level < -125) level = -125;
   if(level < 1) {
      if(!random(10)) {
         send_messages(({"sing","begin"}),"$agent_name $agent_verb the "
                       "song of the dance to $target_name, "
                       "but $agent_verb to dance $agent_reflexive!",
                       who, targ, environment(who));
	 who->AddStaminaPoints(level);
         return 1;
      }
      send_messages("sing","$agent_name $agent_verb powerfully, but "
                    "$agent_possessive song of the dance doesn't even "
		    "cause $target_name to twitch.",who,targ,
                    environment(who));
      return 1;
   }
   send_messages("sing","$agent_name $agent_verb the song "
                 "of the dance expressively, causing $target_name to "
		"break into dance.",
                 who,targ,environment(who));
   targ->AddStaminaPoints(-level);
   return 1;
}
