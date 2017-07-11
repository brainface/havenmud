/*  A scroll lib */
#include <lib.h>
#include <vendor_types.h>
inherit LIB_ITEM;
int eventRead();
string SetRecipe(string);
string GetRecipe();
private string Recipe = "white linen headband";

static void create() {
  item::create();
  SetKeyName("recipe");
  SetShort("a recipe");
  SetLong("This is a coiled piece of parchment with some kind of recipe on it.");
  SetRead("default", (: eventRead :) );
}

string SetRecipe(string x) {
  Recipe = x;
  SetProperty("history", "This is a recipe for " + Recipe + ".");
  return Recipe;
  }

string GetRecipe() { return Recipe; }

int eventRead() {
  if (this_player()->eventLearnRecipe(GetRecipe())) {
    message("system", 
       "As you read the scroll, you gain knowledge of " + Recipe + ".",
        this_player() );
   eventDestruct();
   return 1;
   }
  message("system",
      "You fail to gain any knowledge from " + GetShort() + ".",
       this_player() );
  return 0;
  }
