// Title: Sea Chanty
// File: seachanty.c
// Author: Mahkefel@Haven
// Date: December 2010
//
// Abstract: OHH EEE OHH, OHHHHH EE OHH
//
// Revision History:
//

#include <lib.h>
#include <music.h>
inherit LIB_SONG;

static void create() {
  song::create();
  SetSong("sea shanty");
  SetRules("", "LIV");
  SetSongType(SONG_HEALING);
  SetSkills( ([
    "vocal music" : 80,
  ]) );
  SetMagicCost(50, 50);
  SetDifficulty(20);
  SetHelp(
    "With this cheerful, rythmic song a bard can "
    "lift the spirits of one doing repetitive tasks at "
    "sea, restoring some fatigue. Those who have worked "
    "aboard ship themselves can better perform this type "
    "of song."
  );
  SetUniqueSong(1);
}

varargs int CanSing(object who, int level, string limb, object array targets) {
  object target = targets[0];
  if (who->GetClass() != "siren" && !who->GetTestChar()) {
    who->eventPrint("Only sirens can use this song. You should forget it.");
    return 0;
  }
  if( target->GetStaminaPoints() == target->GetMaxStaminaPoints()) {
    if( target == who )
      write("You do not need any more stamina.", who);
    else
      write(target->GetName()+" does not need any more stamina.",who);
    return 0;
  }
  return song::CanSing(who, level, limb, targets);
}

varargs int eventSing(object who, int level, mixed limb, object array targets) {
  int healing, modifier;
  object target = targets[0];
  modifier = (who->GetSkillLevel("sailing") +
    who->GetSongLevel("sea shanty") )/ 40;
  if( modifier < 1 ) 
    modifier = 1;
  healing = (GetMagicCost(who) * modifier);
  if( healing > GetMagicCost(who) * 4 )
    healing = GetMagicCost(who) * 4;
  send_messages(({"stamp","sing"}),
    "$agent_name $agent_verb $agent_possessive feet and "
    "$agent_verb an old shanty to lift "
    "$target_possessive_noun spirits.", who, target, environment());
  //debug( "shanty cost: " + (string)GetMagicCost(who) );
  //debug( "shanty healing: " + (string)(healing/5) );
  target->AddStaminaPoints(to_int(healing/5));
  return 1;
}

