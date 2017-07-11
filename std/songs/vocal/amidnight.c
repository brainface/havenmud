//
// Invis spell
// Thoin@Haven

#include <lib.h>
#include <music.h>

int eventEndInvis(object);
inherit LIB_SONG;

static void create() {
  song::create();
  SetSong("aria of midnight");
  SetSongType(SONG_OTHER);
  SetRules("");
  SetSkills(  ([
     "vocal music" : 50,
               ])  );
  SetMagicCost(75, 75);
  SetDifficulty(125);
  SetHelp(
          "This aria is about the darkest midnight when there are no stars or moons "
          "in the sky. The bard is able to call upon this great darkness to conceal "
          "themself from sight.");
}

int CanSing(object who, int level, mixed limb, object array targets) {
  object target = targets[0];
  if (who->GetInvis()) {
    message("system", "You are already invisible.", who);
    return 0;
  }
  return song::CanSing(who, level, limb, targets);
}

int eventSing(object who, int level, string limb, object array targets)  {
  level = level + who->GetSkillLevel("vocal music")/10;
  send_messages( ({ "sing", "fade" }), 
     "$agent_name $agent_verb an aria about the darkest midnight.",
     who, 0, environment(who));
  if (random(100) <= level ) who->SetInvis(1);
  if (who->GetInvis()) 
     call_out( (: eventEndInvis, who :), level * 5 );
  return 1;
  }

int eventEndInvis(object who) {
   if( (who) &&
       (who->GetInvis()) ) {
      who->SetInvis(0);
      send_messages("step", "$agent_name $agent_verb out of "
                    "the shadows.",who,0,environment(who));
  }
}
