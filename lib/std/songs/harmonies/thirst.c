#include <music.h>
#include <lib.h>
inherit LIB_SONG;

static void create() {
  ::create();
  SetSong("thirst");
  SetRules("LIV","");
  SetSongType(SONG_COMBAT);
  SetMagicCost(40, 40);
  SetMagicCost(10, 10);
  SetMorality(-1);
  SetDifficulty(30);
  SetSkills( ([
    "instrumental music" : 15,
    "vocal music"        : 15,
    ]) );
  SetHelp("This song causes a given target to feel more thirsty. "
          "This thirst is of a normal variety and not immediately "
          "life threatening.");
  }

varargs int eventSing(object who, int level, mixed x, object *targets) {
  object target = targets[0];

  send_messages( ({ "sing", "look" }),
    "$agent_name%^RED%^ $agent_verb%^RESET%^ a viscious melody, causing "
    "$target_name to feel thirsty.",
    who, target, environment(target) );
  target->AddDrink(-5 * who->GetSongLevel("thirst") );
  return 1;
}


