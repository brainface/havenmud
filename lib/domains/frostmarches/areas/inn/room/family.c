#include "../inn.h"
#include <lib.h>
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("The Innkeeper's room");
  SetAmbientLight(35);
  SetLong("This appears to be the innkeeper's own chambers.  It is furnished "
          "a little bit better than the others.  There is a bathtub, a wood "
          "burning stove that is probably used to do all of the cooking for "
          "the inn, and a large bed in the northwest corner.  There is a "
          "small burn mark on the floor in front of the stove.");
  SetItems( ([ 
             ({ "small burn mark", "small burn", "small mark",
                "burn mark", "burn", "mark" }) :
                "The floor in front of the stove is slightly blackened.  "
                "Most likely, a burning log fell out and sat there for a "
                "while before being noticed.",
             ({ "fairly large bathtub", "large bathtub", "big bathtub",
                "bathtub", "tub" }) :
                "This is a fairly large bathtub, actually big enough for a "
                "decent size person to lie down flat in.",
             ({ "very comfortable bed", "comfortable bed" "large bed",
                "bed" }) :
                "This is the only bed in the inn big enough for two "
                "people.  It looks very comfortable.",
             ({ "tough oak walls", "tough oak wall", "tough walls",
                "tough wall", "oak walls", "oak wall" }) :
                "The walls look quite ordinary.",
             ({ "plank floor", "floor" }) :
                "This is a plank floor.  It seems to have on its surface a "
                "small burn mark.",
             ({ "wood burning stove", "great stove of iron",
                "great iron stove", "iron stove", "stove" }) :
                "Several iron pots lie atop this great stove of iron and a "
                "brick stack reaches up to the ceiling taking all of the "
                "smoke away.",
             ({ "several iron pots", "iron pots", "several pots", "pot",
                "pots", "iron pot", "iron pots" }) :
                "These are iron pots, used to cook meals and heat bath "
                "water.",
             ({ "brick stack", "stack of bricks", "stack of brick",
                "brick", "stack" }) :
                "The stack of bricks is connected to the back of the stove "
                "and is used to carry smoke out of the room through the "
                "ceiling.",
             ({ "smoke" }) : "The smoke can not be seen because it is all "
                "inside the stove or escaping via the stack behind it.",
             ({ "ceiling" }) : "Behold, 'tis a ceiling!",
             ]) );
  SetSmell( ([ 
             "default" : "The scent of burning wood is dominant here."
             ]) );
  SetInventory( ([ I_NPC + "/alana" : 1 ]) );
  SetClimate("indoors");
  SetExits( ([ "south" : I_ROOM + "/hall2" ]) );
}
