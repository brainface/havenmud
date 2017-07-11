#include <lib.h>
#include <meal_types.h>
#include <vendor_types.h>
inherit LIB_MEAL;
#include "../ph.h"

string BlahRead();
int life = 2000+random(200);

static void create() {
   meal::create();
   SetKeyName("vial");
   SetShort("an orange vial");
   SetId( ({ "vial","glass" }) );
   SetAdjectives( ({ "glass","orange" }) );
   SetLong("The orange glass vial contains some murky, milky colored liquid that "
           "has seperated into two layers--one being clear and the other "
           "being white.  The glass is fairly delicate.");
   SetMass(5);
   SetValue(400);
   SetVendorType(VT_MAGIC|VT_TREASURE);
   SetMaterial( ({ "natural" }) );
   SetMealType(MEAL_DRINK);
   SetRead( (: BlahRead :) );
   SetProperty("magic","The liquid inside this vial has powers to restore "
               "lost sight.");
   SetProperty("history","The liquid inside this orange vial was blessed by "
               "a specialized group of Eclats in the WestWood, then brought "
               "over to Parva where it would do more good.");
   SetDamagePoints(5);
   SetRepairDifficulty(35);
   SetRepairSkills( ([
                       "natural working" : 3,
                  ]) );
  set_heart_beat(1);
}

string BlahRead() {
   object who = this_player();
   if((who->GetLanguageLevel("Oiseau") > 70+random(20)) ||
       who->GetLanguageLevel("Enlan") > 70+random(25)) {
      who->eventPrint("The label on the vial reads:\n"
             "%^ORANGE%^%^BOLD%^**** Sight Restoration ****%^RESET%^");
      return "";
   }
   who->eventPrint("The label on the vial is in a language whose "
                  "writing you do not understand well enough to read.");
   return "";
}   


mixed eventDrink(object who) {
   object blah = new(PO + "/vialsight_e");
   send_messages(({ "open","drink" }), "$agent_name $agent_verb "
                    "an orange vial and $agent_verb the contents.",
                    who, 0, environment(who));
   if(who->GetBlind() < 1) {
      message("my_action","Little changes with the consumption of the "
              "orange liquid.",who);
   }
   else if(who->GetBlind() <50) {
      who->SetBlind(0);
      send_messages(({}),"A bright light surrounds $agent_possessive_noun "
                      "eyes, flashing all colors of the rainbow.", who, 0,
                      environment(who));
   }
   else {
      who->SetBlind(who->GetBlind()-50);
      send_messages(({}),"A bright light surrounds $agent_possessive_noun "
                      "eyes, flashing all colors of the rainbow.", who, 0,
                      environment(who));
   }
   eventDestruct();
   return 1;
}

int GetValue() {
   return 400;
}

void heart_beat(){
   life--;
   if(!life) { eventDestruct(); }
}