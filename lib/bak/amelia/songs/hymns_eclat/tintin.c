// eclat song, Amelia@Haven, Dec 98
#include <lib.h>
#include <music.h>
#include <damage_types.h>
inherit LIB_SONG;

int CheckHeal(object ob);

static void create() {
   song::create();
   SetSong("exultant tintinnabulation");
  SetReligions("eclat");
   SetRules("");
   SetMagicCost(50,10);
   SetSongType(SONG_HEALING);
   SetSkills( ([
                 "instrumental music" : 20,
            ]) );
   SetDifficulty(45);
   SetHelp("Exultant tintinnabulation allows Eclatish chorists "
           "to play an instrument at their Goddess, entreating "
           "her to bring down angels with bells to heal all those "
           "around.");
}

varargs int CanSing(object who, int level, string limb, object array targets) {
   targets = all_inventory(environment(who));
   targets = filter(targets, (: living :));
   targets = filter(targets, (: CheckHeal :) );
   if(targets == ({ })) return 0;
   return ::CanSing(who, level, limb, targets);
}

varargs int eventSing(object who, int level, mixed limb, object array targets) {
   int derblah;
   derblah = who->GetStatLevel("wisdom") + level;
   derblah += who->GetSkillLevel("instrumental music")/2;
   targets = all_inventory(environment(who));
   targets = filter(targets, (: living :));
   targets = filter(targets, (: CheckHeal :));
   switch(derblah) {
      case 0..20:
      send_messages("beg","$agent_name $agent_verb "
                    "%^BLUE%^Amelia %^RESET%^with "
                    "sweet instrumental music to send angels "
                    "will bells to heal $agent_possessive "
                    "companions.  A soft jingling "
                    "noise hangs in the air in response.",
                    who,0,environment(who));
      break;
      case 21..50:
      send_messages("call","$agent_name $agent_verb upon "
                    "%^BLUE%^Amelia %^RESET%^to "
                    "send angels ringing bells.  Tinkling "
                    "chime noises fill the air.",
                    who,0,environment(who));
      break;
      default:
      send_messages("","$agent_possessive_noun entreaty to "
                   "$agent_possessive %^BLUE%^Goddess "
                   "Amelia%^RESET%^ is so strong "
                   "that she sends a choir of angels that "
                   "ring bells in an exultant tintinnabulation.",
                   who,0,environment(who));
   }
   foreach(object targ in targets) {
      targ->eventHealDamage(derblah);
      message("spell","You feel a little healthier.",targ);
      targ->eventDisplayStatus();
   }
   return 1;
}

int CheckHeal(object ob) {
   if(ob->GetMaxHealthPoints() == ob->GetHealthPoints()) return 0;
   return 1;
}
