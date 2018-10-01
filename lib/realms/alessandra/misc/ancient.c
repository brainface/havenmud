#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;
inherit LIB_MEAL;

static void create()
{
  meal::create();
  SetKeyName("whiskey");
  SetId( ({ "bottle", "squeeze bottle", "ancient age"}) );
  SetAdjectives( ({ "squeeze","of","ancient" }) );
  SetShort("a squeeze bottle of ancient age");  
  SetMass(30);
  SetValue(5);
  SetLong("This SQUEEZE bottle full of... whiskey? Sorry, "
    "Kentucky Straight Bourbon Whiskey.. carefully distilled "
    "along the banks of the Kentucky blah blah blah. Point is "
    "it's potent. And cheap. And it doesn't make southerners SOUND "
    "drunk until they've gone through an entire SQUEEZE bottle. "
    "And you assume every Food Lion employee keeps a bottle in his or her back "
    "pocket because OH GOD WHY DO I WORK HERE?!?!");
  SetMealType(MEAL_DRINK | MEAL_ALCOHOL);
  SetStrength(200);
  SetMealMessages("You grimace very stevely as you SQUEEZE whiskey into your mouth.",
                  "The bottle of Ancient Age squeaks like a dog toy as $N drowns in genuine sour mash.");
  SetEmptyName("bottle");
  SetEmptyShort("an empty squeeze bottle");
  SetEmptyLong("This is an empty squeeze bottle that could possible have been a condiment? But smells strongly "
    "of cheap booze and lost dreams.");
}
