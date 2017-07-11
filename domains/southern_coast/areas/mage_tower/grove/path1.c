/*  The second path room (after the entrance)
 *  One more after this one to the tower.
 */
#include "../mage_tower.h"
inherit LIB_GROVE;
varargs mixed eventDig(string what, object who);
int BeenDug;

static void create() {
  ::create();
  BeenDug = 0;
  SetClimate("arctic");
  SetShort("along the path to the tower");
  SetExits( ([
    "south" : "entrance",
    "north" : "path2",
    ]) );
  SetLong("The path continues to the north and south from here, "
          "with the tower looming like a menacing terror to the "
          "north. Off to the south the Imperial Road beckons "
          "like a warm comfort beckoning the weary to safety. "
          "The dead and decaying trees line up along the path "
          "leading north like rows upon rows of soldiers "
          "guarding the way to the mysterious tower. "
          "The earth surrounding the path seems especially "
          "worn and beaten down.");
  SetSmell( ([
    "default" : "The scent of death and rot fills the air.",
    ]) );
  SetListen( ([
    "default" : "The wind shrieks through the trees, warding "
                "off the weak.",
    ]) );
  SetItems( ([
    ({ "tree", "trees" }) : "The trees are dead and decaying "
                            "things from long ago.",
    ({ "tower" }) : "The tower stands like a black monolith, "
                    "giving off its evil aura of doom.",
    ({ "ground", "earth", "path" }) : "The earth around the "
                    "path seems almost begging to be dug up.",
    ]) );
  SetInventory( ([
    TOWER_NPC "wraith" : 3,
    ]) );
}

varargs mixed eventDig(object who, string what) {
  object key = new(TOWER_OBJ "key35");

  if (!key) return "Digging doesn't reveal anything.";
  if (BeenDug) return "The earth looks freshly turned like "
                 "someone has already dug here.";
  send_messages( ({ "dig", "bend" }),
    "$agent_name $agent_verb into the ground and then "
    "$agent_verb over to pick something up.",
    who, 0, environment(who) );
  key->eventMove(who);
  message("action", "You uncover a key buried in the ground.",
      this_player() );
  return 1;
}
