#include <lib.h>
#include <damage_types.h>
#include <music.h>
inherit LIB_SONG;

static void create() {
  song::create();
  SetSong("vibrations of destruction");
  SetDifficulty(85);
  SetHelp(
         "Allows the bard to play a note that resonates within the targets "
         "limb causing them to either be disrupted by the sonic vibrations and "
         "fall off or cause extreme damage.");
  SetRules("", "LIV");
  SetSongType(SONG_COMBAT);
  SetMagicCost(75, 75);
  SetSkills( ([
     "instrumental music" : 75,
      ]) );
  }

int eventSing(object who, int level, mixed n, object *targets) {
  object target = targets[0];
  string limb = target->GetRandomLimb("torso");
  int damage = GetDamage(level);
  int limb_hp = target->GetLimb(limb)["health"];

  if(environment(target) != environment(who)) return 0;
  damage = target->eventReceiveDamage(who, ACID, damage, 0, limb);
  if(damage >= limb_hp) {
      send_messages("play",
       "$agent_name $agent_verb a note that causes $target_possessive_noun " + limb + " to "
       "dissolve into a puddle of goo that rapidly sinks into the ground.", 
        who, target, environment(who) );
       target->RemoveLimb(limb);
      if(present("limb", environment(target)))
       present("limb", environment(target))->eventDestruct();
       return 1;
      }
  send_messages( ({ "play", "succeed" }),
    "$agent_name $agent_verb a note that causes $target_possessive_noun " + limb +
    " to bubble and partially liquefy but it fails in destroying $target_possessive " + limb + ".",
     who, target, environment(who) );
  return 1;
  }

