#include <lib.h>
#include "parva.h"
inherit LIB_MAYOR;

static void create() {
   mayor::create();
   SetProperty("parvanoleave",1);
   SetKeyName("Samson");
   SetShort("Samson, the Parva Mayor");
   SetId( ({ "samson","mayor" }) );
   SetAdjectives( ({ "samsom","parva","mayor","the" }) );
   SetLong("Samson is the mayor of Parva.  He keeps the town "
           "board clean, runs town meetings, and transfers the "
           "citizenship of those wishing to join Parva.  He is "
           "short, just a little more than five feet in hieght, "
           "and his facial features dance with his arms while " 
           "he moves and talks.");
   SetRace("human");
   SetGender("male");
   SetClass("rogue");
   SetLevel(15);
   SetTown("Parva");
   SetTax(15);
   SetLocalCurrency("oros");
   SetMorality(100);
   SetInventory( ([
                    P_OBJ + "/boots_mayor" : "wear boots",
                    P_OBJ + "/belt_mayor" : "wear belt",
                    P_OBJ + "/pants_mayor" : "wear pants",
                    P_OBJ + "/shirt_mayor" : "wear shirt",
               ]) );
   SetAction(5, ({ "!speak We're a great town!  "
                   "And we listen to everyone's opinion!  "
                   "Join up, just costs a few oros!",
                   "!speak Request citizenship from me and "
                   "the citizens of Parva will be able "
                   "to help you better." }) );
   SetCombatAction(10, ({ "!yell Help!  Help me!","!yell Help me!  "
                    "I'm being attacked!","!yell Help!",
                    "!yell Fellow citizens, come to the aid of "
                    "your mayor!","!speak This is a blasphemous "
                    "crime!  Get away from me, you evil creature!",
                    "!speak Stop this!","!speak Help me!","!speak "
                    "Get out!","!speak Leave Parva now!" }) );
}