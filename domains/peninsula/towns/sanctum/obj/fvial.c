#include <lib.h>
#include <meal_types.h>
#include <vendor_types.h>
inherit LIB_MEAL;

string BlahRead();

static void create() {
   meal::create();
   SetKeyName("fiery vial");
   SetShort("a fiery vial");
   SetId( ({ "vial" }) );
   SetAdjectives( ({ "fiery" }) );
   SetLong("The small vial has a redish liquid in it.  A label on the outside "
           "identifies this liquid.");
   SetMass(5);
   SetValue(550);
   SetVendorType(VT_MAGIC|VT_TREASURE);
   SetMaterial( ({ "natural" }) );
   SetMealType(MEAL_DRINK);
   SetRead( (: BlahRead :) );
   SetDamagePoints(5);
}


string BlahRead() {
   object who = this_player();
   if(who->GetClass() != "rogue" && who->GetClass() != "assassin") {
   who->eventPrint("You can't seem to understand what the label says.");
   return "";
   }
   who->eventPrint("The label on the vial reads:\n"
             "%^BOLD%^%^YELLOW%^**** Pure Caffeine ****%^RESET%^");
      return "";
}
   

mixed eventDrink(object who) {
   send_messages(({ "open","drink" }), "$agent_name $agent_verb "
                    "a fiery vial and $agent_verb the contents.",
                    who, 0, environment(who));
      if(who->GetClass() != "rogue" && who->GetClass() != "assassin") {
      who->AddPoison(50);
      who->eventPrint("You feel ill.");
   eventDestruct();
      return 0;
   }
   if(who->GetCaffeine() > who->GetStatLevel("durability") * 10) {
      who->eventPrint("The potion seems to have no effect.");
      return 0;
   }
     who->AddCaffeine(550);
      send_messages(({}),"$agent_possessive_noun body shakes uncontrollable "
                         "for a moment.",who,0,environment(who));
   eventDestruct();
   return 1;
}
