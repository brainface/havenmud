/*mahkefel 2017
 *
 * It's made of people!
 * 's shoes.
 *
 */
#include <lib.h>
#include <std.h>
inherit LIB_RECIPE;

static void create() {
  ::create();
  SetRecipe("boot broth");
  SetCraftedObject(STD_CRAFTING "survival/boot_broth");
  SetCraftingMessage( ({"boil", "$agent_name $agent_verb a leather strip "
    "until it's nice and tender." }) );
  SetMaterials( ([
    "leather strip" : 1,
    ]) );
  SetSkills( ([
    "leather working" : 50,     
  ]) );
}

