#include <lib.h>
#include <daemons.h>
string *CraftingRecipes = ({ });

string *AddCraftingRecipes(string *add) {
  if (stringp(add)) add = ({ add });
  CraftingRecipes += add;
  return CraftingRecipes;
}

string *GetCraftingRecipes() {
  return CraftingRecipes;
}

int CanCraft(string recipe) {
  if (member_array(recipe, CraftingRecipes) > -1) return 1;
  return 0;
}

int eventLearnRecipe(string recipe) {
  string file = RECIPES_D->GetRecipeFile(recipe);
  string name = file->GetRecipe();
  int canLearn = 1;
  
  if (file) {
    if (member_array(recipe, this_object()->GetCraftingRecipes()) != -1) {
      this_object()->eventPrint("You already know the recipe for " + name + "!");
      return 0;
    }
    // loop through and report on each requisite skill value
    // note if they can't learn the recipe due to lacking skills
    foreach(string sk, int val in file->GetSkills()) {
      if (this_object()->GetSkillLevel(sk) < val) {
        debug("testing skill: " + sk);
        this_object()->eventPrint("You lack the required skill (" + sk + " : " + val +") to learn this recipe.");
        canLearn = 0;
      } else {
        this_object()->eventPrint("You possess the required skill (" + sk + " : " + val +") to learn this recipe.");
      }
    }
    // return 0 if they were lacking a skill
    if (!canLearn) return 0;
    
    AddCraftingRecipes( ({ recipe }) );
    this_object()->eventPrint("You learn a recipe for " + recipe + ".");
    return 1;
  }
  return 0;
}
                       
