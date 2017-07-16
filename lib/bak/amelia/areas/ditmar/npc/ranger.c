#include <lib.h>
#include "ditmar.h"
inherit LIB_LEADER;

static void create() {
   leader::create();
   SetKeyName("Namime");
   SetShort("Namime the Ranger Leader");
   SetId( ({ "namime","ranger","leader" }) );
   SetAdjectives( ({ "ranger","leader","namime" }) );
   SetLong("Namime is a quiet female mar who has accepted the task of caring for the "
           "flora and fauna of the underground.  She is of average hieght but is quite "
           "strong.  She looks very serious about her job and is probably quite competent "
           "as a ranger.");
   SetGender("female");
   SetClass("ranger");
   SetRace("mar");
   SetLevel(44);
   SetFreeEquip( ([
                    D_OBJ + "/freerobe" : 1,
                    D_OBJ + "/freeslas" : 1,
                    D_OBJ + "/freeproj" : 1,
               ]) );
   SetMorality(500);
   SetPlayerTitles( ([
                       "mortal" : "Botanist of Ditmar",
                       "hm" : "Cave Shadow of Ditmar",
                       "legend" : "Master Scout",
                       "avatar" : "Master Ranger",
                       "nomad" : "Wandering Scout",
                  ]) );
   SetSpellBook( ([
                    "barkskin" : 100,
                    "feast" : 100,
                    "invigorate" : 100,
                    "natural shield" : 100,
                    "mend metal" : 100,
                    "tend wounds" : 100,
                    "transmorph" : 100,
                    "tangle" : 100,
                    "freeze" : 100,
                    "scatter protections" : 100,
                    "summon animal" : 100,
               ]) );
}