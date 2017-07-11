/*  Lockpicking Functionality 
 *  I can't think of a time when this would NOT be an item
 *  so it gets to inherit LIB_ITEM
 *  Duuktsaryth@Haven
 *  4 March 2000
 */
#include <lib.h>
inherit LIB_ITEM;

int PickBonus;

static void create() {
  item::create();
  AddSave( ({ "PickBonus" }) );
  PickBonus    = 0; 
}

int SetPickBonus(int x) { return (PickBonus = x); }
int GetPickBonus()      { return (PickBonus);     }

mixed indirect_pick_str_on_obj_with_obj() {
  return 1;
}


  
