#include <lib.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
   item::create();
   SetKeyName("vial");
   SetShort("a small vial");
   SetId( ({ "vial","bottle","glass" }) );
   SetAdjectives( ({ "small","little","glass" }) );
   SetLong("The small glass bottle shows the existance of "
           "a clear residue on the inside, but not enough to "
           "use for anything.  There is a label on the outside, "
           "probably identifying what used to be in the vial.");
   SetMass(5);
   SetValue(45);
   SetProperty("history","This vial used to contain an antidote for "
               "poison to be used by the Eclatish healers in the "
               "hospital in the WestWood.");
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

