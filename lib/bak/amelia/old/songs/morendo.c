// Amelia@Haven, Jan 99
#include <lib.h>
#include <music.h>
#include <damage_types.h>
inherit LIB_SONG;

static void create() {
   song::create();
   SetSong("morendo");
   SetRules("","LIV");
   SetMagicCost(200,0);
   SetRequiredMagic(200);
   SetStaminaCost(200,0);
   SetRequiredStamina(200);
   SetSongType(SONG_COMBAT);
   SetAutoDamage(0);
   SetSkills( ([
                 "instrumental music" : 95,
                 "vocal music" : 95,
            ]) );
   SetHelp("Morendo is a rousing song with great "
           "power.  As the last note fades out, "
           "the target is drained of life.");
   SetDifficulty(65);
}

varargs int eventSing(object who, int level, mixed limb, object array targets) {
   object targ = targets[0];
   level -= targ->GetLevel();
   level += (who->GetSkillLevel("vocal music") + who->GetSkillLevel("instrumental music") )/4;
   if(level < 1) {
      send_messages(({ "fail" }),"$agent_name "
                    "$agent_verb.",who,targ,
                    environment(targ));
      return 1;
   }
   targ->eventHealDamage(-(targ->GetHealthPoints())+4);
   targ->eventCollapse();
   send_messages("", "$agent_possessive_noun song "
                 "echoes with power, $agent_possessive "
                 "voice and instrument harmonizing "
                 "beautifully, letting the last "
                 "note dying away in the effects of "
                 "%^RED%^morendo%^RESET%^, draining "
                 "the life of $target_name.",who,
                 targ,environment(who));
   return 1;
}
