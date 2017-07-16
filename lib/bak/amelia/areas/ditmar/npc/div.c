#include <lib.h>
#include "ditmar.h"
inherit LIB_LEADER;

static void create() {
   leader::create();
   SetTown("Ditmar");
   SetKeyName("Gravisue");
   SetShort("Gravisue, the diviner leader");
   SetId( ({ "gravisue","diviner","leaver" }) );
   SetAdjectives( ({ "gravisue","diviner","leader" }) );
   SetLong("Gravisue is an old and skinny mar diviner.  She was once employed by "
           "Samdar to help him in his research and language studies.  She looks "
           "very aware of the surrounding world and appears to be a highly talented "
           "diviner.");
   SetGender("female");
   SetRace("mar");
   SetClass("diviner");
   SetLevel(50);
   SetFreeEquip( ([
                    D_OBJ + "/freeblun" : 1,
                    D_OBJ + "/freerobe" : 1,
               ]) );
   SetPlayerTitles( ([
                       "mortal" : "the Studying Diviner of Ditmar",
                       "hm" : "the Diviner of Ditmar",
                       "legend" : "the Intelligent Diviner of Ditmar",
                       "avatar" : "the Wise",
                       "gypsie" : "the Cunningly Wise",
                       "oracle" : "the Rich Diviner",
                  ]) );
   SetCurrency("kuique",2030+random(10000));
   SetInventory( ([
                    D_OBJ + "/robe" : "wear robe",
               ]) );
   SetSpellBook( ([
                    "detect good" : 100,
                    "detect evil" : 100,
                    "detect invisibility" : 100,
                    "detect magic" : 100,
                    "telepathy" : 100,
                    "discern location" : 100,
                    "discern morality" : 100,
                    "research history" : 100,
                    "terra" : 100,
                    "fireball" : 100,
                    "aura" : 100,
                    "buffer" : 100,
                    "channeling" : 100,
                    "dispel protections" : 100,
                    "create dark globe" : 100,
                    "wards of protection" : 100,
                    "chill touch" : 100,
                    "ethereal touch" : 100,
               ]) );
   SetMorality(100);
}