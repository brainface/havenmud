#include <lib.h>
#include <vendor_types.h>
inherit LIB_ITEM;
#include "../ph.h"

string BlahRead();
int life = 2000+random(200);

static void create() {
   ::create();
   SetKeyName("vial");
   SetShort("a blue vial");
   SetId( ({ "vial","glass","bottle" }) );
   SetAdjectives( ({ "blue","small","little","glass" }) );
   SetLong("The blue glass bottle contains little more than a residue of "
           "some clear liquid.  A label on the outside "
           "identifies this liquid.");
   SetMass(5);
   SetValue(30);
   SetVendorType(VT_MAGIC|VT_TREASURE);
   SetMaterial( ({ "natural" }) );
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

void heart_beat(){
   life--;
   if(!life) { eventDestruct(); }
}