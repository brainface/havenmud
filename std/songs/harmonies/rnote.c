#include <lib.h>
#include <daemons.h>
#include <music.h>
#include <damage_types.h>

inherit LIB_SONG;

static void create() {
  song::create();
  SetSong("reverberating note");
  SetRules("");
  SetProtectionTypes(ALL_DAMAGE);
  SetShieldType(SHIELD_TIMED);
  SetSongType(SONG_DEFENSE);
  SetSkills( ([
     "vocal music"       : 350,
     "instrumental music" : 350,
     ]) );
  SetMagicCost(150, 150);
  SetDifficulty(200);
  SetMorality(0);
  SetHelp(
            "The bard creates a reverberating note which continiously echos forming "
             "a powerful barrier of sound and air around the bard. This is the "
            "most powerful protective song a bard can learn and use."
  );
  SetMessages( ({ 
        ({ "sing", "$agent_name $agent_verb an off-key note that begins to reverberate "
       "forming into a %^GREEN%^wispy shield%^RESET%^ that surrounds "
       "$agent_objective." }),
    ({ "strike", "The %^BOLD%^%^CYAN%^wispy shield%^RESET%^ around $agent_name shimmers slightly as "
       "$target_name $target_verb it!" }),
    ({ "", "The %^BOLD%^%^RED%^wispy shield%^RESET%^ around $agent_name disperses into the air." }),
    }) );
}

int CanSing(object who, int level, mixed blah, object *targets){
    object target = targets[0];    
    string *pros = ({ });

  if(who->GetSongLevel("sonic barrier") < 99) { 
        message("system","You have not mastered the sonic barrier song. ",who);
      return 0;
      }
    foreach (class MagicProtection pro in target->GetMagicProtection()){
     pros += ({ pro->name });
   }

    if (sizeof(filter(pros, (: $1 == "reverberating note" :) ) ) > 1){
        message("", "You cannot stack any more of these."
        , who);
        return 0;
    }
  
    return song::CanSing(who, level, blah, targets);
}

