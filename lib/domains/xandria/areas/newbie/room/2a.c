//Selket@Haven
//2006
#include <lib.h>
#include "../newbie.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("a sandy clearing");
  SetClimate("arid");
  SetLong(
    "There are no trees here, merely waving desert grasses "
    "and flowing dunes of yellowy sand, which is marked "
    "here and there with jackal tracks. The path leads both "
    "north and south, as well as to the east. "
  );
  SetItems( ([
    "garden" : "This is a public garden, complete with "
    "animals and various plants.",
    ({ "sand", "path" }) : 
    "The sandy path seems to be less used the further you "
    "move from the city.",
    "clearing" : "The clearing is a rolling expanse of sand dunes "
    "and patches of yellowing grasses.",
    "tracks" : "The canine tracks are large, some of them fresh.",
    ({ "grass", "grasses" }) : 
    "These grasses are resilient, requiring little water "
    "to sustain them. They bend in the wind without breaking. ",
    ({ "dunes", "sand" }) : 
    "the sand is dotted with animal tracks. It seems that "
    "jackals frolic here, hunting out snakes in the sand. ",
  ]) );
  SetItemAdjectives( ([
  "path" : ({ "sandy", "small" }),
  "sand" : ({ "yellow" }),
  "garden" : ({ "public" }),
   "grasses" : ({ "desert" }),
  ]) );
  SetInventory( ([
    NEWBIE_NPC "jackal" : 2,
  ]) );
  SetListen("Wind blows the sand with a whistling sound.");
  SetSmell("It smells faintly of dogs.");
  SetExits( ([
    "north" : NEWBIE_ROOM "/1a",
    "south" : NEWBIE_ROOM "/3a",
    "east" : NEWBIE_ROOM "/2b",
  ]) );
}
