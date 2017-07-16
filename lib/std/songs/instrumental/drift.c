#include <lib.h>
#include <music.h>
inherit LIB_SONG;

static void create() {
  ::create();
  SetSong("drift");
  SetSongType(SONG_COMBAT);
  SetRules("", "LIV");
  SetSkills( ([
    "instrumental music" : 20,
    ]) );
  SetDifficulty(35);
 SetMagicCost(50, 50);
  SetHelp("This song, an instrumental piece, is a quiet and peaceful "
          "song meant to make sentient creatures sleepy.  Its effective"
          "ness is based on the abilities of the bard.  Note that this "
          "is a normal sleep, and NOT a magical sleep.");
  }

varargs int eventSing(object who, int level, mixed x, object *targets) {
  object target = targets[0];

  if(level/3 + random(who->GetSkillLevel("instrumental music")) 
      - target->GetLevel() - random(target->GetStatLevel("wisdom"))>0) {
    send_messages( ({ "play" }),
      "$agent_name $agent_verb a %^BLUE%^soft lullaby%^RESET%^, "
      "which causes $target_name to drift into a light sleep.",
      who, target, environment(target) );
  target->eventCollapse();
    target->SetSleeping(random(5) + 2);
    return 1;
    }
  send_messages( ({ "play" }),
    "$agent_name $agent_verb a %^BLUE%^soft lullaby%^RESET%^, "
    "which $target_name ignores without a qualm.",
    who, target, environment(target) );
  return 1;
}

