//
// A scree
// by Ranquest@Haven
// Created 27 Nov 98
//
#include <climb.h>
#include <lib.h>
#include "main.h"
inherit LIB_DUMMY;
inherit LIB_CLIMB;

static void create() {
  dummy::create();
  SetId("scree");
    SetAdjectives( ({"loose"}) );
  SetShort("a loose scree");
  SetLong("The loose stones and boulders form a loose scree,"
    " a loosely packed hill of rocks and small stones. It looks like"
    " it may be climbable.");
  SetClimb(RNQ_RM + "pass2.c",CLIMB_DOWN);
  SetClimb(RNQ_RM + "scree.c",CLIMB_UP);
}
