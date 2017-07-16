#include <lib.h>
#include <damage_types.h>
#include <music.h>
inherit LIB_SONG;

static void create() {
  ::create();
  SetSong("star strike");
  SetSkills( ([
     "instrumental music" : 150,
     "vocal music" : 150,
  ]) );
  SetRules("", "LIV");
  SetMagicCost(100, 100);
  SetSongType(SONG_COMBAT);
  SetEnhanceSkills( ({ "fire magic" }) );
  SetDifficulty(175);
  SetHelp(
          "This harmony calls out towards the skies with its beauty and wondrous "
          "melody to lend the power of the stars and strike the bards target.");
}

varargs int eventSing(object who, int level, mixed b, object *targets) {
  object target = targets[0];
  int num_hits, i;
  string r_limb;
  int damage, d_count;

  num_hits = ( ( (who->GetSkillLevel("instrumental music")-150)/10) );
                
  if (num_hits < 1)  num_hits = 1;
  if (num_hits > 15) num_hits = 15;

  damage   = GetDamage(level)/3;
  foreach(string enhance in GetEnhanceSkills()) {
          int damageboost = who->GetSkillLevel(enhance) / (GetSongLevel() * 2);
          if (damageboost > 3) damageboost = 3;
          damage += damage * damageboost;
          }
  if (damage < 5) damage = 5;

  send_messages( ({ "sing" }), "With a wondrous harmony, $agent_name "
        "$agent_verb %^BLUE%^star strike%^RESET%^, calling upon the stars to "
        "harm $target_name.",
        who,target,environment(who));

      i = 0;
      while(i < num_hits) {
          r_limb = target->GetRandomLimb();
          i++;
         if (target->GetDying()) break;
          if (present(target, environment(who)) && living(target)) {
            send_messages("incinerate","$agent_name%^BOLD%^%^BLUE%^ $agent_verb%^RESET%^ "
                "$target_possessive_noun " + r_limb + " with the power of the stars.",
                who, target, environment(who));
    d_count += (target->eventReceiveDamage(who, HEAT|MAGIC, damage, 0, r_limb));
          }
      }
  return d_count;
}

