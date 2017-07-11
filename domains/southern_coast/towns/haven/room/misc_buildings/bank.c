//
// The Haven Town Bank
// Filename: bank.c
// Created by Duuktsaryth@Haven
// Modified by Kazgaroth@Haven
//

#include <lib.h>
#include "../haven.h"

inherit LIB_ROOM;

static void create() {
   room::create();
   SetClimate("indoors");
   SetAmbientLight(50);
   SetTown("Haven");
   SetShort("Haven Bank");
   SetObviousExits("out");
   SetProperty("no bump",1);
   SetExits( ([
      "out" : H_ROOM + "imperial_road/ir4",
   ]) );
   SetLong("The Bank of Haven is a clean, efficient place that "
           "conducts business around the clock.  The windows of the "
           "lendinghouse are lined up in a smart manner that allows "
           "the many patrons of the bank to perform their transactions "
           "with the speed and courtesy they deserve. ");
   SetItems( ([
      ({ "bank of haven", "bank", "leadinghouse" }) : 
         (: GetLong :),
      ({ "window", "windows" }) :
         "The row of teller windows are all clear and look freshly "
         "washed. ",
      ({ "patron", "patrons" }) :
         "The many patrons of this bank have found it a great place "
         "to keep their funds.",
   ]) );
   SetItemAdjectives( ([
      "bank" : ({ "haven" }),
      "window" : ({ "teller", "clear", "freshly washed", "washed" }),
   ]) );
   SetInventory( ([
      H_NPC "ilian" : 1,
   ]) );
}

/* Approved by Duuktsaryth on Tue Apr 27 21:08:44 1999. */
