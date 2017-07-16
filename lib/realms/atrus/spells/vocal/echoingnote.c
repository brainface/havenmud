#include <lib.h>
#include <music.h>
inherit LIB_SONG;

static void create() {
  song::create();
  SetSong("echoing note");
  SetDifficulty(50);
  SetRules("LIV", "STR");
  SetGlobalSong(1);
  SetMagicCost(50, 50);
  SetSongType(SONG_OTHER);
  SetSkills( ([
     "vocal music" : 45,
     ]) );
  SetHelp(
          "Using sound as a detection and ranging tool you can "
          "retrieve and echo from throughout the world of the "
          "location of a person.");
  }


int CanSing(object who, int level, mixed limb, object *targets) {
  if (creatorp(targets[0])) {
      message("system", "Echo who?", who);
      return 0;
     }
  return song::CanSing(who, level, limb, targets);
}

varargs int eventSing(object who, int level, mixed n, object *t) {
  object target = t[0];
  message("scry", "%^BLUE%^BOLD%^Using your honed hearing you "
          "detect :%^RESET%^", who);
  message("scry",
  environment(who)->GetRemoteDescription(base_name
             (environment(target)), 1), who);
  return 1;
}

