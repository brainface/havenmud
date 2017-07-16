// Rewritten by Laoise to actually cure diease, instead of poison
// December 2005

#include <lib.h>
#include <meal_types.h>
#include <vendor_types.h>
#include "../ph.h"

inherit LIB_MEAL;
int life = 2000+random(200);
string BlahRead();

static void create() {
   meal::create();
   SetKeyName("vial");
   SetShort("a yellow vial");
   SetId( ({ "vial","glass" }) );
   SetAdjectives( ({ "glass","yellow"}) );
   SetLong(
     "The yellow glass vial contains an opaque liquid, light in color. "
     "A label on the outside identifies this liquid."
   );
   SetMass(5);
   SetValue(550);
   SetVendorType(VT_MAGIC|VT_TREASURE);
   SetMaterial( ({ "natural" }) );
   SetMealType(MEAL_DRINK);
   SetRead( (: BlahRead :) );
   SetProperty("magic","The liquid inside this small vial has been "
               "given healing properties towards diseases.");
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
             "%^BOLD%^%^BLUE%^**** ANTIDOTE:  DISEASE ****%^RESET%^");
      return "";
   }
   who->eventPrint("The label on the vial is in a language whose "
                  "writing you do not understand well enough to read.");
   return "";
}   

mixed eventDrink(object who) {
   object blah = new(PO + "/vialdisease_e");
   object *germ;
   germ = filter(all_inventory(this_player()), (: $1->GetProperty("germ") :) );

   send_messages(({ "open","drink" }), "$agent_name $agent_verb "
                    "a yellow vial and $agent_verb the contents.",
                    who, 0, environment(who));
   if (!sizeof(germ)) { /* Couldn't find any germs. */
     who->eventPrint("You don't feel much different.");
     return 1;
     }
   if(random(100) > germ[0]->GetCureChance() ) {
      who->eventPrint("The potion seems to have no effect.");
      return 1;
      }
   germ[0]->eventDestruct();
   send_messages(({}),"$agent_possessive_noun body shines with a brilliant, "
                     "holy light.",who,0,environment(who));
   who->eventPrint("You feel much healthier!");
   eventDestruct();
   return 1;
}

int GetValue() {
   return 1100;
}

void heart_beat(){
   life--;
   if(!life) { eventDestruct(); }
}