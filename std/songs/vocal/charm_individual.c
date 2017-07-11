#include <lib.h>
#include <music.h>
#include <rooms.h>
inherit LIB_SONG;

static void create() {
  ::create();
  SetSong("charm individual");
  SetSongType(SONG_OTHER);
  SetRules("LIV");
  SetSkills( ([
    "vocal music"   : 60,
    ]) );
  SetDifficulty(25);
  SetMagicCost(150, 150);
  SetHelp(
    "This song attempts to dominate the will of a sentient (non-animal) creature. "
    "Its effectiveness is dependant on many factors."
    );
}
 
varargs int CanSing(object who, int level, mixed limb, object *targets) {
  object t = targets[0];
  if (t->GetClass() == "animal") {
    who->eventPrint("But " + t->GetShort() + " is an animal!");
    return 0;
  }
  if (t->GetInCombat()) {
    who->eventPrint(capitalize(t->GetShort()) + " is too busy to listen to music!");
    return 0;
    }
  return ::CanSing(who, level, limb, targets);
}

int eventSing(object who, int level, mixed limb, object *targets) {
  object t = targets[0];
  int resistance, offense;
  
  offense    = (level * who->GetSkillLevel("vocal music"))/100;
  resistance = (t->GetLevel() + t->GetMagicResistance());
  if (who->GetTestChar())
    debug("Offense: " + offense + " vs Defense: " + resistance + " (MR: " + t->GetMagicResistance() + ")");
  if (offense > resistance) {
    send_messages( ({ "are", "are" }),
      "$target_name $target_verb enthralled by the song that $agent_name $agent_verb singing.",
      who, t, environment(t) );
    t->eventCollapse();
    t->eventForce("halt " + who->GetKeyName());
    who->eventForce("halt " + t->GetKeyName());
    t->eventMove(ROOM_VOID);
    t->RemoveEnemy(who);
    t->SetWander(0);
    who->RemoveEnemy(t);
    t->ResetCurrentEnemy();
    who->ResetCurrentEnemy();
    t->eventMove(environment(who));
    t->AddFriend(who->GetKeyName());
    t->SetOwner(who->GetKeyName());
    t->eventForce("follow " + who->GetKeyName());
    who->eventForce("lead " + t->GetKeyName());
    t->eventForce("grin " + who->GetKeyName());
    if (member_array(t, who->GetFollowers()) == -1) {
      who->eventPrint(capitalize(t->GetShort()) + " is not following you.");
      }
    t->SetParalyzed(0);
    return 1;
  }
  send_messages( ({ "fail" }),
    "$target_name $target_verb to appreciate the beauty of $agent_possessive_noun song!",
    who, t, environment(who) );
    t->SetAttack(who);
  return 1;
}

  
