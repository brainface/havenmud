/* Crafting LIB for /lib/livings/crafting.c 
   Modified to include the ability to forget crafting recipes
   changing the CraftingRecipes variable from a str to a map
   2/2/14 Atrus

   This will only handle how the recipes are added and removed 
   from the character, the crafting is handled in the verb and 
   in /lib/special/recipe.c.
*/

#include <lib.h>
#include <daemons.h>

private mapping CraftingRecipes = ([]);

static void SetCraftingRecipes(mapping book) {
    CraftingRecipes = book;
}

string *GetCraftingRecipes() {
        return copy(CraftingRecipes);
}

void ResetCraftingRecipes() {
  CraftingRecipes = ([]);
  debug("All crafting recipes reset in " + base_name(this_object()));
}

int CanCraft(string recipe) {
    if( !CraftingRecipes[recipe] ) {
        return 0;
    }
    return 1;
}

mixed eventLearnRecipe(string recipe) {
    object scroll = RECIPES_D->GetRecipeFile(recipe = lower_case(recipe));
    string name = scroll->GetRecipe();

    foreach(string skill in scroll->GetSkills()) {
        if( recipe->GetRequiredSkill(skill) > this_object()->GetSkillLevel(skill) ) {
                this_object()->eventPrint("You lack the required skill "
                "(" + skill + " : " + recipe->GetRequiredSkill(skill) +") "
                "to learn this recipe.");
            return 0;
        }
    }
    if( !CraftingRecipes[recipe] ) {
        CraftingRecipes[recipe] = 1;
    }
    this_object()->eventPrint("You learn to craft " + recipe + ".");
    return 1;
}

mapping eventForgetRecipe(string recipe) {
        map_delete(CraftingRecipes, recipe);
        return CraftingRecipes;
}
