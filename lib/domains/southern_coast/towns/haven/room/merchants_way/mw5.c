//
// Part of Merchant's Way
// Filename: mw5.c
// Created by Duuktsaryth@Haven
// Modified by Kazgaroth@Haven
//

#include <lib.h>
#include "../haven.h"

inherit LIB_ROOM;

static void create() {
   room::create();
   SetShort("Merchant's Way");
   SetExits( ([
      "west" : H_ROOM + "holy_path/hp6",
      "east" : H_ROOM + "merchants_way/mw4",
   ]) );
   SetLong("The road continues to the east and west.  From here, it is "
           "easy to tell that this is the heart of the business district "
           "of Haven Town.  Passersby carry packages and seem intent on "
           "shopping.  To the south is a shop billing as Fidget's Armoury, "
           "which seems to be more than a simple armoury, as wealthy women "
           "come and go out of the building with ease.");
   SetItems( ([
      ({ "heart", "district" }) :
         (: GetLong :),
      ({ "armoury", "shop" }) : 
         "Fidget's Armoury",
      ({ "passerby", "passersby" }) :
         "These passersby are carrying packages and they seem to be "
         "concentrating on shopping.",
      ({ "package", "packages" }) :
         "The people here are walking too fast to be able to make out "
         "what they're carrying.",
      ({ "women" }) :
         "These wealthy women are making their way in and out of Fidget's "
         "Armoury.",
   ]) );
   SetItemAdjectives( ([
      "district" : ({ "business" }),
      "armoury" : ({ "fidget's" }),
      "women" : ({ "wealthy" }),
   ]) );
   SetEnters( ([
      "shop" : H_ROOM + "shops/armoury",
   ]) );
}

/* Approved by Duuktsaryth on Tue Apr 27 21:07:09 1999. */
