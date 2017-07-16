#include <lib.h>
#include <magic.h>
#include <damage_types.h>
inherit LIB_SPELL;

static void create() {
  spell::create();
  SetSpellType(SPELL_COMBAT);
  SetSpell("corruption");
  SetDifficulty(155);
  SetSkills( ([
     "faith" : 250,
     "evokation" : 250,
    ]) );
  SetEnhanceSkills( ({ "poison magic" }) );
  SetRules("", "LIV");
  SetReligions("Soirin");
  SetHelp(
    "Harnessing the power of poison magic, this spell allows a Soirin priest"
    " to corrupt money into poisonous projectiles that are hurled at their"
    " opponent.");
}


varargs int eventCast(object who, int level, mixed limb, object array targets) { 
  object victim;
  int num_hits, i;
  string r_limb;
  int damage, d_count;
  int cost;
    if( CanAttack(who, targets, GetSpellLevel() + level/5) == - 1 ) {
            who->eventPrint("Your powers fail you.");
            return 0;
          }
        
  num_hits = (who->GetSkillLevel("faith") /25);
  if (num_hits < 1)  num_hits = 1;
  if (num_hits > 15) num_hits = 15;
  cost = num_hits * 50;
  damage = GetDamage(level);
    if (who->GetCurrency("roni") < cost) {
      who->eventPrint("You do not have enough roni to cast that spell.");
      return 0;
    }
  foreach(string enhance in GetEnhanceSkills()) {
          int damageboost = who->GetSkillLevel(enhance) / (GetSpellLevel() * 2);
          if (damageboost > 3) damageboost = 3;
          damage += damage * damageboost;
          }
  damage = damage/3;
  if (damage < 5) damage = 5;

  victim = targets[0];

  send_messages( ({ "hurl", }),
    "$agent_name $agent_verb a handful of coins at $target_name!",
    who, victim, environment(who));  

  i = 0;
    while(i < num_hits) {
    r_limb = victim->GetRandomLimb();
    i++;
    if (victim->GetDying()) break;
    if (present(victim, environment(who)) && living(victim)) {
      send_messages("slice",
         "$agent_possessive_noun %^GREEN%^%^BOLD%^corrupt coin%^RESET%^ slices"
         " into $target_possessive_noun " + r_limb + ".",
         who, victim, environment(who));
      d_count += (victim->eventReceiveDamage(who, SLASH|POISON, damage, 0, r_limb));
      }
  }
  who->AddCurrency("roni", -cost);
  return d_count;
}
