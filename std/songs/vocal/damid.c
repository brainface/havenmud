#include <lib.h>
#include <music.h>

inherit LIB_SONG;

static void create() {
   song::create();
   SetSong("dispel aria of midnight");
   SetSongType(SONG_OTHER);
   SetMagicCost(25,25);
   SetRules("");
   SetSkills( ([ 
     "vocal music" : 50,
   ]) );
   SetDifficulty(20);
   SetMorality(0);
  SetHelp(
           "This song allows for a bard to dispel the effects "
           "of the aria of midnight song and become visible once "
           "again.");
}

int CanSing(object who, int level, string limb, object *targets) {
   if (!who->GetInvis()) {
      message("my_action","You aren't invisible!",who);
      return 0;
   }
   return song::CanSing(who, level, limb, targets);
}

int eventSing(object who, int level, mixed limb, object *targets) {
   who->SetInvis(0);
   send_messages("step", "$agent_name $agent_verb out of "
                 "the darkness.",who,0,environment(who));
   return 1;
}

