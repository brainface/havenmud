/*
 * Chain lightning clone,
 *  specifically for warlocks
 *
 * Smacks a dude with randomly cold or fire
 *  damage boost boost only the right damage type
 *
 */
#include <lib.h>
#include <magic.h>
#include <damage_types.h>
inherit LIB_SPELL;

static void create() {
  spell::create();
  SetSpellType(SPELL_COMBAT);
  SetSpell("banefire");
  SetDifficulty(40);
  SetSkills( ([
     "faith" : 250,
     "necromancy" : 250,
    ]) );
  SetEnhanceSkills( ({ "ice magic", "fire magic", "poison magic" }) );
  SetRules("", "LIV");
  SetHelp(
    "This spell allows a priest to channel a multitude of stygian flames "
    "against an enemy of the faith. These flames from the depths of hell "
    "will have a multitude of unwanted effects on the target.");
}

varargs int eventCast(object who, int level, mixed limb, object array targets) {
  object victim;
  int num_hits, i;
  string r_limb;
  string hit_verb, hit_message;
  int fireOrCold = 0;
  int damage_type = HEAT;
  int damage, fire_damage, poison_damage, cold_damage, d_count, damageboost;

  if( CanAttack(who, targets, GetSpellLevel() + level/5) == - 1 ) {
     who->eventPrint("Your powers fail you.");
     return 0;
  }
  num_hits = ( who->GetSkillLevel("faith") / 20 );
  if (num_hits < 1)  num_hits = 1;
  if (num_hits > 10) num_hits = 10;
  damage   = GetDamage(level);
  fire_damage = damage;
  cold_damage = damage;
  poison_damage = damage;

  // calculate damage for fire bolts
  damageboost = who->GetSkillLevel("fire magic") / (GetSpellLevel() * 2);
  if (damageboost > 3) damageboost = 3;
  fire_damage += fire_damage * damageboost;
  fire_damage = fire_damage / 3;
  if (fire_damage < 5) fire_damage = 5;

  // calculate damage for cold bolts
  damageboost = who->GetSkillLevel("ice magic") / (GetSpellLevel() * 2);
  if (damageboost > 3) damageboost = 3;
  cold_damage += cold_damage * damageboost;
  cold_damage = cold_damage / 3;
  if (cold_damage < 5) cold_damage = 5;

  // calculate damage for poison bolts

  damageboost = who->GetSkillLevel("poison magic") / (GetSpellLevel() * 2);
  if (damageboost > 3) damageboost = 3;
  poison_damage += poison_damage * damageboost;
  poison_damage = poison_damage / 3;
  if (poison_damage < 5) poison_damage = 5;


  victim = targets[0];

  send_messages( ({ "launch", }),
    "$agent_name $agent_verb a volley of "
    "%^BOLD%^MAGENTA%^stygian flames%^RESET%^ towards $target_name!",
    who, victim, environment(who));

  // send out the bolts
  i = 0;
  while(i < num_hits) {
    r_limb = victim->GetRandomLimb();
    i++;
    if (victim->GetDying()) break;
    if (present(victim, environment(who)) && living(victim)) {
    fireOrCold = random(3);

    // change message and damage types to appropriate element
    switch(fireOrCold) {
      case 0:
        damage_type = HEAT;
        hit_verb = "scorch";
        hit_message = "$agent_name%^BOLD%^RED%^ $agent_verb%^RESET%^ " +
          "$target_possessive_noun " + r_limb + " with a tongue of infernal flame!";
        damage = fire_damage;
        break;
      case 1:
        damage_type = COLD;
        hit_verb = "blister";
        hit_message = "$agent_name%^BOLD%^%^CYAN%^ $agent_verb%^RESET%^ " +
          "$target_possessive_noun " + r_limb + " with freezing ethereal fire!";
        damage = cold_damage;
        break;
      case 2:
        damage_type = POISON;
        hit_verb = "corrupt";
        hit_message = "$agent_name%^BOLD%^%^GREEN%^ $agent_verb%^RESET%^ " +
          "$target_possessive_noun " + r_limb + " with noxious stygian fumes!";
        damage = poison_damage;
        victim->AddPoison(random(who->GetSkillLevel("poison magic")/50)+1);
        break;
    }


    // hit someone with a bolt
    send_messages(hit_verb,
       hit_message,
       who, victim, environment(who));
       d_count += (victim->eventReceiveDamage(who, damage_type, damage, 0, r_limb));
    }
  }
  return d_count;
}

