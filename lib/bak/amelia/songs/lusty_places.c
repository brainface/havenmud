#include <music.h>
#include <lib.h>
inherit LIB_SONG;

private mapping LustyPlaces = ([
"blah" : "/realms/amelia/workroom"
  
  ]);

private mapping LustySongs = ([
"blah" : "lustyblah",
  ]);

static void create() {
  ::create();
  SetSong("testplace");
  SetRules("STR");
  SetSongType(SONG_OTHER);
  SetMagicCost(75, 75);
  SetStaminaCost(75, 75);
  SetDifficulty(50);
  SetSkills( ([
    "vocal music" : 25,
    "instrumental music" : 25,
    ]) );
  SetHelp("This song causes the bard to focus his energy thinking of "
          "a far away place from the description given in bardic "
          "stories.  While thinking of the place, the bard will actually "
          "be moved there from the magic of his song.  Be warned that "
          "this songs does not always work until the bard is very "
          "proficient with it." +
          "\nCurrently allowed Lusty Places are " +
          conjunction(keys(LustyPlaces)));
   }

varargs object *GetTargets(object who, mixed place) {
  return ({ (object)LustyPlaces[place] });
}


varargs int eventSing(object who, int level, string place, object *dest) {
  object target = dest[0];
  if (random(100) < who->GetSongLevel("lusty places")) {
    send_messages( ({ "sing", "finish", "disappear" }),
  "$agent_name $agent_verb a song about " + LustySongs[target] + ". "
      "After $agent_nominative $agent_verb $agent_possessive song, "
      "$agent_nominative%^BLUE%^BOLD%^ $agent_verb%^RESET%^.",
      who, 0, environment(who) );
      who->eventMove(target);
      return 1;
      }
   send_messages( ({ "sing", "finish", "look" }),
  "$agent_name $agent_verb a song about " + LustySongs[target] + ". "
     "When $agent_nominative $agent_verb $agent_possessive song, $agent_nominative "
     "$agent_verb slightly depressed.",
     who, 0, environment(who) );
   who->AddStaminaPoints(75);  /* Give back the base cost for failure */
   who->AddMagicPoints(75);
   return 1;
 }
