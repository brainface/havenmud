// Amelia@Haven, 2005
#include <lib.h>
#include <music.h>
#include <damage_types.h>
inherit LIB_SONG;

varargs int eventAutumn(object who, int level, mixed limb, object *targets);
varargs int eventSummer(object who, int level, mixed limb, object *targets);
varargs int eventSpring(object who, int level, mixed limb, object *targets);
varargs int eventWinter(object who, int level, mixed limb, object *targets);

static void create() {
   song::create();
   SetSong("ballad of the seasons");
   SetRules("","LIV");
   SetMagicCost(150,150);
   SetSongType(SONG_COMBAT);
   SetSkills( ([
                 "vocal music" : 125,
            ]) );
   SetDifficulty(75);
   SetHelp("The ballad of the seasons is a song that praises all of the seasons of the "
	"year.");
}

varargs int eventSing(object who, int level, mixed limb, object *targets) {
   eventSpring(who, level, limb, targets);
   eventSummer(who, level, limb, targets);
   eventAutumn(who, level, limb, targets);
   eventWinter(who, level, limb, targets);
   return 1;
}

varargs int eventAutumn(object who, int level, mixed limb, object *targets) {
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

varargs int eventSpring(object who, int level, mixed limb, object *targets) {
   object targ = who;
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
   targ->eventHealDamage(level);
  return 1;
}

varargs int eventSummer(object who, int level, mixed limb, object *targets) {
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
                    "is sung with ferver and gusto by $agent_name, "
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
   targ->eventReceiveDamage(who, HEAT, level, 0, targ->GetRandomLimb());
   return 1;
}

varargs int eventWinter(object who, int level, mixed limb, object *targets) {
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
   targ->eventReceiveDamage(who, COLD, level, 0, targ->GetRandomLimb());
    return 1;
}