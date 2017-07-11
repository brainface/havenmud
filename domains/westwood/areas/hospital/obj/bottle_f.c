#include <lib.h>
#include <vendor_types.h>
#include <meal_types.h>
inherit LIB_MEAL;
#include "hospital.h"

string BlahRead();

static void create() {
   meal::create();
   SetKeyName("bottle");
   SetShort("a purple bottle");
   SetId( ({ "bottle" }) );
   SetAdjectives( ({ "purple","healing" }) );
   SetLong("The bottle itself is clear, not purple, but a peculiar "
           "liquid inside makes it look like an opaque purple.  "
           "A multi-color flower is drawn on one side of the bottle, "
           "and the other side has some strange writing.");
   SetMass(20);
   SetValue(600);
   SetVendorType(VT_MAGIC|VT_TREASURE);
   SetMaterial( ({ "natural" }) );
   SetMealType(MEAL_DRINK);
   SetRead( (: BlahRead :) );
   SetProperty("magic","The liquid inside this bottle has been given "
                       "general healing properties.");
   SetDamagePoints(10);
   SetRepairDifficulty(30);
   SetRepairSkills( ([
                       "natural working" : 8,
                  ]) );
}

int GetValue() {
   return 600;
}

string BlahRead() {
   object who = this_player();
   if(who->GetLanguageLevel("Oiseau") > 70+random(20)) {
      who->eventPrint("The writting on the bottle reads:\n"
                      "%^MAGENTA%^**** HEALING LIQUID ****%^RESET%^");
      return "";
   }
   who->eventPrint("The writting on the bottle is in a language whose "
                   "writing you do not understand well enough to read.");
}
   
mixed eventDrink(object who) {
   object blah = new(H_OBJ + "/bottle_e");
   who->eventCompleteHeal(250);
   send_messages(({ "open","drink" }), "$agent_name $agent_verb "
                    "a purple bottle and $agent_verb the contents.",
                    who, 0, environment(who));
   who->eventPrint("You feel much better!");
   blah->eventMove(who);
   eventDestruct();
   return 1;
}
