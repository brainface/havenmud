/* combat/physical.c
 * handles damage, death, and death of enemies
 * Duuktsaryth 3 February 1999
 */
#include <lib.h>
#include <damage_types.h>
inherit LIB_RACE;

/* virtual declarations */
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

static void create() {
  race::create();
}

int GetDamage(int weapon_class, string skill, int targdefskill) {
  int skill_level = GetSkillLevel(skill);
  int strength = GetStatLevel("strength");
  int luck = GetLuck();
  int dmg = 0;

  strength = strength/4;
  skill_level = skill_level/4;
  weapon_class = weapon_class * 2;
  if (weapon_class < 1) weapon_class = 1;
  if (strength < 1) strength = 1;
  if (skill_level < 1) skill_level = 1;

  dmg = weapon_class;
  dmg += luck;
  dmg += skill_level;
  dmg += strength;
  dmg += (random(skill_level) +1);
  dmg = dmg - 0.3 * targdefskill; //added to have defensive skill matter
                   // Note: average skill_level effectiveness is ranged from .25-.5,
                   // average 0.375, so attack skill still matters more then def skill
  if (dmg < 0) dmg = 0;
  if (GetCombatStyle() == "sparring") {
    dmg -= (dmg * GetCombatStyleLevel("sparring"))/100;
    } /* reduce my damage by how effective a sparrer I am */
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
  call_out((:eventWimpy:), 0);
  return amount;
}
