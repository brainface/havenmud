#include <lib.h>
inherit LIB_SENTIENT;

static void create() {
   sentient::create();
   SetProperty("jidnewbinoleave",1);
   SetKeyName("dung beetle");
   SetShort("a dung beetle");
   SetId( ({ "beetle" }) );
   SetAdjectives( ({ "dung" }) );
   SetLong("The dung beetle has a plodding, bored look to himself, but "
           "also seems like the sort of thing that would consistantly "
           "do his work.");
   SetRace("insect");
   SetGender("male");
   SetClass("animal");
   SetLevel(1);
  
   SetWander(23);
}


/* Approved by Zaxan on Fri Jan 16 22:54:36 1998. */
