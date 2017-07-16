#include <lib.h>
#include <vendor_types.h>
inherit LIB_ITEM;
inherit LIB_KEY;

string BlahRead();

static void create() {
   ::create();
   SetKeyName("key");
   SetShort("a yellow key");
   SetId( ({ "key" }) );
   SetKeyID("parvahospital_storagekey");
   SetAdjectives( ({ "yellow" }) );
   SetLong("The key has some writing on the side in yellow, and edges are all "
           "painted yellow, as well.");
   SetValue(3);
   SetMass(1);
   SetDamagePoints(70);
   SetMaterial( ({ "metal" }) );
   SetRepairDifficulty(15);
   SetRepairSkills( ([
                       "metal working" : 1,
                  ]) );
   SetProperty("history","This key belongs to one of the many workers in the "
               "Parva Hospital.  It goes to the hatch to the storage room.");
   SetVendorType(VT_TREASURE);
   SetRead((: BlahRead :));
}

string BlahRead() {
   object who = this_player();
   if((who->GetLanguageLevel("Oiseau") > 70+random(20)) ||
       who->GetLanguageLevel("Enlan") > 70+random(25)) {
      who->eventPrint("The letters on the key read:\n"
             "Basement Storage Room Hatch, Parva Hospital");
      return "";
   }
   who->eventPrint("The writing on the key is in a language whose "
                  "writing you do not understand well enough to read.");
   return "";
} 
