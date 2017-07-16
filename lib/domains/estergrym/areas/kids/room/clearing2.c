//Samah@Haven
//20040911
#include "../clearing.h"
#include <lib.h>
#include <std.h>

inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("a small clearing");
  SetDayLong(
     "This small clearing has been carved out "
     "of the bramble patch, creating a natural barrier "
     "separating it from the main road.  Small shrubs "
     "and grasses line the area, contrasting with the hard, "
     "thorny surroundings.  A small path continues to the "
     "north, leading off farther into the briars."
  );
  SetNightLong(
     "The moonlight filters softly into the area through "
     "the surrounding brambles, causing dark shadows to sweep "
     "across the clearing.  Small shrubs and bushes "
     "dot this natural clearing within the vicious thorns "
     "that surround it.  A small path is visible leading "
     "farther into the brambles."
  );
  SetItems( ([ 
     ({ "clearing" }):
     (: GetLong :),
     ({ "bramble", "briar", "brambles", "briars","barrier","patch" }):
     "The sharp brambles surround the clearing, creating "
     "an impassable natural barrier.",
     ({ "shrubs", "shrub","bushes" }):
     "The small shrubs line the interior of the clearing "
     "adding a hospitable feeling to the harsh surroundings.",
     ({ "grass", "grasses" }):
     "The small crab grass covers the clearing, giving the area "
     "a soft appearance in contrast to the hard brambles surrounding "
     "it.",
     ({ "path" }):
     "The path leads off to the north, blazing its way "
     "through the briars.",
     ({ "road" }):
     "The main road is barely visible through the thick "
     "brambles that surround the clearing.",
     ({ "thorns" }):
     "The thorns are incredibly sharp and create an impassible "
     "barrier around the small clearing.",
     ({ "shadow","shadows" }):
     "The dark shadows stretch and contract across the "
     "clearing as the wind blows the brambles to and fro."
  ]) );
  SetItemAdjectives( ([
     "clearing" : ({ "small" }),
     "bramble" : ({ "patch", "sharp", "impassable","surrounding",
                    "hard"
     }),
     "shadow" : ({ "dark","sweeping" }),
     "shrubs" : ({ "small" }),
     "grass" : ({ "small", "crab" }),
     "path" : ({ "small" }),
     "thorns" : ({ "viscious","hard" }),
     "road" : ({ "main" }),
  ]) );
  SetInventory( ([ 
     CLEAR_NPC "female_gelfling" : 1,
     CLEAR_NPC "male_gelfling" : 1,
  ]) );
  SetSmell( ([
     "default" : "The smell of fresh cut foliage fills the air",
  ]) );
  SetListen( ([
     "default" : "The sound of wind whistling through the brambles "
     "echoes throughout the area",
  ]) );
  SetExits( ([
     "north" : CLEAR_ROOM "clearing1",
  ]) );
}

/** Approved by Laoise at Sat Sep 11 20:24:20 2004. **/