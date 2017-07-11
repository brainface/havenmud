
/* a room in the kingdom
   Elasandria 4/15/98
*/
#include <lib.h>
#include "../kingdom.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("a clearing");
  SetDomain("FrostMarches");
  SetClimate("temperate");
  SetLong(
    "The trees become less dense through here. A few hardy toadstools "
    "and numerous ferns cover the forest floor. The surrounding forest "
    "seems to subtly shift and change. Two large oaks dominate the area."
  );
  SetItems( ([
    ({"ancient tree","growth","tree","trees"}) : "The trees are obviously "
      "ancient due to their impressive size.",
    ({"hardy mushroom","mushroom","toadstool","toadstools","mushrooms"}) : 
      "The mushrooms are unnaturally large and vividly colored.",
    ({"lush plant","plant","plants","fern","ferns"}) : "These plants are "
      "very lush and green.",
    ({"area","clearing","forest"}) : "The forest surrounding this serene "
      "little clearing seem to have the uncanny ability to shift and change "
      "as if it were an illusion.",
    ({"north oak","oak"}) : "This tree is completely covered with a soft "
      "blue-green moss and tendrils of dangling vines. The vines delicately "
      "veil a dark entryway.",
    ({"west oak","oak"}) : "This rustic tree is very gnarled with rough bark "
      "and creeping roots. A large opening at its base is dark with shadows.",
    ({"soft moss","moss","tendril","tendrils"}) : "This beautifully "
      "colored moss blankets the entryway.",
    ({"large opening","opening","trunk"}) : "A large opening in the trunk of "
      "the oak looks dark and mysterious.",
    ({"dark entryway","entryway","trunk"}) : "The dark entryway looks well " 
      "kept and intriguing.",
    ({"green vine","vine","vines"}) : "Deep green vines hang curtain-like over "
      "the entryway.",
    ({"shadow","shadows"}) : "The opening is dark except for a faint inner "
      "glow deep within.",
    ({"faint light","light","glow"}) : "A very faint light shines deep within "
      "the depths of the oak.",
    ({"knotted root","root","roots"}) : "The roots are knotted and uneven as "
      "they creep over the floor.",
    "floor" : "The forest floor is slightly damp.",
    "bark" : "The bark is roughly textured.",
    ]) );
  SetItemAdjectives( ([
    "knotted root" : "uneven",
    "large opening" : ({"dark","mysterious"}),
    "green vine" : "dangling",
    "soft moss" : "blue-green",
    "lush plant" : "green",
    "hardy mushroom" : "large",
  ]) );
  SetSmell( ([
    "default" : "A damp, earthy smell lingers here.",
  ]) );
  SetListen( ([
    "default" : "The sound of gently rustling leaves can be heard.",
  ]) );
  SetInventory( ([
  ]) );
  SetExits( ([
    "south" : KINGDOM_ROOMS + "kingdom15",
    "southwest" : KINGDOM_ROOMS + "kingdom14",
  ]) );
  SetEnters( ([
    ({"north oak"}) : KINGDOM_ROOMS + "kingdom5",
    ({"west oak"}) : KINGDOM_ROOMS + "kingdom9",
   ]) );
}
