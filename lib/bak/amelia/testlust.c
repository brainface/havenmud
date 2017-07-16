#include <music.h>
#include <lib.h>
#define Verb GetVerb()
#define Rules GetRules()
inherit LIB_SONG;

private mapping LustyPlaces = ([
   "mellie" : "/realms/amelia/areas/castle/room/ent",  
  ]);

private mapping LustySongs = ([
  "mellie" : "Goddess of Joy",
  ]);

static void create() {
  ::create();
  SetSong("lusty places");
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
  find_living("amelia")->eventPrint("In GetTargets");
  return ({ (object)LustyPlaces[place] });
}

string GetErrorMessage() {
	return "Error message goes here.";
}

varargs mixed eventParse(object who, mixed array args...) {
    int count = sizeof(args);

    if( count < 1 ) {
        if( member_array("", Rules) == -1 ) {
            find_living("amelia")->eventPrint("1");
            return GetErrorMessage();
        }
        return ({});
    }
    if( Verb == "sing" ) {
        if( count == 1 ) {
            if( objectp(args[0]) ) {
                if( !living(args[0]) ) {
                    if( member_array("OBJ", Rules) == -1 ) {
            find_living("amelia")->eventPrint("2");
 
                       return GetErrorMessage();
                    }
                    return ({ args[0] });
                }
                if( sizeof(({ "OBJ", "LIV"}) & Rules) == 0 ) {
            find_living("amelia")->eventPrint("3");

                    return GetErrorMessage();
                }
                return ({ args[0] });
            }
            if( stringp(args[0]) ) {
                int which = member_array("against STR", Rules);
                
                if( which == -1 && member_array("STR", Rules) == -1 ) {
            find_living("amelia")->eventPrint("4");

                    return GetErrorMessage();
                }
                return ({ args[0] });
            }
        }
        if( member_array("STR of LIV", Rules) == -1 ) {
            find_living("amelia")->eventPrint("5");

            return GetErrorMessage();
        }
        if( stringp(args[0]) && objectp(args[1]) && living(args[1]) ) {
            return ({ args[0], args[1] });
        }
        return "Sing it on what of whom?";
    }
    else {
        if( count == 1 ) {
            if( objectp(args[0]) ) {
                if( sizeof(({ "for OBJ", "for LIV" }) & Rules) ) {
                    if( !living(args[0]) ) {
                        if( member_array("for OBJ", Rules) == -1 ) {
            find_living("amelia")->eventPrint("6");

                            return GetErrorMessage();
                        }
                    }
                    return ({ args[0] });
                }
            find_living("amelia")->eventPrint("7");

                return GetErrorMessage();
            }
            if( member_array("against STR", Rules) == -1 ) {
            find_living("amelia")->eventPrint("8");

                return GetErrorMessage();
            }
            return ({ args[0] });
        }
        if( member_array("against STR for LIV", Rules) == -1 ) {
            find_living("amelia")->eventPrint("9");

            return GetErrorMessage();
        }
        if( stringp(args[0]) && objectp(args[1]) && living(args[1]) ) {
            return ({ args[0], args[1] });
        }
        return "Pray for it against what for whom?";
    }
}


varargs int CanSing(object who, int level, string limb, object array targets) {
   find_living("amelia")->eventPrint("In Cansing");
   return ::CanSing(who, level, limb, targets);
}

varargs int eventSing(object who, int level, string place, object *dest) {
  object target = dest[0];
  find_living("amelia")->eventPrint("In eventSing");

  if (random(100) < who->GetSongLevel("lusty places")) {
    send_messages( ({ "sing", "finish", "disappear" }),
  "$agent_name $agent_verb a song about " + LustySongs[target] + ". "
      "After $agent_nominative $agent_verb $agent_possessive song, "
      "$agent_nominative $agent_verb.",
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