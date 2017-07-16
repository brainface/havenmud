#include <lib.h>
#include "ditmar.h"
inherit LIB_LEADER;

static void create() {
   leader::create();
   SetKeyName("Conta");
   SetShort("Conta the Enchanter Leader");
   SetId( ({ "conta","enchanter","leader" }) );
   SetAdjectives( ({ "conta","enchanter","leader" }) );
   SetLong("Conta is the enchanter leader for Ditmar.  She is small in size and very "
           "serious.  She has spent many years studying the arts of enchantment and "
           "has become a strong mage.");
   SetClass("enchanter");
   SetGender("female");
   SetRace("mar");
   SetLevel(50);
   SetFreeEquip( ([
                    D_OBJ + "/freepole" : 1,
                    D_OBJ + "/freerobe" : 1,
               ]) );
   SetPlayerTitles( ([
                       "mortal" : "the Studying Enchanter of Ditmar",
                       "hm" : "the Enchanter of Ditmar",
                       "legend" : "the Powerful Enchanter of Ditmar",
                       "avatar" : "the Creator",
                       "sorcerer" : "the Warlike Enchanter of Ditmar",
                  ]) );
   SetSpellBook( ([
                    "create dark globe" : 100,
                    "create water" : 100,
                    "haste" : 100,
                    "ice ball" : 100,
                    "blindness" : 100,
                    "curse" : 100,
                    "buffer" : 100,
                    "aura" : 100,
               ]) );
}