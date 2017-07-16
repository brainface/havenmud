#include <lib.h>
#include <music.h>
inherit LIB_SONG;

static void create() {
  ::create();
  SetSong("holy light");
  SetReligions("Kylin");
  SetRules("OBJ", "OBJS");
  SetSongType(SONG_OTHER);
  SetMagicCost(10, 10);
  SetDifficulty(10);
  SetSkills( ([
    "faith" : 1,
    "vocal music" : 1,
    ]) );
  SetHelp("This song targets a given object, causing it to glow "
          "with the blessings of Duuktsaryth.  This CAN be used "
          "several times on the same target for greater light. "
          "Be warned that this has a negative effect on the item.");
  }

varargs int eventSing(object who, int level, mixed x, object *targets) {
  object target = targets[0];
  string tmp;

  send_messages( ({ "hum", "chant" }),
    "$agent_name $agent_verb and $agent_verb over $target_name, causing "
    "it to %^YELLOW%^glow%^RESET%^.",
    who, target, environment(who) );
  target->SetRadiantLight(target->GetRadiantLight() +
                          who->GetSongLevel("holy light")/10 + 1);
  if (sscanf(target->GetShort(), "%s (glowing)", tmp) == -1)
    target->SetShort(target->GetShort() + " (glowing)");
  target->eventReceiveDamage(who->GetSongLevel("holy light") * 10);
  return 1;
  }



