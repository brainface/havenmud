#include <lib.h>
inherit LIB_SENTIENT;
#include "../jidnewbi.h"

static void create() {
   sentient::create();
   SetProperty("jidnewbinoleave",1);
   SetKeyName("green snake");
   SetShort("a green snake");
   SetId( ({ "snake" }) );
   SetAdjectives( ({ "tree","green" }) );
   SetLong("The tree snake blends in well with the surrounding green.");
   SetGender("male");
   SetRace("snake");
   SetClass("animal");
   SetLevel(2);
   SetWander(22);
}


/* Approved by Zaxan on Sat Jan 17 02:26:36 1998. */
