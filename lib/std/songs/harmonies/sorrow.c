/*  A mid level song */
// Targeting code commented out, SetAreaSong(1)
// Laoise, August, 2004
#include <lib.h>
#include <music.h>
inherit LIB_SONG;

static void create() {
  ::create();
  SetSong("song of sorrow");
  SetRules("");
  SetSkills( ([
     "instrumental music" : 10,
     "vocal music" : 10,
     ]) );
  SetDifficulty(20);
  SetMagicCost(50, 50);
  SetMagicCost(50, 50);
  SetHelp("This painful song is such a heart rending tragedy "
          "that it oftens distracts attackers, preventing them "
          "from causing harm to the bard for a moment. "
          "Note that this song is cast on ALL of those in the area who "
          "are hostile to the bard. Also note that the pain of this song may "
          "cause previously passive individuals in the area to attack the "
          "singer."
  );
  SetSongType(SONG_COMBAT);
  SetAreaSong(1);
  }

/*
object *GetTargets(object who, mixed args...) {
  object *ret = all_inventory(environment(who));
  ret = filter(ret, (: $1->GetClass() == "animal" :) );
  return ret;
 }
*/

varargs int eventSing(object who, int level, mixed n, object *targets) {
  foreach(object target in targets) {
    if (!target) continue;
    if (target->GetMagicResistance() >= level) {
      who->eventPrint(target->GetName() + " ignores your song.");
       }
  if (target->GetMagicResistance() < level) {
     send_messages( ({ "get", "forget" }),
       "$target_name $target_verb a forlorn look on " +
       "$target_possessive face, and $target_verb to attack.",
       who, target, environment(who) );
     target->SetParalyzed(who->GetLevel() / 5);
     }
  }
  return 1;
 }
