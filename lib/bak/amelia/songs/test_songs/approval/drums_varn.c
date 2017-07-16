//--     Torak@Haven     --//
//-- Drums of Karak Varn --//
//--     Bardic Song     --//

#include <lib.h>
#include <music.h>
#include <damage_types.h>

inherit LIB_SONG;

void eventFeelThePower();

static void create() {

  song::create();
  SetSong("drums of karak varn");
  SetRules("");
  SetSongType(SONG_OTHER);
  SetSkills( ([
    "instrumental music" : 15,
    "vocal music"        : 25,
    ]) );
  SetDifficulty(40);
  SetRequiredStamina(20);
  SetStaminaCost(15, 5);
  SetRequiredMagic(30);
  SetMagicCost(25, 5);
  SetMorality(0);
  SetHelp("Syntax: <sing drums of karak varn>\n\n"
    "A long lost war hymn from the Karak Varn army, the bards "
    "who know this song are the most sought after bards, as "
    "the Drums of Karak Varn has been known to inspire the "
    "souls of the weakest and the strongest people of Kailie.");
  }

int CanSing(object who, int level, string limb, object *targets) {
  return song::CanSing(who, level, limb, targets);
  }

int eventSing(object who, int level, mixed limb, object *targets) {
  int bonus, songlength, chance, everyone;
  bonus = ( (who->GetLevel() + who->GetSpellLevel("drums of karak varn") )/10 );
  songlength = 
    ((who->GetLevel()) + who->
    GetSpellLevel("drums of karak varn") + who->
    GetSkillLevel("vocal music"))/1.25;
  chance = (who->GetLevel());


  everyone = filter(all_inventory(environment(this_player())),
    (: noncreatorp :));

  if(chance <= 15) {
    send_messages("sing",  "As $agent_name $agent_verb the deep and "
                           "harmonic "
                           "%^MAGENTA%^Drums of Karak Varn%^RESET%^"
                           ", everyone "
                           "in in the area feels inspired and more "
                           "prepared for battle."
                           ,who,0,environment(who));
    everyone->AddStatBonus("strength", bonus);
    everyone->AddStatBonus("durability", bonus);
    call_out( (: eventFeelThePower() :), songlength);
    return 1;
    }

  if(chance >= 16) {
    send_messages("sing",  "As $agent_name $agent_verb the deep and "
                           "harmonic %^BOLD%^"
                           "%^MAGENTA%^Drums of Karak Varn%^RESET%^"
                           ", everyone "
                           "in in the area feels inspired and more "
                           "prepared for battle."
                           ,who,0,environment(who));
    everyone->AddStatBonus("strength", bonus + 2);
    everyone->AddStatBonus("durability", bonus + 2);
    call_out( (: eventFeelThePower() :), songlength + 100);
    return 1;
    }
  }

void eventFeelThePower() {
  object who;
  who = filter(all_inventory(environment(this_player())), (: noncreatorp :));
  if( (who) ) {
       who->RemoveStatBonus("strength");
       who->RemoveStatBonus("durability");
    send_messages("", "With the final stanza of "
                      "the Drums of Karak Varn "
                      "coming to an end, everyone "
                      "feals a sense of pride and at ease."
                      ,who,0,environment(who));
    }
  }
