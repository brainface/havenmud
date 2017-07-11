

#include <lib.h>
#include "../durgoroth.h"

inherit LIB_ROOM;

int BankExit(string dir);

static void create() {
   room::create();
   SetClimate("indoors");
   SetAmbientLight(50);
   SetTown("Durgoroth");
   SetShort("the Durgoroth Bank");
   SetExits( ([
     "out" : DURG_ROOM "road07"
      ]) );
   SetLong("Every inch of this building is covered in"
           " debris and dirt. Despite the semi-coherent"
           " appearance given off by the outside of this"
           " building, it's obvious that the inside"
           " is inhabited by followers of Taigis, for"
           " everything is in disarray.");
   SetItems( ([
      ({ "bank" }) : 
         (: GetLong :),
      ({ "debris", "floor", "dirt" }) :
         "The floor and even parts of the walls are covered"
         " in debris and dirt.",
   ]) );
   SetInventory( ([
      DURG_NPC "banker" : 1,
   ]) );
}

int BankExit(string dir) {
  if(this_player()->GetReligion() != "Saahagoth") {
   message("system", "%^CYAN%^You return to your normal state"
                     " upon exiting the bank%^RESET%^", this_player());
   return 1;
   }
   message("system", "%^RED%^%^BOLD%^Rage consumes you once more"
                     " as you exit the bank.%^RESET%^", this_player());
   return 1;
}


