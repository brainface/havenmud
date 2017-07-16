#include <lib.h>
#include <meal_types.h>
#include <vendor_types.h>
inherit LIB_MEAL;
#include "../ph.h"

string BlahRead();
int RestoreIt(string limb, array limbs, object who);
int life = 2000+random(200);

static void create() {
   meal::create();
   SetKeyName("vial");
   SetShort("a green vial");
   SetId( ({ "vial","glass" }) );
   SetAdjectives( ({ "glass","green" }) );
   SetLong("The green glass vial is filled with a liquid that shimmers with "
           "intensity.  Writing on the side describes the contents thoroughly.  "
           "The glass is very thick and sturdy.");
   SetMass(5);
   SetValue(900);
   SetVendorType(VT_MAGIC|VT_TREASURE);
   SetMaterial( ({ "natural" }) );
   SetMealType(MEAL_DRINK);
   SetRead( (: BlahRead :) );
   SetProperty("magic","The liquid inside this vial has powers to restore "
               "lost limbs.");
   SetProperty("history","The liquid inside this green vial was blessed by "
               "a specialized group of Eclats in the WestWood, then brought "
               "over to Parva where it would do more good.");
   SetDamagePoints(250);
   SetRepairDifficulty(25);
   SetRepairSkills( ([
                       "natural working" : 2,
                  ]) );
    set_heart_beat(1);
}

string BlahRead() {
   object who = this_player();
   if((who->GetLanguageLevel("Oiseau") > 70+random(20)) ||
       who->GetLanguageLevel("Enlan") > 70+random(25)) {
      who->eventPrint("The label on the vial reads:\n"
             "%^GREEN%^%^BOLD%^**** Limb Restoration ****%^RESET%^");
      return "";
   }
   who->eventPrint("The label on the vial is in a language whose "
                  "writing you do not understand well enough to read.");
   return "";
}   

mixed eventDrink(object who) {
   object blah = new(PO + "/viallimb_e");
   array limbs;
   string limb;
   limbs = who->GetMissingLimbs();
   send_messages(({ "open","drink" }), "$agent_name $agent_verb "
                    "a green vial and $agent_verb the contents.",
                    who, 0, environment(who));
   if (!sizeof(limbs)) {
      message("my_action","The potion seems to have no effect.",who);
      eventDestruct();
      return 0;
   }
   limb = limbs[random(sizeof(limbs))];
   RestoreIt(limb,limbs,who);
   who->RestoreLimb(limb);
   send_messages(({ }),"A shimmering light surrounds $agent_name, " 
                    "blinding those around.  When it fades, "
                    "one of $agent_possessive limbs has returned.",
                    who, 0, environment(who)); 
   who->eventPrint("You feel much better!");
   eventDestruct();
   return 1;
}

int RestoreIt(string limb, array limbs, object who) {
      if(!(who->GetLimb((who->GetMissingLimb(limb))["parent"]))) {
      limbs -= ({ limb });
      limb = limbs[random(sizeof(limbs))];
      RestoreIt(limb,limbs,who);
   }
   return 1;
}

int GetValue() {
   return 900;
}

void heart_beat(){
   life--;
   if(!life) { eventDestruct(); }
}