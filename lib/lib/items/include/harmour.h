#ifndef l_armour_h
#define l_armour_h

static void create();
mixed direct_remove_obj();
mixed direct_wear_obj();
mixed direct_wear_obj_on_str(mixed fix...);

mixed CanWear(object who, string *limbs);
mixed CanWield(object who, string *limbs);

void eventDeteriorate(int type);
void eventEquipAgain(string *limbs);
int eventReceiveDamage(object agent, int type, int strength, int internal, mixed limbs);
mixed eventUnequip(object who);
mixed eventWear(object who, string *limbs);

string GetWornDescription();
string GetItemCondition();
int SetArmourType(int x);
int SetProtection(int type, int amount);
int AddProtectionBonus(int, int, int);
int RemoveProtectionBonus(int, int);
int GetProtectionBonus(int);
int GetProtection(int type);
int GetMaxProtection(int type);
string *SetRestrictLimbs(string *limbs);
string *GetRestrictLimbs();
int SetFingers(int x);
int GetFingers();
mixed SetWear(mixed val);
mixed GetWear();
string GetShort();
int AddDamage(int howMuch);

#endif /* l_armour_h */


