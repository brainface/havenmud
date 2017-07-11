#include "path.h"
#include <lib.h>
inherit LIB_ROOM;
static void create () {
    room::create();
    SetShort("inside a large tent");
    SetLong("This tent was set up quickly in the middle of a huge mud puddle, "
          "so the poles are wobbly and the ground is wet.  The second portion "
          "of the tent is off to the west.  The ceiling and walls are dripping "
          "with rainwater.");
    SetItems( ([
          ({ "mud puddle", "puddle", "mud" }) :
          "The mud puddle composes the entire floor of the tent.",
          ({ "large tent", "tent" }) :
          "The tent is huge, but the ceiling and walls are sagging from the "
          "wobbly poles.",
          ({ "walls", "wall" }) :
          "The walls of the tent are sagging into the mud because of the "
          "akward positioning of the poles.",
           ({ "rainwater", "water" }) :
          "The water drips slowly down the sides of the tent, forming puddles "
          "around the base.",
          ({ "ceiling" }) : 
          "The ceiling of the tent droops down almost a full two feet from "
          "the weight of the leftover rainwater and the badly placed poles.",
          ({ "wobbly poles", "poles" }) :
          "The metal poles that hold up the tent look like they will "
          "fall over any minute.",
          ({ "wet ground", "muddy ground", "ground" }) :
          "The ground is wet and muddy.",
]) );
    SetExits( ([
          "west" : BEORN_ROOM + "tent2.c",
          "out" : BEORN_ROOM + "field4.c",
]) );
    SetObviousExits("west, out");
    SetInventory( ([
          BEORN_NPC + "osoldier.c" : 2,
]) );
    SetClimate("indoors");
    SetAmbientLight(50);
}
