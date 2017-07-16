#include <lib.h>

inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("frozen beer");
  SetShort("a bottle of frozen beer");
  SetId(({ "beer","bottle" }));
  SetAdjectives( ({ "bottle","of","frozen" }) );
  SetLong(
    "It's some kind of fancy beer, frozen solid. Like, you "
    "could kill someone with this way easier than drink from it. "
    "Like, the polar ice caps will melt before this beer does. Like, "
    "it's... look it's really cold and really frozen and if you tried "
    "to even lick it to get the beer out your tongue would just stick "
    "to it and then people would make fun of you. Also it smells like "
    "flowers for some goddamned reason. Maybe you shouldn't have left "
    "it in the freezer so long? And maybe gotten something to drink "
    "that didn't smell of potpourri?"
  );
}

