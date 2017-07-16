#include <lib.h>
#include <damage_types.h>
#include <music.h>
inherit LIB_SONG;

static void create() {
  ::create();
  SetSong("star fall");
  SetSkills( ([
     "instrumental music" : 250,
     "vocal music" : 250,
  ]) );
  SetAreaSong(1);
  SetUniqueSong(1);
  SetRules("");
  SetMagicCost(150, 150);
  SetSongType(SONG_COMBAT);
  SetDifficulty(175);
  SetEnhanceSkills( ({ "fire magic" }) );
  SetHelp(
          "This powerful song beseeches the stars in the sky to strike "
          "everyone in the surrounding area with their power. Mastery of the "
          "star strike song is required to sing this song");
}

int CanSing(object who, int level, mixed limb, object *targets) {

  if(who->GetSongLevel("star strike") < 99) { 
        message("system","You have not mastered the star strike song. ",who);
      return 0;
      }

   return song::CanSing(who, level, limb, targets);
}

varargs int eventSing(object who, int level, mixed limb, object array targets) { 
  object victim;
  int num_hits, i;
  string r_limb;
  int damage, d_count;
    if( CanAttack(who, targets, GetSongLevel() + level/5) == - 1 ) {
            who->eventPrint("Your powers fail you.");
            return 0;
          }
  num_hits = (who->GetSkillLevel("vocal music") /10);
  if (num_hits < 1)  num_hits = 1;
  if (num_hits > 10) num_hits = 10;
  damage   = GetDamage(level);
  foreach(string enhance in GetEnhanceSkills()) {
          int damageboost = who->GetSkillLevel(enhance) / (GetSongLevel() * 2);
          if (damageboost > 3) damageboost = 3;
          damage += damage * damageboost;
          }
  damage = damage/2;
  if (damage < 5) damage = 5;

  
  send_messages( ({ "call", }),
    "$agent_name $agent_verb down a storm of falling stars!",
    who, 0, environment(who));
  i = 0;
  while(i < num_hits) {
    victim = targets[random(sizeof(targets))];
    r_limb = victim->GetRandomLimb();
     if (victim->GetRandomLimb() == 0) {
         r_limb = victim->GetRandomLimb();
       }
    i++;
    if (victim->GetDying()) break;
    if (present(victim, environment(who)) && living(victim)) {
      send_messages("slam",
         "$agent_name%^RED%^ $agent_verb%^RESET%^ $target_possessive_noun " + r_limb + " with a finger of star-fall.",
         who, victim, environment(who));
      d_count += (victim->eventReceiveDamage(who, BLUNT|HEAT, damage, 0, r_limb));
      }
  }
  return d_count;
}
