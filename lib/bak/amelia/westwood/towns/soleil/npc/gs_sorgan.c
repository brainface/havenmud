#include <lib.h>
#include <vendor_types.h>
inherit LIB_VENDOR;
#include "../soleil.h"

static void create() {
   vendor::create();
   SetProperty("soleilnoleave",1);
   SetKeyName("Sorgan");
   SetShort("Sorgan");
   SetId( ({ "sorgan" }) );
   SetAdjectives( ({ }) );
   SetLong("Sorgan smiles at the world around him, happy in his "
           "occupation as the general store keeper for Soleil.  "
           "He doesn't have his own store, but resides within the "
           "bakery with Dulcae, the baker, usually.");
   SetGender("male");
   SetLevel(17);
   SetRace("muezzin");
   SetClass("valkyr");
   SetSkill("bargaining",2);
   SetVendorType(VT_ALL);
   SetLocalCurrency("cuicui");
   SetStorageRoom(S_NPC + "storage_sorgan");
   SetMaxSingleItem(9);
   SetMorality(150);
   SetReligion("Eclat","Eclatish");
   SetFriends( ({ "Dulcae","Tia","Aegri Portare","Alamus","cemetary worker",
                  "Soleil citizen","Oppugno","shaggy dog",
                  "entrance guard","Iuvo","Fossis","Kiee","Miserum" }) );
}
