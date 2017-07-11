/*  A meal object for player shops
 *  Duuktsaryth
 */
#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

private string PLong, PShort, PKeyName, *PId, *PAdjectives;

static void create() {
  meal::create();
  SetMealType(MEAL_FOOD);
  AddSave( ({ "PLong", "PShort", "PKeyName", "PId", "PAdjectives" }) );
  }

string SetShort(string x) { return (PShort= x); }
string GetShort() { return PShort;}
string SetLong(string x) { return (PLong= x); }
string GetLong() { return PLong; }
string SetKeyName(string x) { return (PKeyName= x); }
string GetKeyName() { return (PKeyName); }
string *SetAdjectives(string *x) { return (PAdjectives = x); }
string *GetAdjectives() { return (PAdjectives); }
string *SetId(string *x) { return (PId = x); }
string *GetId() { return (PId); }
