/* Made by duuk sometime in 2011 and i feel old
 *
 * Mahkefel 2017: added some helper functions.
 *
 */

#include <lib.h>
#include <std.h>
#include <daemons.h>
inherit LIB_DAEMON;

mapping RecipeFiles = ([]);
private mapping Recipes = ([]);

int DEBUG = 0;

void LoadRecipes();

static void create() {
  daemon::create();
  SetNoClean(1);
  LoadRecipes();
}

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
      Recipes[ob->GetRecipe()] = ob;
      RecipeFiles[ob->GetRecipe()] = STD_CRAFTING + "recipes/" + recipe;
      if (DEBUG) debug("Completed Recipe: " + ob->GetRecipe() + " ~~ " + RecipeFiles[ob->GetRecipe()]);
    }
  }		
}

string* GetRecipes() { return keys(Recipes); }

object GetRecipe(string name) {
  if (!Recipes[name]) {
    LoadRecipes(); 
  }
  return Recipes[name];
}

mapping GetRecipeFiles() { return RecipeFiles; }

string GetRecipeFile(string recipe) { 
	if (RecipeFiles[recipe]) return RecipeFiles[recipe];
	return 0;
}
