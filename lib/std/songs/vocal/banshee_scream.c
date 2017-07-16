//
// Summary: a song to destroy one's protections
// Created by: Rhakz@Haven -- Angel Cazares
// For: Bards
// Date: 12/23/98
//
#include <music.h>
#include <lib.h>
#include <damage_types.h>
inherit LIB_SONG;

static void create() {
  ::create();
  SetSong("banshee scream");
  SetRules("");
  SetSongType(SONG_OTHER);
  SetSkills( ([
               "vocal music" : 1,
           ]) );
  SetMagicCost(10, 10);
  SetDifficulty(5);
  SetHelp("This song has no musical value, as it is just a very high "
          "tone and loud scream that shatters the protections of the "
          "singer.");
}



varargs int eventSing(object who, int level, mixed limb, object array targets) {
   int i = sizeof(who->GetMagicProtection());
   while(i--) {
      who->RemoveMagicProtection(i);
   }
   send_messages( "let", "$agent_name $agent_verb out a loud and "
                         "high-pitched %^WHITE%^%^BOLD%^scream%^RESET%^, "
                         "shattering $agent_possessive magical protections.",
                          who,0,environment(who));
   return 1;
}


/* Approved by Duuktsaryth on Thu Dec 31 17:18:22 1998. */
