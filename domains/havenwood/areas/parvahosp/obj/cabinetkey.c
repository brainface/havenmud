#include <lib.h>
#include <vendor_types.h>
inherit LIB_ITEM;
inherit LIB_KEY;

string BlahRead();

static void create() {
   ::create();
   SetKeyName("key");
   SetShort("a brass key");
   SetId( ({ "key" }) );
   SetKeyID("parvahospital_cabinetkey");
   SetAdjectives( ({ "brass" }) );
   SetLong("The brass key has some very small letters engraved in the side.");
   SetValue(5);
   SetMass(1);
   SetDamagePoints(50);
   SetMaterial( ({ "metal" }) );
   SetRepairDifficulty(20);
   SetRepairSkills( ([
                       "metal working" : 1,
                  ]) );
   SetProperty("history","This key was lost in the storage room of the Parva "
               "Hospital for years before it was finally found.  It goes to "
               "various cabinets in the upstairs part of the hospital.");
   SetVendorType(VT_TREASURE);
   SetRead((: BlahRead :));
}

string BlahRead() {
   object who = this_player();
   if((who->GetLanguageLevel("Oiseau") > 70+random(20)) ||
       who->GetLanguageLevel("Enlan") > 70+random(25)) {
      who->eventPrint("The letters on the key read:\n"
             "Storage Cabinets, Parva Hospital");
      return "";
   }
   who->eventPrint("The writing on the key is in a language whose "
                  "writing you do not understand well enough to read.");
   return "";
}
