#include <lib.h>
#include <daemons.h>
#include <music.h>
#include <damage_types.h>

inherit LIB_SONG;

static void create() {
  song::create();
  SetSong("wail of the banshee");
  SetRules("");
  SetDamagingShield(1);
  SetProtectionTypes(ALL_DAMAGE);
  SetShieldType(SHIELD_TIMED);
  SetSongType(SONG_DEFENSE);
  SetSkills( ([
     "vocal music"       : 100,
     "instrumental music" : 100,
     ]) );
  SetMagicCost(100, 100);
  SetDifficulty(140);
  SetMorality(0);
  SetHelp(
            "This song warps the caster in a protective barrier of sound "
             "that protects the caster from all damage. The noise is harmful "
            "to those who encounter it, so any who touch the barrier are harmed "
            "by it."
  );
  SetMessages( ({ 
        ({ "wail",
       "$agent_name $agent_verb loudly and suddenly a "
       "%^BOLD%^%^YELLOW%^shimmering shield%^RESET%^ surrounds "
       "$target_name." }),
    ({ /* Handled by hitCallBack */ }),
    ({ /* handled by endCallBack */ }),
    }) );
}


int hitCallback(object who, object agent, int x, class MagicProtection cl) {
    string colour;
    
    if (who == agent) return 0;
    if( cl->time < 20 ) {
        colour = "%^YELLOW%^";
    }
    else {
            colour = "%^BOLD%^YELLOW%^";
    }
   send_messages("", 
      "The " + colour + "shimmering shield%^RESET%^ surrounding "
      "$agent_name screams at $target_name as $target_nominative hits it.",
       who, agent, environment(who) );
/*
  if (agent && living(agent) )
  if (living(agent) && !SPELLS_D->GetDamagingShield(agent))
  agent->eventReceiveDamage(who, MAGIC, who->GetSongLevel("wail of the banshee"), 0);
*/
    return x;
}
 
void endCallback(object who) {
    if( who ) {
   send_messages("", 
      "The %^WHITE%^shimmering shield%^RESET%^ around $agent_name disperses into the air.",
      who, 0, environment(who));
    }
}

