#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

string Race;

varargs void SetMeat(object);

static void create() {
  ::create();
  AddSave( ({ "Race" }) );
  SetMealType(MEAL_FOOD);
  SetId( ({ "hunk", "meat" }) );
  SetAdjectives( ({ "meat", "hunk", "of", }) );
  SetMass(20);
  SetMealMessages( ({
    "You gnaw on a hunk of meat.",
    "$N gnaws on a hunk of meat.",
  }) );
  SetMeat();
}

varargs void SetMeat(object ob) {
  string r;
  if (ob) {
    Race = ob->GetRace();
  }
  if (Race) r = " " + Race; else r = "";
  SetLong("This is a butchered piece of" + r + " meat.");
  SetShort("a hunk of" + r + " meat");
  if (Race) SetAdjectives(GetAdjectives() + ({ Race })); 
}

string GetRace() { return Race; }