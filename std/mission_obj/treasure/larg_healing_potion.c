#include <lib.h>
#include <meal_types.h>
#include <vendor_types.h>

inherit LIB_MEAL;
string ReadMe();

static void create() {
  ::create();
  SetKeyName("potion");
  SetId( ({ "potion", "vial" }) );
  SetShort("a large red potion");
  SetAdjectives( ({ "large", "red" }) );
  SetLong("This is a large vial filled with a red liquid that bubbles"
          " ever so slightly. A small label on the base of the vial"
          " has several languages written upon it.");
  SetRead( (: ReadMe :) );
  SetMass(5);
  SetValue(250);
  SetVendorType(VT_MAGIC|VT_TREASURE);
  SetDamagePoints(15);
  SetMealType(MEAL_DRINK);
  SetMealMessages("$N drink the potion and feel much better.",
                  "$N drinks the potion and begins to look better.");
}

string ReadMe() {
   object who = this_player();
   
   who->eventPrint("As you look at the label you notice a language you are familiar with:\n"
                   "Strong Healing Potion");
   return;
 }

int eventDrink(object who) {
  if ((who->GetHealthPoints()) == (who->GetMaxHealthPoints())) {
     who->eventPrint("It would be a waste to drink this potion when your health"
                     " is already full.");
    return 0;
   }
  who->AddHealthPoints(125);
  return (meal::eventDrink(who));
}
