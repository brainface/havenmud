// Changed to a universal eclat cleric trainer Feb. 19th 2014 Torak
// made it remove projectile combat from updated eclat priests 2017 mahk

#include <lib.h>
#include <daemons.h>
#include <dirs.h>
inherit LIB_LEADER;
#include "../monastery.h"

static void create() {
   leader::create();
   SetTown("all");     
//   SetTown("Soleil");
   SetProperty("monasterynoleave",1);
   SetKeyName("young unicorn");
   SetShort("a young unicorn");
   SetId( ({ "unicorn" }) );
   SetAdjectives( ({ "young" }) );
   SetLong("The unicorn has big, sad eyes that speak of how his "
           "mother was killed and he wandered, sick, until taken "
           "in to this garden.  He is healthy and strong, now, but "
           "still young and limber.");
   SetRace("unicorn");
   SetGender("male");
   SetClass("priest");
   SetReligion("Eclat");
   SetGlobalLeader(1);
   SetUniqueSkills( ([
     "melee combat" : 1,
     "projectile combat" : 0,
   ]) );
   SetPlayerTitles( ([
     "newbie"    : "the Helpful",
     "mortal"    : "the Kind",
     "hm"        : "the Joyful",
     "legend"    : "the Blessed",
     "avatar"    : "Pious $N the Innocent",
     "fighter"   : "Oathbound $N the Guardian of the Weak",
     "bard"      : "Chorist $N the Trumpet of the Heart",
     "cavalier"  : "Holy $N the Defender of the Meek",
     "charlatan" : "$N the Thief of the Mighty",
   ]) );
   SetLevel(50);
   SetMorality(1500);
}

void eventDie(object killer) {
   object horn;
  object ogre_inv;
  if(!random(400)) {
    ogre_inv = new(DIR_INVASIONS + "/soleil_ogre/ois_inv");
    INVASION_D->eventRegisterInvasion(ogre_inv, killer);
  }
   horn = new(M_OBJ + "horn");
   horn->eventMove(this_object());
   ::eventDie(killer);
}

