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
SetShort("a dim red potion"); 
SetAdjectives( ({ "murky", "red" }) );
SetLong("This is a glass vial filled with a dimly glowing red liquid that bubbles"
" ever so slightly. A small label on the base of the vial"          
" has several languages written upon it.");                         
SetRead( (: ReadMe :) );
SetMass(75);
SetValue(2500);
SetStrength(250);
SetVendorType(VT_MAGIC|VT_TREASURE);
SetDamagePoints(15);
SetMealType(MEAL_DRINK);
SetMealMessages("$N drink the potion and feel much better.",
"$N drinks the potion and begins to look better.");
}

string ReadMe() {
object who = this_player();
who->eventPrint("As you look at the label you notice a language you are familiar with:\n"
"Moderate Healing Potion");
return;
}

int eventDrink(object who) {
if ((who->GetHealthPoints()) == (who->GetMaxHealthPoints())) {
who->eventPrint("It would be a waste to drink this potion when your health"
" is already full.");
return 0;
}
who->AddHealthPoints(200);
who->eventDisplayStatus();
return (meal::eventDrink(who));
}

