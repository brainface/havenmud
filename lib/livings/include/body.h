#ifndef l_body_h
#define l_body_h
 
static void create();
static void heart_beat();
void restart_heart();

int CanFly();
int SetRecoveryTime(int);

void eventCheckHealing();
void eventCompleteHeal(int x);
mixed eventFall();
varargs int eventHealDamage(int x, int internal, mixed limbs);
int eventBleed(int);
varargs int eventReceiveDamage(object agent, int type, int x, int internal, mixed limbs);
int eventCheckProtection(object agent, int type, int damage);
int eventCheckResistance(int amount, int type);
 
mixed eventReceiveThrow(object who, object what);
varargs int eventDie(object agent);
int eventRemoveItem(object ob);
int eventWear(object ob, mixed limbs);
 
void NewBody(string race);
mixed CanWear(object armour, string *limbs);
varargs int AddLimb(string limb, string parent, int classes, int *armours);
int RestoreLimb(string str);
int RemoveLimb(string limb, object agent);
mapping GetLimb(string limb);
string GetRandomLimb(string targ);
string GetTorso();
string *GetLimbs();
int GetLimbClass(string limb);
string GetLimbParent(string limb);
string GetParentLimb(string limb);
string *GetLimbChildren(string limb);
mapping GetMissingLimb(string limb);
string *GetMissingLimbs();
string GetLong(string nom);
string *GetWieldingLimbs();
varargs int AddFingers(string limb, int x);
int GetFingers(string limb);
varargs object *GetWorn(string limb);
varargs mixed GetWielded(string limb);
varargs int AddHealthPoints(int x, string limb, object agent);
varargs int GetHealthPoints(string limb);
varargs int GetMaxHealthPoints(string limb);
int AddMagicPoints(int x);
int GetMagicPoints();
int GetMaxMagicPoints();
float AddStaminaPoints(mixed x);
int GetStaminaPoints();
float GetMaxStaminaPoints();
int AddMagicProtection(class MagicProtection cl);
class MagicProtection *GetMagicProtection();
int RemoveMagicProtection(int i);
int SetUndead(int x);
int GetUndead();
string SetUndeadType(string str);
string GetUndeadType();
int GetBlessed();
int GetCursed();
int AddBlessed(int);
int AddCursed(int);
int SetSleeping(int x);
int GetSleeping();
int GetBleeding();
int SetBleeding(int);
int AddBleeding(int);
int AddAlcohol(int x);
int GetAlcohol();
int AddCaffeine(int x);
int GetCaffeine();
int AddFood(int x);
int GetFood();
int AddDrink(int x);
int GetDrink();
int AddPoison(int x);
int GetPoison();
int GetDying();
string GetResistance(int type);
string GetRace();
string GetName();
string GetCapName();
int GetHeartRate();
int GetHealRate();
/* pure virtual */ string GetShort();
/* pure virtual */ varargs mixed eventPrint(mixed msg, mixed cl, mixed three);
/* pure virtual */ varargs void SetParalyzed(int x, function f);
int GetParalyzed();
int AddRecoveryTime(int);
int GetRecoveryTime();
/* pure virtual */ varargs mixed eventMoveLiving(mixed dest, string omsg,
						 string imsg);
int GetStatLevel(string);
int GetProperty(string);
void eventDisplayStatus();
int GetSize();
int GetInCombat();
    /* pure virtual */ int ClearShortSuffixes();
#endif /* l_body_h */
