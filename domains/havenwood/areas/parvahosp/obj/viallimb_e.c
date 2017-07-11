#include <lib.h>
#include <vendor_types.h>
inherit LIB_ITEM;

string BlahRead();
int life = 2000+random(200);

static void create() {
   item::create();
   SetKeyName("vial");
   SetShort("a green vial");
   SetId( ({ "vial","glass" }) );
   SetAdjectives( ({ "green","glass" }) );
   SetLong("The green glass vial contains a slight residue of what "
           "used to be a small amount of liquid.  The vial is "
           "empty now.  There is a label on the outside, "
           "probably identifying what used to be in the vial.");
   SetMass(5);
   SetValue(45);
   SetProperty("history","The liquid inside this green vial was blessed by "
               "a specialized group of Eclats in the WestWood, then brought "
               "over to Parva where it would do more good.");
   SetVendorType(VT_TREASURE);
   SetDamagePoints(275);
   SetRead( (: BlahRead :));
   SetMaterial( ({ "natural" }) );
   SetRepairDifficulty(15);
   SetRepairSkills( ([ 
                       "natural working" : 1,
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

void heart_beat(){
   life--;
   if(!life) { eventDestruct(); }
}