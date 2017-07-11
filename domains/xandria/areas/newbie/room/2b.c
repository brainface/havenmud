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
    "north and south, as well as east and west."
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
  "path" : ({ "sandy" , "small" }),
  "sand" : ({ "yellow" }),
  "garden" : ({ "public"}),
   "grasses" : ({ "desert" }),
  ]) );
  SetInventory( ([
    NEWBIE_NPC "jackal" : 4,
  ]) );
  SetListen("Wind blows the sand with a whistling sound.");
  SetSmell("The scent of water comes from east and south.");
  SetExits( ([
    "north" : NEWBIE_ROOM "/1b",
    "south" : NEWBIE_ROOM "/3b",
    "east" : NEWBIE_ROOM "/2c",
    "west" : NEWBIE_ROOM "/2a",
  ]) );
}
