#include <lib.h>
#include <vendor_types.h>
inherit LIB_ITEM;

string BlahRead();

static void create() {
   item::create();
   SetKeyName("bottle");
   SetShort("a pale purple bottle");
   SetId( ({ "bottle" }) );
   SetAdjectives( ({ "pale","empty","purple","healing" }) );
   SetLong("The bottle itself is clear, not purple, but the remains of "
           "a deep purple substance have turned it to a pale purple "
           "shade.");
   SetMass(5);
   SetValue(10);
   SetVendorType(VT_TREASURE);
   SetMaterial( ({ "natural" }) );
   SetRead( (: BlahRead :) );
   SetProperty("history","The liquid that used to be inside this bottle "
               "was put together by the Eclatish healers of the "
               "hospital in the WestWood.");
   SetDamagePoints(10);
   SetRepairDifficulty(30);
   SetRepairSkills( ([
                       "natural working" : 8,
                  ]) );
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
