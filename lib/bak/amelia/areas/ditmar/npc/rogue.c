#include <lib.h>
#include "ditmar.h"
inherit LIB_LEADER;

void eventSteal();

static void create() {
   leader::create();
   SetTown("Ditmar");
   SetKeyName("Tobor");
   SetShort("Tobor the Stealthy");
   SetId( ({ "tobor","stealthy","rogue","leader" }) );
   SetAdjectives( ({ "stealthy","rogue","leader" }) );
   SetLong("Tobor the Stealthy is the resident rogue leader.  Some citizens of Ditmar "
           "still feel a little nervous around him, though he has tried to convince "
           "them over and over again that he only steals from foreigners.  The local "
           "diviner has taught him and most of the other staple citizens how to detect "
           "foreigners.  Tobor is small in size and very skinny; sometimes he seems "
           "to be just a shadow hiding in the corner.");
   SetClass("rogue");
   SetLevel(33);
   SetRace("mar");
   SetGender("male");
   SetFreeEquip( ([
                    D_OBJ + "/freerobe" : 1,
                    D_OBJ + "/freeknif" : 2,
               ]) );
   SetPlayerTitles( ([
                       "mortal" : "Pilferer of Ditmar",
                       "hm" : "Thief of Ditmar",
                       "legend" : "Escape Artist of Ditmar",
                       "avatar" : "Dagger of the Night",
                       "assassin" : "",
                       "pirate" : "",
                       "shadow mage" : "",
                       "gypsie" : "",
                  ]) );
   SetMorality(-504);
   SetAction(90, (: eventSteal :) );
}

void eventSteal() {
   object me = this_object();
   object array ppls = all_inventory(environment(me));
   me->eventForce("!blah");
   foreach(object prsn in ppls) {
      if(prsn->GetReligion() == "Marn") ppls -= ({ prsn });
      if(prsn->GetTown() == "Ditmar") ppls -= ({ prsn });
      if(prsn->GetRace() == "mar") ppls -= ({ prsn });
      if(!living(prsn)) ppls -= ({ prsn });
   }
   if(sizeof(ppls)) {
      me->eventForce("!steal money from " + ppls[random(sizeof(ppls))]->GetKeyName());
      me->eventForce("!emote whistles a little ditty.");
   }
   return;
}