/* A song that cures thirst. */
#include <lib.h>
#include <music.h>
inherit LIB_SONG;

static void create() {
  ::create();
  SetSong("quenching");
  SetSongType(SONG_OTHER);
  SetDifficulty(10);
  SetRules("LIV","");
  SetSkills( ([
    "instrumental music" : 3,
  ]) );
  SetMagicCost(20, 20);
  SetHelp("This song fills the body with a wonderfully "
          "filling sense of peace and harmony which takes the "
          "place of needing water.");
  }


varargs int eventSing(object who, int level, mixed x, object *targets) {
  object target = targets[0];

  if (target->GetDrink() > 500) {
     who->eventPrint("That person is not thirsty!");
     return 1; 
  }
  send_messages( ({ "sing", "seem" }),
    "$agent_name $agent_verb a full and rich ballad, and "
    "$target_name $target_verb less thirsty.",
    who, target, environment(who) );
  target->AddDrink(5* (who->GetSongLevel("quenching")));
  return 1;
}
