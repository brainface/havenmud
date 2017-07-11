#include <lib.h>
#include <std.h>
#include <daemons.h>
inherit LIB_DAEMON;

mapping RecipeFiles;
int DEBUG = 0;

void LoadRecipes() {
    string *recipes = ({ });
	
    RecipeFiles = ([]);
    recipes = get_dir(STD_CRAFTING + "recipes/" + "*.c");
    if (DEBUG) debug("SizeOf Recipes = " + sizeof(recipes));
    foreach(string recipe in recipes) {
      object ob = find_object(STD_CRAFTING + "recipes/" + recipe);
			if (DEBUG) debug("recipe: " STD_CRAFTING + "recipes/" + recipe);
			if( ob ) {
	    	ob->eventDestruct();
			}
  		if (ob = load_object(STD_CRAFTING + "recipes/" + recipe) ) {
	  		RecipeFiles[ob->GetRecipe()] = STD_CRAFTING + "recipes/" + recipe;
	  		if (DEBUG) debug("Completed Recipe: " + ob->GetRecipe() + " ~~ " + RecipeFiles[ob->GetRecipe()]);
			}
		}		
}

mapping GetRecipeFiles() { return RecipeFiles; }

string GetRecipeFile(string recipe) { 
	if (RecipeFiles[recipe]) return RecipeFiles[recipe];
	return 0;
}

static void create() {
	::create();
  RecipeFiles = ([ ]);
  LoadRecipes();
}