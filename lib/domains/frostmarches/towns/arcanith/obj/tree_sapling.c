/* sapling - made by Sardonas */

#include <lib.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("sapling");
  SetId( ({ "sapling" }) );
  SetAdjectives( ({ "odd", "silver" }) );
  SetShort("an odd looking sapling");
  SetLong("The small sapling struggles to survive in this enviroment.  The "
          "sapling is silver with a few pale blue leaves.  It looks like "
          "it's been well watered and tended.");
  SetProperty( "history", "This is the last Aster.  It's a magical tree "
                          "that was almost lost to the world.  The tree "
                          "was created during the Golden Age of Arcanith as "
                          "an example of how magic could be used to help "
                          "life when used in a peaceful manner.  After "
                          "Arcanith fell the tree was almost harvested "
                          "into extinction, as the wood makes some of the "
                          "world's most powerful enchanted staves.  This "
                          "was found by Kara and tended by her, in order "
                          "to save the species.");
  SetProperty( "magic", "The magic imbued in the sapling causes many mysterious "
                        "effects.  The wood of the tree holds enchantment "
                        "well and strengthens the magic cast upon it.");
                        
  SetPreventGet("The roots of the tree hold this plant in place!");
}
