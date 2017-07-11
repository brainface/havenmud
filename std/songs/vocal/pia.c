// Pianissimo Song
// Recoded by Laoise
// August 2004

#include <lib.h>
#include <music.h>
inherit LIB_SONG;

int DoPianissimo(object who);
int EndPianissimo(object env);

static void create() {
  ::create();
  SetSong("pianissimo");
  SetRules("");
  SetMagicCost(30,10);
  SetSongType(SONG_OTHER);
  SetSkills( ([
    "vocal music" : 30,
  ]) );
  SetDifficulty(15);
  SetHelp(
    "Pianissimo is when the bard sings "
    "so softly that the beings in that area "
    "refrain from great movements for a time."
  );
}



varargs int eventSing(object who, int level, mixed limb, object array targets) {
  call_out( (: DoPianissimo :), random(3)+2, who);
}

int DoPianissimo(object who) {
  int timelength;
  if(!who || undefinedp(who)) {
    return 0;
  }
  if(environment(who)->GetProperty("no attack") > 0) {
    who->eventPrint("This room does not need to be quieted.");
    return 0;
  }
  if(!environment(who)->GetProperty("pianissimo"))
  {
    timelength = (random(15) + (who->GetSkillLevel("vocal music")));
    send_messages( ({"susurrate"}),"$agent_name $agent_verb "
                  "so silently with such %^CYAN%^pianissimo"
                  "%^RESET%^ that the surrounding area is "
                  "quieted, and aggression is faded out.",who,
                  0, environment(who));
    environment(who)->SetProperty("no attack", 1);
    environment(who)->SetProperty("pianissimo", 1);
    call_out( (: EndPianissimo :), timelength, environment(who));
    return 1;
  }
  else
  {
    who->eventPrint("This room is already quiet.");
    return 0;
  }
}

int EndPianissimo(object env) {
   send_messages(({""}), "The %^CYAN%^pianissimo%^RESET%^ hanging "
           "over the area fades away.",env, 0);
   env->SetProperty("no attack", 0);
   env->SetProperty("pianissimo", 0);
   return 1;
}
