// mahkefel 2011
// weak shop potion.
// largely Melchezidek's potions,
//   except with a AddDrink to keep someone
//   from spamming it too much.
#include <lib.h>         
#include <meal_types.h>  
#include <vendor_types.h>

inherit LIB_MEAL;
string ReadMe(); 

static void create() {
::create();         
SetKeyName("potion");
SetId( ({ "potion", "vial" }) );
SetShort("a murky blue potion");
SetAdjectives( ({ "murky", "blue" }) );
SetLong("This is a glass vial filled with a murky blue liquid that bubbles"
" ever so slightly. A small label on the base of the vial"
" has several languages written upon it.");
SetRead( (: ReadMe :) );
SetMass(50);
SetStrength(50);
SetValue(100);
SetVendorType(VT_MAGIC|VT_TREASURE);
SetDamagePoints(15);
SetMealType(MEAL_DRINK);
SetMealMessages("$N drink the potion and feel much better.",
"$N drinks the potion and begins to look better.");
}

string ReadMe() {
object who = this_player();

who->eventPrint("As you look at the label you notice a language you are familiar with:\n"
"Weak Mana Potion");
return;
}

int eventDrink(object who) {
if ((who->GetMagicPoints()) == (who->GetMaxMagicPoints())) {
who->eventPrint("It would be a waste to drink this potion when your mana"
" is already full.");
return 0;
}
who->AddMagicPoints(50);
who->eventDisplayStatus();
return (meal::eventDrink(who));
}

