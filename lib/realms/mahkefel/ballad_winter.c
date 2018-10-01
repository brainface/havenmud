// Amelia@Haven, Dec 98
#include <lib.h>
#include <music.h>
#include <damage_types.h>
inherit LIB_SONG;

static void create() {
   song::create();
   SetSong("ballad of winter");
   SetRules("","LIV");
   SetMagicCost(75,75);
   SetSongType(SONG_COMBAT);
   SetSkills( ([
       "vocal music" : 75,
            ]) );
   SetDifficulty(20);
   SetHelp("The ballad of winter is an ode to the cold months of the "
           "year.  When effective, it summons frosty, ice-filled "
           "winds that surround the target.");
}

varargs int eventSing(object who, int level, mixed limb, object *targets) {
   object targ = targets[0];
   level = level + who->GetSkillLevel("vocal music");
   if(query_season(time()) == "winter") {
      level = level * 2;
   }
   level -= targ->GetLevel();
   if(level < 1) {
      send_messages("sing","$agent_name $agent_verb $agent_possessive "
                    "best, but $agent_possessive %^BLUE%^ballad of winter%^RESET%^ does "
                    "not call the frigid winds of the north to surround "
                    "$target_name.",who,
                    targ, environment(targ));
      return 1;
   }
   switch(level) {
      
      case 0..50:
      send_messages("","$agent_possessive_noun angry %^BLUE%^ballad of winter "
                    "%^RESET%^echoes through the area, calling up a quick wind "
                    "full of snow that swirls around $target_name.",
                    who,targ,environment(targ));
      break;
      case 51..100:
      send_messages("sing","$agent_name $agent_verb the %^BLUE%^ballad of winter "
                    "%^RESET%^in a loud crashing voice, summoning the icy wind of "
                    "the north to harm $target_name.",who,targ,
                    environment(targ));
      break;
      default:
      send_messages("sing","$agent_name $agent_verb the %^BLUE%^ballad of winter "
                    "%^RESET%^with power in $agent_possessive voice, bringing the "
                    "frostbitten winds to howl around $target_name.",
                    who, targ, environment(targ) );
      break;
   }
   targ->eventReceiveDamage(who, COLD, GetDamage(level));
    return 1;
}


/* Approved by Duuktsaryth on Thu Dec 31 17:17:24 1998. */
