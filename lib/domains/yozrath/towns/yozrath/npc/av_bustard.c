#include <lib.h>
inherit LIB_SENTIENT;

static void create() {
  sentient::create();
  
  SetKeyName("bustard");
  SetId( ({ "bustard", "bird" }) );
  SetAdjectives( ({ "brown", "large" }) );
  SetShort("a large brown bustard");
  SetLong(
    "With her long thick neck and long sturdy legs, this large "
    "bustard stalks the floor, pecking for food. She has long broad "
    "wings in a dusty brown color that have 'fingered' wingtips."
    );
  SetRace("bird");
  SetGender("female");
  SetClass("animal");
  SetLevel(3);
  AddLimb("torso",0,1,({ }) );
  AddLimb("head","torso",1,({ }) );
  AddLimb("left leg","torso",4,({ }) );
  AddLimb("right leg","torso",4,({ }) );
  AddLimb("left wing","torso",3,({ }) );
  AddLimb("right wing","torso",3,({ }) );
}



