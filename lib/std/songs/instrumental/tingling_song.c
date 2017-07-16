/*  Tingling song, which is sort of a soothe song */
#include <lib.h>
#include <music.h>
inherit LIB_SONG;

static void create() {
  ::create();
  SetSong("tingling song");
  SetRules("", "LIV");
  SetSongType(SONG_OTHER);
  SetSkills( ([
    "instrumental music" : 1,
    ]) );
  SetMagicCost(20, 30);
  SetMagicCost(20, 30);
  SetDifficulty(15);
  SetHelp("This song attempts to soothe the savage beasts "
          "of Kailie.  It can only be used on an animal, "
          "and its effectiveness depends on how well one "
          "knows the song.");
 }



varargs int eventSing(object who, int level, mixed x, object *targets) {
  if (!sizeof(targets)) {
  	who->eventPrint("There are no animals present to hear your song.");
  	return 1;
  	}
  foreach(object target in targets) {
      if (level > target->GetLevel()) {
        target->eventCollapse();
        target->SetSleeping(level - (target->GetLevel()));
        send_messages("put",
      "$agent_name $agent_verb $target_name into a deep %^GREEN%^sleep%^RESET%^.",
        who, target, environment(who) );
      }
  if (level <= (target->GetLevel())) {
   who->eventPrint(target->GetName() + " ignores your song.");
         }
    }
    return 1;
  }

object *GetTargets(object who, mixed args...) {
  object *ret = all_inventory(environment(who));
  ret = filter(ret, (: $1->GetClass() == "animal" :) );
  return ret;
 }
