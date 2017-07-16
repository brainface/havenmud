//
// Summary: a day shield for bards
// Created by: Rhakz@Haven -- Angel Cazares
// For: Bards
// Date: 12/22/98
//
#include <music.h>
#include <lib.h>
#include <damage_types.h>
inherit LIB_SONG;

static void create() {
  ::create();
  SetSong("solar ballad");
  SetRules("", "LIV");
  SetSongType(SONG_DEFENSE);
  SetSkills( ([
      "instrumental music" : 25,
           ]) );
  SetMagicCost(29, 29);
  SetDifficulty(25);
  SetProtectionTypes(ALL_PHYSICAL|HEAT);
  SetProtectionAmount(500);
  SetShieldType(SHIELD_TIMED);
  SetMessages( ({
                 ({ "play", "$agent_name $agent_verb a "
                             "beautiful, calming song and a "
                             "%^YELLOW%^marvelous aura%^RESET%^ "
                             "starts protecting $target_name."}),
                 ({ "strike", "The dancing aura %^YELLOW%^waves%^RESET%^ "
                              "as $target_name $target_verb it." }),
                 ({ "", "The protecting aura %^BLUE%^fades%^RESET%^ "
                        "away into darkness." }),
             }) );
  SetHelp("This is a calm and soothing song often heard "
          "during the day. When played, the bard gets rewarded with "
          "protection from the natural powers of the sun and its "
          "light.");
}

varargs int eventSing(object who, int level, string limb, object array targets) {

  if (query_night()) {
    send_messages( "play", "$agent_name $agent_verb a beautiful and calm "
                           "melody", who, 0, environment(who) );
    return 0;
  }
  return song::eventSing(who, level, limb, targets);
}



/* Approved by Duuktsaryth on Wed Dec 23 03:04:31 1998. */
