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
   SetShort("a blue vial");
   SetId( ({ "vial","glass","bottle" }) );
   SetAdjectives( ({ "blue","small","little","glass" }) );
   SetLong("The little blue glass bottle has a small amount of some "
           "clear liquid inside.  A label on the outside "
           "identifies this liquid.");
   SetMass(5);
   SetValue(550);
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
   SetProperty("history","Amelia, the Goddess of Goodness, blessed the "
               "liquid in this vial so that it might be used for "
               "healing.  She gave it to a group of clerics who "
               "specialized in healing.  The group then travelled to Parva.");
   set_heart_beat(1);
}

string BlahRead() {
   object who = this_player();
   if((who->GetLanguageLevel("Oiseau") > 70+random(20)) ||
      (who->GetLanguageLavel("Enlan") > 70+random(25))) {
      who->eventPrint("The label on the vial reads:\n"
             "%^BOLD%^%^BLUE%^**** ANTIDOTE:  POISON ****%^RESET%^");
      return "";
   }
   who->eventPrint("The label on the vial is in a language whose "
                  "writing you do not understand well enough to read.");
   return "";
}   

mixed eventDrink(object who) {
   object blah = new(PO + "/vialpois_e");
   send_messages(({ "open","drink" }), "$agent_name $agent_verb "
                    "a blue vial and $agent_verb the contents.",
                    who, 0, environment(who));
   if(!(who->GetPoison())) {
      who->eventPrint("The potion seems to have no effect.");
   }
   if(who->GetPoison() < 30) {
      who->AddPoison(-(who->GetPoison()));
      send_messages(({}),"$agent_possessive_noun body shines with a brilliant, "
                         "cleansing light.",who,0,environment(who));
      who->eventPrint("You feel much better!");
   }
   else {
      who->AddPoison(-30);
      send_messages(({}),"$agent_possessive_noun body shines with a brilliant, "
                         "cleansing light.",who,0,environment(who));
      who->eventPrint("You feel much better!");
   }
   eventDestruct();
   return 1;
}

int GetValue() {
   return 550;
}

void heart_beat(){
   life--;
   if(!life) { eventDestruct(); }
}