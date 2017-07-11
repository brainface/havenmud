#include <lib.h>
#include <damage_types.h>
#include <magic.h>
inherit LIB_SPELL;
int eventStab(object who, object target);
int eventPrintDamage(object who, object target, int percentDamage);

static void create() {
  ::create();
  SetSpell("daggers of betrayal");
  SetRules("","LIV");
  SetSpellType(SPELL_COMBAT);
  SetDifficulty(200);
  SetSkills( ([
      "evokation" : 175,
      "faith" : 175,
    ]) );
  SetReligions("Soirin");
  SetHelp(
          "This is by far one of the most powerful spells a soirin cleric "
          "can get. It allows them to summon forth daggers to backstab their "
          "target and then fade.");
 }

varargs int eventCast(object who, int level, mixed x, object *targets) {
  object target = targets[0];
  object env;
  float tmp;
  int suprise;
  object *weapons;
  int num_hits;
  int numberOfStabs;
  int i;
  
  if( CanAttack(who, targets, GetSpellLevel() + level/5) == - 1 ) {
            who->eventPrint("Your powers fail you.");
            return 0;
        } 

  num_hits = ( ( (who->GetSkillLevel("faith")-400)/50) );              
  if (num_hits < 1)  num_hits = 1;
  if (num_hits > 5) num_hits = 5;

  tmp = (who->GetSkillLevel("faith")*1.5)*(level/100);
  tmp += who->GetStatLevel("charisma")/2;
  tmp += who->GetStatLevel("luck")/3;
  tmp += who->GetMobility()/3;
  tmp -= target->GetStatLevel("luck")/3;
  tmp -= target->GetMobility()/5;
  tmp *= level/80;
  if(tmp < 1) tmp = 1;
  suprise = to_int(tmp);

  moral_act(who, target, -50);

  if (target->GetSleeping()) {
        if (random(600) < who->GetLevel("faith")) {
                send_messages( ({ "summon","slaughter" }),
                  "$agent_name $agent_verb a pair of %^BOLD%^WHITE%^silver%^RESET%^ "
                  "which %^BOLD%^WHITE%^B_RED%^ $agent_verb%^RESET%^ $target_name in " 
              "$target_possessive sleep!",
                  who, target, environment(target) );
                  target->eventDie(who);
                  moral_act(who, target, -90);
                  return 1;
                }
        }
                         
  if(suprise < random(100) || !present(target, environment(who))) {
    who->eventPrint("%^RED%^" + target->GetName()
      + " quickly dodges out of the way of your summoned daggers.%^RESET%^");
    target->eventPrint("%^RED%^You easily dodge " + possessive_noun(who)
      + " summoned daggers before they strike you.%^RESET%^");
    environment(who)->eventPrint("%^RED%^" + target->GetName()
      + " dodges " + possessive_noun(who) + " summoned daggers.%^RESET%^",
      ({who, target}));
    target->SetSleeping(0);
    target->eventStand();
    target->SetAttack(who);
    target->AddEnemy(who);
    return 1;
  }

  numberOfStabs = 0;
  for(i = 0; i < num_hits && target; i++)
    numberOfStabs += eventStab(who, target);
  if(!numberOfStabs) {
    target->eventPrint("%^RED%^You quickly dodge " + possessive_noun(who)
      + " summoned daggers.%^RESET%^");
    return 1;
  }

  who->eventExecuteAttack(target);
  return 1;
 }

int eventStab(object who, object target) {
  int damage;
  float x;
  int percentDamage;
  float adjustment;

  x = who->GetLevel() / 3;
  x += who->GetSkillLevel("faith")/1.0;
  x += who->GetStatLevel("strength")/2.0;
  x += who->GetStatLevel("luck")/3.0;
  x -= target->GetStatLevel("luck")/3.0;
  x *= 0.5;
  x = (x + random(to_int(x))) / (100/who->GetSpellLevel("daggers of betrayal"));
  x = x/6;
  if(x < 1.0) x = 0.0;

  damage = (int)target->eventReceiveDamage(who, PIERCE|POISON, GetDamage(to_int(x)), 0, target->GetTorso());
  if(damage > 0) {
    percentDamage = damage * 100 / target->GetMaxHealthPoints();
    if(percentDamage < 1) percentDamage = 0;
  }
  else return 0;
  eventPrintDamage(who, target, percentDamage);
  who->eventMoralAct(-5);
  return 1;
}

int eventPrintDamage(object who, object target, int percentDamage) {
  string adverb;
  string myVerb;
  string verb;

/* FAIL FAIL FAIL */
  if(!percentDamage) {
    who->eventPrint("%^RED%^You fail to summon forth a dagger "
      "of betrayal allowing "
      + target->GetName() + " to strike!%^RESET%^");
    environment(who)->eventPrint("%^RED%^" + who->GetName()
      + " stumbles towards " + target->GetName() + " awkwardly, failing to summon forth a "
      "dagger of betrayal allowing "
      + target->GetName() + " to strike!%^RESET%^",
      ({who, target}));
    target->SetSleeping(0);
    target->eventStand();
    target->SetAttack(who);
    target->eventWeaponRound(who, target->GetWielded());
    return 1;
  }

/* KILL KILL KILL */
  if(percentDamage < 15) {
    myVerb = "thrust ";
    verb = "thrusts ";
    adverb = "deeply ";
  }
  else if(percentDamage < 30) {
    myVerb = "stab ";
    verb = "stabs ";
    adverb = "painfully ";
  }
  else {
    myVerb = "slam ";
    verb = "slams ";
    adverb = "gravely ";
  }

  who->eventPrint("%^RED%^You " + myVerb + "your "
    "summoned dagger " + adverb + "into "
    + possessive_noun(target) + " back.%^RESET%^");
  target->eventPrint("%^RED%^Your back sears with pain as a dagger "
    + verb + adverb + "into you.%^RESET%^");
  environment(who)->eventPrint("%^RED%^" + who->GetName() + " "
    + verb + possessive(who) + " summoned dagger " + adverb + "into " 
    + possessive_noun(target) + " back.%^RESET%^",
    ({who, target}));

  return 1;
}

