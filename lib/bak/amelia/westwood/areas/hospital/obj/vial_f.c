#include <lib.h>
#include <meal_types.h>
#include <vendor_types.h>
inherit LIB_MEAL;
#include "hospital.h"

string BlahRead();

static void create() {
   meal::create();
   SetKeyName("vial");
   SetShort("a small vial");
   SetId( ({ "vial","glass","bottle" }) );
   SetAdjectives( ({ "small","little","glass" }) );
   SetLong("The little glass bottle has a small amount of some "
           "clear liquid inside.  A label on the outside probably "
           "identifies this liquid.");
   SetMass(5);
   SetValue(850);
   SetVendorType(VT_MAGIC|VT_TREASURE);
   SetMaterial( ({ "natural" }) );
   SetMealType(MEAL_DRINK);
   SetRead( (: BlahRead :) );
   SetProperty("magic","The liquid inside this small vial has been "
               "given healing properties towards poison.");
   SetDamagePoints(5);
   SetRepairDifficulty(35);
   SetRepairSkills( ([
                       "natural working" : 3,
                  ]) );
}

string BlahRead() {
   object who = this_player();
   if(who->GetLanguageLevel("Oiseau") > 70+random(20)) {
      who->eventPrint("The label on the vial reads:\n"
             "%^BLUE%^**** ANTIDOTE:  POISON ****%^RESET%^");
      return "";
   }
   who->eventPrint("The label on the vial is in a language whose "
                  "writing you do not understand well enough to read.");
   return "";
}   

mixed eventDrink(object who) {
   object blah = new(H_OBJ + "/vial_e");
   if(!(who->GetPoison())) {
      who->eventPrint("But you aren't poisoned!");
      return 1;
   }
   if(who->GetPoison() < 30) {
      who->AddPoison(-(who->GetPoison()));
   }
   else {
      who->AddPoison(-30);
   }
   send_messages(({ "open","drink" }), "$agent_name $agent_verb "
                    "a small vial and $agent_verb the contents.",
                    who, 0, environment(who));
   who->eventPrint("You feel much better!");
   blah->eventMove(who);
   eventDestruct();
   return 1;
}

int GetValue() {
   return 850;
}
