#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;
inherit LIB_READ;
#include "ditmar.h"

string Blah();

static void create() {
   meal::create();
   SetKeyName("bucket");
   SetShort("a small bucket");
   SetId( ({ "bucket" }) );
   SetAdjectives( ({ "small" }) );
   SetLong("The bucket is filled with the cool, clear water of the "
           "Ditmar Falls.  A chain has been attached to it and "
           "holds it near the ground.  It would be possible to "
           "lift it high enough to easily drink from it, however.  "
           "Both chain and bucket are made of some kind of stone.  "
           "Some small writting is on the chain.");
   SetPreventGet("The bucket is securely attached to the ground by a "
                 "chain.");
   SetEmptyItem(D_OBJ + "/wbucket");
   SetStrength(50);
   SetMealType(MEAL_DRINK);
   SetMealMessages("You drink from the bucket's cool water.",
                   "$N drinks from a bucket.");
   SetMaterial( ({ "stone" }) );
   SetRead( (: Blah :) );
}

string Blah() {
   object guy;
   if(guy->GetLanguageLevel("Marin") > 70 +random (10) ) {
      guy->eventPrint("The writting on the chain reads:\n"
                      "%^ORANGE%^PROPERTY OF DITMAR%^RESET%^\n"
                      "(made in keryth)");
      return "";
   }
   guy->eventPrint("The writting on the chain is in a language you "
                   "don't understand well enough to read.");
   return "";
}