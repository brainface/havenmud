#include <lib.h>
#include <music.h>
inherit LIB_SONG;

static void create() {
  ::create();
  SetSong("mesmerize audience");
  SetSongType(SONG_OTHER);
  SetSkills( ([
    "vocal music"        : 50,
    "instrumental music" : 50,
    ]) );
  SetMagicCost(75, 100);
  SetDifficulty(20);
  SetRules("");
  SetAreaSong(1);
  SetHelp(
    "Singing this song is making an attempt to enrapture an entire "
    "crowd of people.  If successful, the listeners could be lulled "
    "for a period of time."
    );
}

object *GetTargets(object who, mixed args...) {
  object *t = all_inventory(environment(who));
  t = filter(t, (: living :) );
  t -= ({ who });
  return t;
}

int eventSing(object who, int level, mixed q, object *targets) {
  int Effectiveness;
  int tmp;

  Effectiveness = (who->GetSkillLevel("vocal music") + 
                   who->GetSkillLevel("instrumental music"));
  Effectiveness += who->GetStatLevel("charisma");
  Effectiveness = (Effectiveness * level) / 100;

  foreach(object t in targets) {
    tmp = t->GetMagicResistance() + t->GetStatLevel("charisma") + t->GetLevel();
    tmp = Effectiveness - tmp;
    
    if (tmp >= 10) {
      send_messages( ({ "are" }),
         "%^GREEN%^The beauty of $agent_possessive_noun song overwhelms $target_name!%^RESET%^",
         who, t, environment(t));
      t->SetParalyzed(10);
      continue;
    }
    if (tmp > 0) {
      send_messages( ({ }),
        "%^BLUE%^The beauty of $agent_possessive_noun song causes $target_name to pause.%^RESET%^",
        who, t, environment(t) );
      t->SetParalyzed(tmp);
      continue;
    }
    send_messages( ({ "fail" }),
      "$target_name%^RED%^ $target_verb%^RESET%^ to appreciate the perfection of "
      "$agent_possessive_noun song.",
      who, t, environment(t) );
      continue;
  }
  return 1;
}
