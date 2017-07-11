#include <music.h>
#include <lib.h>
inherit LIB_SONG;

static void create() {
  ::create();
  SetSong("famine");
  SetRules("LIV","");
  SetSongType(SONG_COMBAT);
  SetMagicCost(50, 50);
  SetMorality(-2);
  SetMagicCost(20, 30);
  SetDifficulty(40);
  SetSkills( ([
    "instrumental music" : 20,
    "vocal music"        : 20,
    ]) );
  SetHelp("This song causes a given target to feel pangs of hunger. "
          "This hunger is of a normal variety and not immediately "
          "life threatening.");
  }

varargs int eventSing(object who, int level, mixed x, object *targets) {
  object target = targets[0];

  send_messages( ({ "sing", "look" }),
    "$agent_name%^RED%^ $agent_verb%^RESET%^ a viscious melody, causing "
    "$target_name to feel a pang of hunger.",
    who, target, environment(target) );
  target->AddFood(-5 * who->GetSongLevel("famine") );
  return 1;
}


