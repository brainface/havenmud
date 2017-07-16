#include <lib.h>
#include "ditmar.h"
inherit LIB_LEADER;

int Blah();

static void create() {
   leader::create();
   SetTown("Ditmar");
   SetKeyName("Vanta");
   SetShort("Vanta, the fighter leader");
   SetId( ({ "vanta","fighter","leader","mar","female" }) );
   SetAdjectives( ({ "vanta","fighter","leader","mar","female" }) );
   SetLong("Vanta is a very strong and very courageous mar female.  She stands rather "
           "straight and keeps her muscles tense in continual fear.  Vanta is not "
           "particularly found of the world outside Ditmar, and has proven it on "
           "a number of occasions with unfortunate, young, and unknowning high "
           "mortals from other towns and religions.");
   SetClass("fighter");
   SetLevel(50);
   SetGender("female");
   SetStat("strength",70,1);
   SetRace("mar");
   SetReligion("Marn","Marn");
   SetMorality(-200);
   SetFreeEquip( ([
                    D_OBJ + "/freehack" : 1,
                    D_OBJ + "/freeslas" : 1,
                    D_OBJ + "/freerobe" : 1,
               ]) );
   SetPlayerTitles( ([
                       "mortal" : "the Weak Fighter of Ditmar",
                       "hm" : "the Fighter of Ditmar",
                       "legend" : "the Muscular Fighter of Ditmar",
                       "avatar" : "the Strong",
                       "sorcerer" : "the Wise Fighter",
                       "assassin" : "the Cunning Fighter",
                       "monk" : "the Faithful Fighter",
                  ]) );
   SetEncounter((:Blah:));
   SetInventory( ([
                    D_OBJ + "/robe" : "wear robe",
               ]) );
}

int Blah() {
   object who = this_player();
   object me = this_object();
   if(who->GetReligion() != "Marn" && who->GetRace() !="mar" &&
      who->GetTown() != "Ditmar") {
      if(who->GetLevel() > 24) {
         me->eventForce("!speak in marin Why do all other races, towns, and religions "
            "refuse to pay attention to the fact that I don't like them?");
         me->eventForce("!bump " + who->GetKeyName());
         me->eventForce("!attack " + who->GetKeyName());
         return 100;
      }
      else if(who->GetLevel() < 10) {
         me->eventForce("!speak in marin Little child, I'd suggest finding someplace "
                        "safer to wander through than Ditmar.  The way out is east, "
                        "north, and east until you make it through the gates.");
         me->eventForce("!bump " + who->GetKeyName());
         return 0;
      }
      else {
         me->eventForce("!speak in marin Listen, I don't like those who are citizens " 
                        "here, who aren't Marn by religion, or who aren't mar by "
                        "race.  So if you don't mind, go away and don't come back.");
         me->eventForce("!bump " + who->GetKeyName());
         return 50;
      }
   }
   return 0;
}