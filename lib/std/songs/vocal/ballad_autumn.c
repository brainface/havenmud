// Amelia@Haven, Dec 98
#include <lib.h>
#include <music.h>
#include <damage_types.h>
inherit LIB_SONG;

static void create() {
   song::create();
   SetSong("ballad of autumn");
   SetRules("","LIV");
   SetMagicCost(75,75);
   SetSongType(SONG_COMBAT);
   SetSkills( ([
       "vocal music" : 95,
            ]) );
   SetDifficulty(35);
   SetHelp("The ballad of autumn is an ode to the falling leaves of "
           "this season.");
}

varargs int eventSing(object who, int level, mixed limb, object *targets) {
   object targ = targets[0];
   level = level + who->GetSkillLevel("vocal music");
   if(query_season(time()) == "autumn") {
      level = level * (7/2);
   }
   level -= (targ->GetStatLevel("coordination"))/2;
   level -= targ->GetLevel();
   if(level < 1) {
      if(!random(10)) {
         send_messages(({"sing","fall"}),"$agent_name $agent_verb a %^YELLOW%^"
                       "ballad of autumn%^RESET%^ to $target_name, "
                       "but $agent_verb down $agent_reflexive!",
                       who, targ, environment(who));
         who->eventCollapse();
         return 1;
      }
      send_messages("sing","$agent_name $agent_verb powerfully, but "
                    "$agent_possessive %^YELLOW%^ballad of autumn%^RESET%^ "
                    "does nothing to $target_name.",who,targ,
                    environment(who));
      return 1;
   }
   send_messages("sing","$agent_name $agent_verb the %^YELLOW%^ballad "
                 "of autumn%^RESET%^ with powerful lungs, prasing the "
                 "falling leaves, and causing $target_name to fall.",
                 who,targ,environment(who));
   targ->eventCollapse();
   return 1;
}


/* Approved by Duuktsaryth on Thu Dec 31 17:11:36 1998. */
