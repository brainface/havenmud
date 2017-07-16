/* combat/physical.c
 * handles damage, death, and death of enemies
 * Duuktsaryth 3 February 1999
 */
#include <lib.h>
#include <damage_types.h>
#include <vision.h>
inherit LIB_RACE;

/* virtual declarations */
int GetTestChar();
int GetCombatStyleLevel(string);
string GetCombatStyle();
int GetSkillLevel(string);
int GetStatLevel(string);
int GetLuck();
float GetWimpy();
int GetHealthPoints();
int GetMaxHealthPoints();
int eventMoralAct(int);
void FilterEnemies();
int RemoveEnemy(object);
object *GetEnemies();
int eventWimpy();
int GetBlessed();
int GetCursed();

static void create() {
  race::create();
}

int GetDamage(int weapon_class, string skill, int targdefskill) {
  int skill_level = GetSkillLevel(skill);
  int strength = GetStatLevel("strength");
  int luck = GetLuck();
  int tarmod, modifier;
  int dmg = 0;
  int ragemod;

  ragemod = GetSkillLevel("combat rage")/20;
  ragemod = random(ragemod);
  if (ragemod > 20) ragemod = 20;
  if (GetSkillLevel("combat rage") && ragemod < 1) ragemod = 1;
  strength = strength/25;
  tarmod   = random(targdefskill)/10 + 1;
  modifier = random(skill_level)/10 + 1;
  if (weapon_class < 1) weapon_class = 1;
  if (strength < 1) strength = 1;

  modifier /= tarmod;
  dmg = weapon_class;
  dmg += strength;
  dmg += ragemod;
  if (dmg > 1000) dmg = 1000;
  dmg *= modifier;
  dmg += GetBlessed();
  dmg -= GetCursed();
  if (dmg < 0) dmg = 0;
  if (GetTestChar() && GetProperty("combat_debug")) {
    debug("MySkill: " + GetSkillLevel(skill) + " TargetSkill: " + targdefskill + " WeaponClass: " + weapon_class +
          " Strength Bonus: " + strength + " Damage = " + dmg + " SkillModifier: " + modifier); 
    }
  return dmg;
  }

varargs int eventDie(object agent) {
  object ob;
  int x;

  x = race::eventDie(agent);
  if (x != 1) { return x; }
  foreach(ob in GetEnemies()) {
    if (ob)
    ob->eventEnemyDied(this_object());
    RemoveEnemy(ob);
    }
  FilterEnemies();
  return (sizeof(GetEnemies()) == 0);
}

void eventKillEnemy(object died) {
  if (!died) return;
  if (member_array(died, GetEnemies()) == -1) {
    eventMoralAct(-(died->GetMorality()));
    eventMoralAct(-5);
    }
}

void eventDestroyEnemy(object died) {
  if (!died) return;
  eventMoralAct(-(died->GetMorality()*2));
}

void eventEnemyDied(object died) {
  if (!died) return;
  RemoveEnemy(died);
}

varargs int eventReceiveDamage(object agent, int type,
                 int amount, int internal, mixed limbs) {
  int hp;

  amount = race::eventReceiveDamage(agent, type, amount, internal, limbs);
  if (!GetWimpy()) return amount;
  if ((hp = GetHealthPoints()) < 1) return amount;
  if (GetWimpy() < percent(hp, GetMaxHealthPoints()))
    return amount;
  if(GetInCombat())
    call_out((:eventWimpy:), 0);
  return amount;
}

int GetOffense(mixed skill) {
  int pro = 0;
  int skills = 0;
  
  if (!arrayp(skill)) skill = ({ skill });
  skills = sizeof(skill);
  if (!skills) return 0;
    
  foreach(string s in skill) pro += GetSkillLevel(s);
  pro = pro/skills;
  pro += GetStatLevel("agility")/10;
  pro += GetLuck()/10;
  if (GetSkillLevel("accuracy"))
     pro += (GetSkillLevel("accuracy")/20 || 1);
  if (userp()) if (GetBlind()) { pro = pro/10; }
  if (userp()) if (GetEffectiveVision() != VISION_CLEAR) { pro = pro/10; }
  return pro;
}

int GetDefense() {
  int x = 0;
  if (sizeof(GetWielded())) {
    x += GetSkillLevel(GetWielded()[0]->GetWeaponType() + " combat");
    x += GetSkillLevel("parry");
  } else {
    x += GetSkillLevel("melee combat");
  }
  x += GetSkillLevel("dodge");
  if (userp()) if (GetBlind()) { x = x/10; }
  if (userp()) if (GetEffectiveVision() != VISION_CLEAR) { x = x/10; } 
  return x;
}

varargs int eventInflictDamage(object agent, int type, int amount, int internal, mixed limbs) {
  int hp;

  amount = race::eventInflictDamage(agent, type, amount, internal, limbs);
  if (!GetWimpy()) return amount;
  if ((hp = GetHealthPoints()) < 1) return amount;
  if (GetWimpy() < percent(hp, GetMaxHealthPoints()))
    return amount;
  if(GetInCombat())
    call_out((:eventWimpy:), 0);
  return amount;
}
