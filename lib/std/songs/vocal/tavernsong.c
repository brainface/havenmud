#include <music.h>
#include <lib.h>
inherit LIB_SONG;

static void create() {
  ::create();
  SetSong("tavernsong");
  SetRules("", "LIV");
  SetDifficulty(20);
  SetSkills( ([
    "vocal music" : 15,
    ]) );
  SetMagicCost(50, 25);
  SetHelp("This song causes memories of times past in a given target. "
          "The memories recalled are those of a long ago drinking binge, "
          "which has the effect of causing the target to behave in a "
          "drunken manner.");
  SetSongType(SONG_OTHER);
  }

varargs int eventSing(object who, int level, mixed x, object *targets) {
  object target = targets[0];
  int amt;
  if (target->GetAlcohol() > target->GetStatLevel("durability")*3) {
     who->eventPrint("That person is way too drunk already.");
     return 1; 
  }

  send_messages( ({ "sing", }),
    "$agent_name $agent_verb a %^GREEN%^rousing%^RESET%^ tavern tune which reminds $target_name of a night long ago. ", 
    who, target, environment(who) );
  send_messages( ({ "look" }),
    "$target_name $target_verb drunk.",
    who, target, environment(who) );
  amt = 10;
  amt += (who->GetSkillLevel("vocal music")/10);
  amt *= (who->GetSongLevel("tavernsong")/100);
  if (target->GetAlcohol() / 2 > amt) {
    who->eventPrint("That person is as song-drunk as you can make them!");
    return 1;
  }
  target->AddAlcohol(amt);
  return 1;
}

    
