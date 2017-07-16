#include <lib.h>
#include <daemons.h>
#include <music.h>
#include <magic.h>
#include <damage_types.h>

inherit LIB_SONG;

static void create() {
  song::create();
  SetSong("reflective aria");
  SetRules("", "LIV");
  SetProtectionTypes(ALL_EXTERNAL);
  SetSongType(SONG_DEFENSE);
  SetSkills( ([
     "instrumental music"       : 150,
     "vocal music" : 150,
     ]) );
  SetMagicCost(175, 120);
  SetDifficulty(50);
  SetMorality(0);
  SetHelp(
            "This song envelopes the singer with a shroud "
            "of sharp notes that strike back at any attacker "
            "who hits it."
  );
  SetMessages( ({ 
        ({ "surround",
       "A brilliant harmony $target_verb $target_name "
       "with sharp notes." }),
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
      "The " + colour + "reflective aria %^RESET%^protecting "
      "$agent_name shrieks at $target_possessive attack.",
       who, agent, environment(who) );
  if (agent && living(agent) )
  if (living(agent) && !0)
  agent->eventReceiveDamage(who, MAGIC, who->GetSkillLevel("instrumental music")/10);
    return random(x);
}
 
void endCallback(object who) {
    if( who ) {
   send_messages("", 
      "The %^YELLOW%^reflective aria%^RESET%^ around $agent_name is silenced.",
      who, 0, environment(who));
    }
}

