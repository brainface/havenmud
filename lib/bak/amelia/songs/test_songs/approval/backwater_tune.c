//--     Torak@Haven    --//
//--   BackWater Tune   --//
//--     Bardic Song    --//

#include <lib.h>
#include <music.h>
#include <damage_types.h>

inherit LIB_SONG;

void eventGoWithTheFlow();

static void create() {

  song::create();
  SetSong("backwater tune");
  SetRules("");
  SetSongType(SONG_OTHER);
  SetSkills( ([
    "instrumental music" : 1,
    "vocal music"        : 1,
    ]) );
  SetDifficulty(1);
  SetRequiredStamina(10);
  SetStaminaCost(8, 2);
  SetRequiredMagic(30);
  SetMagicCost(25, 5);
  SetMorality(0);
  SetHelp("Syntax: <sing backwater tune>\n\n"
    "A simple and pleasant song written by an anonymous bard "
    "whle traveling through the HavenWood.  Its simplicity "
    "and ease to play are amazing and everyone who enjoys the "
    "song seams to regain their powers sooner.");
  }

int CanSing(object who, int level, string limb, object *targets) {
  return song::CanSing(who, level, limb, targets);
  }

int eventSing(object who, int level, mixed limb, object *targets) {
  int bonus, songlength, chance, everyone;
  bonus = ((who->GetLevel()) + 2);
  songlength = 
    ((who->GetLevel()) + who->
    GetSpellLevel("backwater tune") + who->
    GetSkillLevel("vocal music"))/2;
  chance = (who->GetLevel());
  everyone = filter(all_inventory(environment(this_player())),
    (: noncreatorp :));

  if(chance <= 5) {
    send_messages("playing", "With a slow rhythem and upbeat tempo, "
                            "$agent_name $agent_verb playing "
                            "Backwater Tune and eases the "
                            "minds and soothes the worries of everyone "
                            "in the area."
                            ,who,0,environment(who));
    everyone->AddMagic(bonus);
    everyone->AddStamina(bonus);
    call_out( (: eventGoWithTheFlow() :), songlength);
    return 1;
    }

  if(chance >= 6) {
    send_messages("playing", "With a slow rhythem and upbeat tempo, "
                            "$agent_name $agent_verb playing "
                            "Backwater Tune and eases the "
                            "minds and soothes the worries of everyone "
                            "in the area."
                           ,who,0,environment(who));
    everyone->AddMagic(bonus + 20);
    everyone->AddStamina(bonus + 20);
    call_out( (: eventGoWithTheFlow() :), songlength);
    return 1;
    }
  }

void eventGoWithTheFlow() {
  object who;
  who = filter(all_inventory(environment(this_player())), (: noncreatorp :));
  if( (who) ) {
    send_messages("", "As Backwater Tune comes to "
                      "a close, $agent_name sheds a tear "
                      "as even $agent_nominative was moved by the song."
                      ,who,0,environment(who));
    }
  }
