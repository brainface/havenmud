//
// A footpath linking to Frostmarches
// by Ranquest@Haven
// Created 27 Nov 1998
//
#include <lib.h>
#include <domains.h>
#include "main.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("at the end of a footpath");
  SetDayLong(
    "Here the path ends abruptly where the road has collapsed and sunk into"
    " some sort of underground passage. The firs around it have been"
    " uprooted recently, as if in a violent storm, and seem to have"
    " loosened the rocky foundations of the footpath, allowing the"
    " rocky ground to drop away into a hole approximately the size of a"
    " house. Loose stones and a few larger boulders form a treacherous"
    " path downwards into the depths of the hole.");
  SetNightLong(
    "The footpath ends here abruptly in a gloomy pit where the footpath"
    " used to be. A group of uprooted trees lay slumped together, casting"
    " eerie shadows upon the crisp fallen snow, and animals seem to skitter"
    " about in the gloom below. The footpath continues back to the west,"
    " and appears to dead-end here in some sort of scree, a rocky slope"
    " downwards. It looks like a storm passed through here not long ago.");
  SetItems( ([
    ({"stones","boulders","stone","boulder","slope","dead-end"}) :
      "The loose stones and boulders form a loose scree, a slippery"
      " slope downwards. However, it looks like it may be climbable.",
    ({"footpath","path","road"}) : 
      "The footpath dead-ends here in a scree, and leads back to the"
      " main road to the west.",
    ({"firs","fir","trees"}) :
      "The firs lie uprooted, giving silent testimony to the strength of"
      " the storm. The branches are starting to lose their needles.",
    ({"branches","branch"}) :
      "The branches of the firs are starting to lose their needles.",
    ({"needles","needle"}) :
      "The fir needles are starting to fall off their branches.",
    ({"treacherous path","path","passage","hole","gloom","pit"}) :
      "The gloom below is too dark to penetrate. However, it should be"
      " possible to enter this hole by climbing down the scree.",
    ({"foundations","earth","ground","marks","covering"}) :
      "Earth lies scattered in a loose covering over the ground.",
    ({"storm"}) : "It looks like the storm occurred quite a while ago."
      " However, the marks of its devastation still remain.",
    ({"shadows","shadow"}) : 
      "The broken branches of the trees sway from side to side, as if"
      " in time to some hidden music.",
    ({"snow"}) :
      "The unbroken snow lies gently upon the ground, like icing on a"
      " cake.",
    ]) );
  SetItemAdjectives( ([
    "scree" : ({"loose","larger","slippery","rocky"}),
    "firs" : "uprooted",
    "passage" : ({"underground","gloomy"}),
    "foundations" : ({"rocky","covering"}),
    "storm" : ({"violent"}),
    "shadows" : "eerie",
    "snow" : ({"crisp","fallen","unbroken"}),
    ]) );
  SetListen( ([
    "default" : "The wind whistles through the fallen branches.",
    ]) );
  SetSmell( ([
    "default" :
      "The crisp chill of the wind brings with it the smell of snow."
    ]) );
  SetClimate("arctic");
  SetDomain("FrostMarches");
  SetAmbientLight(20);
  SetInventory( ([
    RNQ_OBJ + "scree.c" : 1,
    ]) );
  SetExits( ([
    "west" : "/domains/frostmarches/virtual/frostmarchrd/0,12",
    ]) );
}
