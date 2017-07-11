#include <lib.h>
#include "../ph.h"
inherit LIB_STORAGE;

void AddStuff();

static void create() {
   storage::create();
   SetShort("a plain cabinet");
   SetKeyName("cabinet");
   SetId( ({ "cabinet" }) );
   SetAdjectives( ({ "plain" }) );
   SetLong("The cabinet is made of plain wood, and has a small latch to one side "
           "with a lock on it.  It is mounted on the wall.  The lock is made of "
           "brass.");
   SetMass(10);
   SetCanClose(1);
   SetClosed(1);
   SetMaxCarry(90);
   SetPreventGet(1);
   SetLockStrength(40); // GoodStrength?
   SetPick(1);
   AddStuff();
   SetCanLock(1);
   SetLocked(1);
   SetOpacity(100);
   SetKeys( ({ "key","parvahospital_cabinetkey" }) );
   SetDisableChance(100);
}

void AddStuff() {
   if(!random(500)) {
      object blah = new(PO + "/vialdisease_f"); 
      blah->eventMove(this_object());
   }
   if(!random(400)) { object blah2 = new(PO + "/vialsight_f");
      blah2->eventMove(this_object());
   }
   if(!random(500)) { object blah3 = new(PO + "/vialpois_f");
      blah3->eventMove(this_object());
   }
   if(!random(400)) { object blah4 = new(PO + "/viallimb_f");
      blah4->eventMove(this_object());
   }

   

   return;
}
