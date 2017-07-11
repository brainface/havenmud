// Amelia@Haven, Dec 98
#include <lib.h>
#include <music.h>
#include <damage_types.h>
inherit LIB_SONG;

static void create() {
   song::create();
   SetSong("ballad of spring");
   SetRules("","LIV");
   SetMagicCost(50,50);
   SetSongType(SONG_HEALING);
   SetSkills( ([
       "vocal music" : 55,
            ]) );
   SetDifficulty(15);
   SetHelp("The ballad of spring is an ode to the healing powers "
           "of those months in the year when the snow is melting "
           "away and the flowers are bursting into bloom.");
}

varargs int eventSing(object who, int level, mixed limb, object *targets) {
   object targ = targets[0];
   level = level + who->GetSkillLevel("vocal music");
   if(query_season(time()) == "spring") {
      level = level * 3;
   }
   switch(level) {
      case 0..50:
      send_messages("sing","Green swirls around $target_name as "
                    "$agent_name $agent_verb the%^GREEN%^ ballad of "
                    "spring.",
                    who,targ,environment(targ));
      break;
      case 51..100:
      send_messages("sing","Youth and beauty shines on the face of "
                    "$target_name while $agent_name $agent_verb the %^GREEN%^"
                    "ballad of spring%^RESET%^.",
                    who,targ,environment(targ));
      break;
      default:
      send_messages("sing","$agent_name $agent_verb on the beauty and "
                    "glory of spring with a sweet, clear voice that "
                    "brings health to $target_name at the end of the "
                    "%^GREEN%^ballad of spring%^RESET%^.",
                    who,targ,environment(targ));
      break;
   }
   targ->eventHealDamage(GetHealing(level));
  return 1;
}


/* Approved by Duuktsaryth on Thu Dec 31 17:13:30 1998. */
