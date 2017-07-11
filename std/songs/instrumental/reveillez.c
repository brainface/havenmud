#include <lib.h>
#include <music.h>
inherit LIB_SONG;

static void create() {
  ::create();
  SetSong("reveillez");
  SetSkills( ([
     "instrumental music" : 40,
  ]) );
   SetAreaSong(1);
  SetRules("");
  SetMagicCost(20, 20);
  SetSongType(SONG_OTHER);
  SetDifficulty(25);
  SetHelp(
    "This fast paced song speeds up the heart beat of any who hear it. "
    "This song requires an audience to be properly enjoyed."
  );
}

varargs int eventSing(object who, int level, mixed b, object array targets) {
  int someone = 0;
  send_messages("play","$agent_name $agent_verb a rousing reveillez.",
	who, 0, environment(who));
  foreach(object target in (targets + ({ who }))) {
     if (target->GetCaffeine() < target->GetStatLevel("durability") * 15) { 
       if (target==who) {
         send_messages("perk",
         "$agent_name $agent_verb $agent_reflexive up.",
         who, 0, environment(who));
       }
       else {
         send_messages("perk",
         "$agent_name $agent_verb $target_name up.",
          who, target, environment(target));
       }
     target->AddCaffeine(level/4 );
     someone = 1;
     }
  }
  if(!someone) {
	  who->eventPrint("Everyone is too wired right now without your help.");
  }
  return 1;
}

// nonfunctional
/*
int CanSing(object who, int level, mixed limb, object *targets) {
  if (!sizeof(targets)) {
    who->eventPrint("A reveillez alone may as well be a lullaby! Find an audience!");
    return 0;
  }
  return song::CanSing(who, level, limb, targets);
}
*/



