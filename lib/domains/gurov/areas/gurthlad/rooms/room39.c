#include <lib.h>
#include "../gurthlad.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  
  SetShort("entrance to Human camp on a shadowed plain.");
  SetLong("This is the entrance to a human camp, this is the forward exploration "
          "base of the human expedition. There is a large camp fire to the west, "
          "a small tent to the north, and several more tents on the other side "
          "of the fire pit.");
          SetObviousExits("east, west");
  SetExits( ([
          "west" : G_ROOMS + "/room38",
          "east" : G_ROOMS + "/room40"]) );
  SetSmell( ([
          "default" : "A light wind brings a strong smell of wood smoke."]) );
  SetListen( ([
          "default" : "Talking in the human language can be heard nearby."]) );
  SetItems( ([
          "plain" : "The dead land stretches away as far as the eye can see.",
          ({ "camp", "base", "expedition" }) : "This is the forward base for "
          "one of the human exploration "
          "armies. It is layed out in a typical patern, with a central fire "
          "and tents circling it.",
          "entrance" : "A open place in the circle of tents.",
          "fire" : "A large camp fire made out of fallen branches.",
          ({ "four tents","tent", "tents" }) : "Large cabin style tents aranged around "
          "the central fire area. There is a brown tent to the north and "
          "three more tents off to the west.",
          ({ "brown tent","tent" }) : "A large cabin style tent. It is worn, faded and "
          "patched. It looks like you can enter it."]) );
  SetEnters( ([ "brown tent" : G_ROOMS + "/room30"]) );
  SetInventory( ([ G_NPC + "/human_explr" : 2 ]) );
  }

