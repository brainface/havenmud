#include <lib.h>
#include <vendor_types.h>
inherit LIB_ITEM;

string BlahRead();
int life = 2000+random(200);

static void create() {
   item::create();
   SetKeyName("vial");
   SetShort("a orange vial");
   SetId( ({ "vial","glass" }) );
   SetAdjectives( ({ "orange","glass" }) );
   SetLong("The orange glass vial contains the residue of some murky, milky "
           "colored liquid.  The glass is fairly delicate.");
   SetMass(5);
   SetValue(35);
   SetProperty("history","The liquid inside this orange vial was blessed by "
               "a specialized group of Eclats in the WestWood, then brought "
               "over to Parva where it would do more good.");
   SetVendorType(VT_TREASURE);
   SetDamagePoints(15);
   SetRead( (: BlahRead :));
   SetMaterial( ({ "natural" }) );
   SetRepairDifficulty(20);
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
             "%^ORANGE%^%^BOLD%^**** Sight Restoration ****%^RESET%^");
      return "";
   }
   who->eventPrint("The label on the vial is in a language whose "
                  "writing you do not understand well enough to read.");
   return "";
}   

void heart_beat(){
   life--;
   if(!life) { eventDestruct(); }
}