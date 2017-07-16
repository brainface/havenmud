/*  John Carpenter's Thingism */
#include <lib.h>
#include <damage_types.h>
#include "../camp.h"
inherit LIB_GERM;
int eventSuffer();
int createThing(string limb);

string *outerLimbs = ({
  "left hand",
  "right hand",
  "left wing",
  "right wing",
  "left paw",
  "right paw",
  "tail",
});

string *innerLimbs = ({
  "left leg",
  "right leg",
  "left arm",
  "right arm",
});

static void create() {
  germ::create();
  SetKeyName("strange contagion");
  SetShort("strange contagion");
  SetContagious(15);
  SetCureChance(5);
  SetLifeSpan(90);
  SetSuffer( (: eventSuffer :) );
}



int eventSuffer() {
  object who = environment();
  string innerLimb = 0;
  string outerLimb = 0;
  
  if (!who) return 0;
 
  switch(random(4)) {
    case 0:
      who->eventPrint("You feel like you're forgetting something. Something important.");
      break;
    case 1:
      who->eventPrint("Your head turns, looking around of its own volition.");
      break;
    case 2:
      who->eventPrint("You don't remember why you came here.");
      break;
    case 3:
      who->eventPrint("You babble incoherently.");
      break;
  }
  
  if (!random(10)) {

