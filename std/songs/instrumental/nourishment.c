/* A song that cures hunger. */
#include <lib.h>
#include <music.h>
inherit LIB_SONG;

static void create() {
  ::create();
  SetSong("nourishment");
  SetSongType(SONG_OTHER);
  SetDifficulty(15);
  SetRules("LIV","");
  SetSkills( ([
    "instrumental music" : 10,
  ]) );
  SetMagicCost(25, 25);
  SetHelp("This song fills the body with a wonderfully "
          "filling sense of peace and harmony which takes the "
          "place of needing food.");
  }


varargs int eventSing(object who, int level, mixed x, object *targets) {
  object target = targets[0];

  if (target->GetFood() > 500) {
     who->eventPrint("That person is already full!");
     return 1; 
  }
  send_messages( ({ "sing", "seem" }),
    "$agent_name $agent_verb a full and rich ballad, and "
    "$target_nominative $target_verb less hungry.",
    who, target, environment(who) );
  target->AddFood(5* (who->GetSongLevel("nourishment")));
  return 1;
}
