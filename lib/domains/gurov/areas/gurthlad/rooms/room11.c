#include <lib.h>
#include "../gurthlad.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  
  SetShort("a shadowed plain");
  SetLong("A dusty, dead plain. Nothing can be seen but the brown "
         "land stretching into the distance. In the semi-darkness "
         "you can see a small hill off to the west. In the ground "
         "all about are some tubers growing.");
  SetObviousExits("north, west");
  SetExits( ([
          "north" : G_ROOMS+"/room12.c",
          "west" : G_ROOMS+"/room10.c",]) );
  SetSmell( ([
          "default" : "A light wind brings the faint smell of death."]) );
  SetListen( ([
          "default" : "A squealing sound can be heard nearby."]) );
  SetItems( ([
          ({ "grass", "dead grass" }) : "Blades of withered dead grass.",
          "dirt" : "Dry, dusty, lifeless, gray dirt.",
          ({ "plain", "land" }) : "A dusty brown plain. Nothing can be "
          "seen but dead grass, dirt, and a hill to the west.",
          "hill" : "A small hill, barely more than a hump in the "
          "flatness.",
          ({ "tuber", "tubers", "plant", "plants", "ground" }) : 
          "There are small brown tuber plants growing out of the ground "
          "all around. These are the plants that Squealers like to eat."]) );
  }
