#include <lib.h>
inherit LIB_NPC;
#include "../jidnewbi.h"

static void create() {
   string DRYAD_GENDER;
   npc::create();
   SetProperty("jidnewbinoleave",1);
   switch(random(2)) {

      case 0:
      DRYAD_GENDER = "male";
      SetLong("The male dryad seems to want to protect his tree from "
              "intruders.");
      break;

      case 1:
      DRYAD_GENDER = "female";
      SetLong("The female dryad seems to want to protect her tree from "
              "intruders.");
      break;
   }
   SetKeyName("dryad");
   SetId( ({ "dryad" }) );
   SetShort("a " + DRYAD_GENDER + " dryad");

   SetAdjectives(DRYAD_GENDER );
   SetGender(DRYAD_GENDER);
   SetRace("dryad");
   SetClass("rogue");
   SetLevel(3+random(3));
   SetInventory( ([
      JD_OBJ + "/glove" : 1,
      JD_OBJ + "/glove2" : 1,
      ]) );
  SetFirstCommands( ({
    "wear first glove on right hand",
    "wear first glove on left hand",
  }) );
}


/* Approved by Zaxan on Sat Jan 17 02:19:16 1998. */
