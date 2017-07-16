/* combat/enemies.c
 * controls all functions of maintaining
 * attackers and valid livings in combat
 * Duuktsaryth 3 February 1999
 */

private object *Enemies;
private object *SpecialTargets;
private object  CurrentEnemy;
private object  Guard;

object GetGuard();
string GetCapName();

static void create() {
  Enemies        = ({});
  SpecialTargets = ({});
  CurrentEnemy   = 0;
  Guard = 0;
}

mixed direct_guard_liv() {
  if (GetGuard()) return GetCapName() + " is already being guarded.";
  return 1;
}

object SetGuard(object who) {
  if (!who) Guard = 0;
  return Guard = who;
}

object GetGuard() {
  if (!Guard) return (Guard = 0);
  if (!present(Guard, environment())) return (Guard = 0);
  if (member_array(Guard, Enemies) != -1) return (Guard = 0);
  return Guard;
}

int AddEnemy(object foe) {
  if (!foe || member_array(foe, Enemies) != -1) return 0;
  if (!living(foe)) return -1;
  if (creatorp(foe)) return 0;
  Enemies += ({ foe });
  return 1;
}

object *GetEnemies() {
  return (Enemies);
}

int RemoveEnemy(object foe) {
  if (!foe || member_array(foe, Enemies) == -1) {
    return 0;
    }
  Enemies -= ({ foe });
  return 1;
}

object SetCurrentEnemy(object foe) {
  if (!foe) return (CurrentEnemy = 0);
  if (!living(foe)) return (CurrentEnemy);
  if (member_array(foe, Enemies) == -1)
    AddEnemy(foe);
  return (CurrentEnemy = foe);
}

object GetCurrentEnemy() { return (CurrentEnemy); }

object ResetCurrentEnemy() {
  object *foes;

  foes = filter(Enemies, (: $1 && (environment($1) == environment()) :));
  if (!sizeof(foes)) return SetCurrentEnemy(0);
  return SetCurrentEnemy(foes[random(sizeof(foes))]);
}

void FilterEnemies() {
  Enemies = filter(Enemies, (: $1 && living($1) :) );
  return;
}

object *GetSpecialTargets() { return (SpecialTargets); }

object *AddSpecialTarget(object foe) {
  if (member_array(foe, Enemies) == -1) AddEnemy(foe);
  return (SpecialTargets += ({ foe }));
}

object *RemoveSpecialTarget(object foe) {
  return (SpecialTargets -= ({ foe }) );
}

object *SetSpecialTargets(object *foes) {
  return (SpecialTargets = foes);
}



