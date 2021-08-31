/*  A mid level song */
// Targeting code commented out, SetAreaSong(1)
// Laoise, August, 2004
#include <lib.h>
#include <music.h>
#include <conditions.h>
inherit LIB_SONG;

static void create() {
  ::create();
  SetSong("song of sorrow");
  SetRules("");
  SetSkills( ([
     "instrumental music" : 10,
     "vocal music" : 10,
     ]) );
  SetDifficulty(20);
  SetMagicCost(50, 50);
  SetHelp("This painful song is such a heart rending tragedy "
          "that it oftens distracts attackers, preventing them "
          "from causing harm to the bard for a moment. "
          "Note that this song is cast on ALL of those in the area who "
          "are hostile to the bard. Also note that the pain of this song may "
          "cause previously passive individuals in the area to attack the "
          "singer. This song scales with level."
  );
  SetSongType(SONG_COMBAT);
  SetEnhanceSkills( ({ "poison magic" }) );
  SetAreaSong(1);
  SetCooldown(15);
  }


varargs int eventSing(object who, int level, mixed n, object *targets) {
  int duration = 2;
  int duration_bonus = 0;

  duration += who->GetSkillLevel("instrumental music")/5;
  duration_bonus += who->GetSkillLevel("poison magic")/5;
  if (duration > 10) duration = 10;
  if (duration_bonus > 10) duration_bonus = 10;
  duration = duration + duration_bonus;
  
  who->AddCooldown(GetSong(), GetCooldown());

  foreach(object target in targets) {
        if( CanAttack(who, targets, who->GetSkillLevel("vocal music")/2 + level/5) == - 1 ) {
        if (target) {
          who->eventPrint(target->GetShort() + " ignores your song.");
        }
    } else {

     send_messages( ({ "get", "forget" }),
       "$target_name $target_verb a forlorn look on " +
       "$target_possessive face, and $target_verb to attack.",
       who, target, environment(who) );
     target->AddCondition("You've got the blues.",CONDITION_PREVENT_COMBAT, duration);

    }

    /*  if (!target) continue;
    if (target->GetMagicResistance() >= level) {
      who->eventPrint(target->GetName() + " ignores your song.");
       }
  if (target->GetMagicResistance() < level) {
     send_messages( ({ "get", "forget" }),
       "$target_name $target_verb a forlorn look on " +
       "$target_possessive face, and $target_verb to attack.",
       who, target, environment(who) );
     target->SetParalyzed(who->GetLevel() / 5);
     }*/
  }
  return 1;
 }
