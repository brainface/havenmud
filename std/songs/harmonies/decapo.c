// Stolen from rez spell stuff.
#include <lib.h>
#include <music.h>

inherit LIB_SONG;

static void create() {
   ::create();
   SetSong("de capo");
   SetRules("LIV");
   SetSongType(SONG_OTHER);
   SetSkills( ([ 
      "vocal music" : 90,
      "instrumental music"   : 90,
   ]) );
   SetMagicCost(250,250);
   SetDifficulty(50);
   SetStaminaCost(250,250);
   SetHelp(
           "By singing de capo at an undead target, the musician "
	"attempts to return him to his previous state of life.");
}

int CanSing(object who, int level, mixed limb, object array targets) {
   foreach(object target in targets) {
      if(!target->GetUndead()) {
         message("system","But "+target->GetName()+" is not undead!.",who);
         return 0;
      }
   }
   return song::CanSing(who, level, limb, targets);
}

int eventSing(object who, int level, string limb, object array targets) {
   foreach(object target in targets) {
      send_messages( ({ "begin","restore" }),"$agent_name $agent_verb "
                        "with a delicate, vocal melody, but "
			"quickly progresses into a complicated "
			"harmony with $agent_possessive instrument.  "
			"Repeating the same stanzas over and over "
			"again, $agent_nominative $agent_verb "
			"$target_possessive_noun life!",
                         who,target,environment(who));
      target->eventRevive();
   }
   return 1;
}
