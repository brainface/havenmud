#include <lib.h>
#include <music.h>
inherit LIB_SONG;

static void create() {
  ::create();
  SetSong("magical lullaby");
  SetSongType(SONG_OTHER);
  SetDifficulty(50);
  SetRules("LIV");
  SetSkills( ([
    "instrumental music" : 40,
    "vocal music"        : 40,
    ]) );
  SetHelp("This song is a more powerful version of the drift song. "
          "However, this song IS magical sleep.  The effectiveness "
          "of this song is dependant on the skills of the bard.");
  SetMagicCost(75, 75);
  }

varargs int eventSing(object who, int level, mixed x, object *targets) {
  object target = targets[0];

  if (random(target->GetStatLevel("wisdom")) + target->GetStatLevel("wisdom") >
      (level/2 + who->GetSkillLevel("vocal music")/10 + who->GetSkillLevel("instrumental music")/10 ) ) {
      send_messages( ({ "perform", "sluff" }),
        "$agent_name $agent_verb a soft lullaby which $target_nominative "
        "$target_verb off with %^RED%^no effect%^RESET%^.",
        who, target, environment(who) );
      return 1;
      }
    send_messages( ({ "perform" }),
      "$agent_name $agent_verb a %^BLUE%^BOLD%^soft lullaby%^RESET%^ "
      "which causes $target_name to become sleepy.",
      who, target, environment(who) );
  target->eventCollapse();
    target->SetSleeping(10);
    target->SetParalyzed(10);
    return 1;
  }


