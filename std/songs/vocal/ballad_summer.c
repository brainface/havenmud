// Amelia@Haven, Dec 98
#include <lib.h>
#include <music.h>
#include <damage_types.h>
inherit LIB_SONG;

static void create() {
   song::create();
   SetSong("ballad of summer");
   SetRules("","LIV");
   SetMagicCost(20,5);
   SetSongType(SONG_COMBAT);
   SetSkills( ([
       "vocal music" : 35,
            ]) );
   SetEnhanceSkills( ({ "fire magic" }) );
   SetDifficulty(15);
   SetHelp("The ballad of summer is an ode to the hot, torrid months "
           "of the year.  When effective, it creates a dry, breeze-less "
           "and burning hot air to surround the target.");
}

varargs int eventSing(object who, int level, mixed limb, object *targets) {
   object targ = targets[0];
   level = level + who->GetSkillLevel("vocal music");
   if(query_season(time()) == "summer") {
      level = level * (12/7);
   }
   level += - targ->GetLevel();
   if(level < 1) {
      send_messages("sing","$agent_name $agent_verb $agent_possessive "
                    "best, but $agent_possessive ballad of summer does "
                    "nothing to $target_name.",who,
                    targ, environment(targ));
      return 1;
   }
   switch(level) {
      case 0..50:
      send_messages("complete","A stuffy, dry air surrounds $target_name as "
                    "$agent_name $agent_verb $agent_possessive "
                    "%^ORANGE%^ballad of summer%^RESET%^.  Wavy lines "
                    "of distortion hang in the air.",
                    who,targ,environment(targ));
      break;
      case 51..100:
      send_messages("","The %^ORANGE%^ballad of summer%^RESET%^ "
                    "is sung with furvor and gusto by $agent_name, "
                    "summoning a torrid blast of air that hangs "
                    "around $target_name.",who,targ,
                    environment(targ));
      break;
      default:
      send_messages("finish","Scorching heat surrounds $target_name as "
                    "$agent_name $agent_verb the %^ORANGE%^"
                    "ballad of summer%^.",
                    who,targ,environment(targ));
      break;
   }
   targ->eventReceiveDamage(who, HEAT, GetDamage(level));
   return 1;
}


