/* /lib/items/burn.c
 * A new lib file to control all things that burn
 * which can give off heat and light. Much cleaner
 * than the idiotic torch code shipped with NMIVr5
 * Duuk@Haven 10/23/2007
 */
#include <lib.h>

inherit LIB_LIGHT;
inherit LIB_ITEM;

private int Fuel = -1;
private int MaxFuel;
private int Refillable;
private string FlickerString;
private int Heat;


static void create() {
  light::create();
  item::create();
  AddSave( ({ "Fuel" }) );
  set_heart_beat(60);
}

int SetMaxFuel(int x) { return MaxFuel = x; }
int GetMaxFuel()      { return MaxFuel;     }
int GetFuel()         { if (Fuel == -1) Fuel = MaxFuel; return Fuel; }
int SetFuel(int x)    { return Fuel = x;    }
int GetBurning()      { return GetLit();    }
int SetHeat(int x)    { return Heat = x;    }
int GetHeat() {
  if (GetBurning()) return Heat;
    else return 0;
}
int SetRefillable(int x) { return Refillable = x; }
int GetRefillable()      { return Refillable; }
string SetFlickerString(string str) { return FlickerString = str; }
string GetFlickerString()  { return FlickerString; }
int GetRadiantLight() {
  if (GetBurning()) {
    return item::GetRadiantLight();
    }
  return 0;
}

int eventBurn() {
  object env = environment();
  object room;
  
  if (!env) {
    eventDestruct();
    return -1;
  }
  room = environment(env);
  if (GetFuel() == -1) SetFuel(GetMaxFuel()); 
  Fuel--;
  if (Fuel > 0) {
    if (FlickerString) {
     if (room) env->eventPrint("Your " + GetKeyName() + " " + FlickerString + ".");
      else env->eventPrint(capitalize(GetShort()) + " " + FlickerString + ".");
     if (room) room->eventPrint(possessive_noun(env) + " " + GetKeyName() + " " + FlickerString + ".", ({ env }));
     }
    } else {
    eventDarken();
  }
  return 1;
}

mixed CanLight(object who) {
  if (GetFuel() == 0) {
    return capitalize(GetShort()) + " is fully spent.";
  }
  return light::CanLight(who);
}

mixed eventShow(object who, string comp) {
  int p; mixed s;
  if (comp) return item::eventShow(who, comp);
  p = (GetFuel() * 100)/MaxFuel;
  item::eventShow(who, comp);
  who->eventPrint(capitalize(GetShort()) + " is still " + p + "% usable.");
  return 1;
}

string GetShort() {
  return item::GetShort() + light::GetShort();
}

void heart_beat() {
  if (GetLit()) eventBurn();
}