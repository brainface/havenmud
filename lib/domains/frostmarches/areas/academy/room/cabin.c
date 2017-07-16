/* A log cabin in the woods
 * 
 *
 */

#include <lib.h>

#include "../fence.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("indoors");
  SetAmbientLight(30); //about mid range of kobold & lamrani
  SetShort("a small cabin in the woods");
  SetLong(
    "This log cabin shows little in the way of decoration or privacy, "
    "appearing more like a military barracks than a house. A set of "
    "bunkbeds along the southern wall show signs of recent use. On the "  
    "other side of the cabin, a wood heater emits an impressive amount of "
    "heat. A set of cabinets line the wall on one side of the heater, and "
    "on the other rests a simple cot. An open window and two glass globes "
    "along the ceiling provide some light."
  );
  SetItems( ([
    ({"cabin"}) :
      (: GetLong :),

    ({"house"}) :
      (: GetLong :),

    ({"ceiling","beams","beam"}):
      "Thick wooden beams support the ceiling.",

    ({"walls","wall","logs","log"}):
      "The logs serving as the cabin's walls seem freshly cut, and are " 
      "still weeping sap.",

    ({"floor","hardwood"}):
      "Polished hardwood serves for the floor. ",

    ({"cabinets","cabinet"}) :
      "The cabinet doors stand open, revealing cooking utensils and bags "
      "of foodstuff",

    ({"bags","food","foodstuff","flour","rice","bags of foodstuff"}) :
      "Bags of flour and rice are stacked in the cabinets.",

    ({"utensils","pots","pans","spoons"}):
      "Pots, pans, and spoons of various sizes are piled on top of each "
      "other.",

    ({"cot"}):
      "A cot, much longer than the other beds in the room, rests close to "
      "the wood heater.",

    ({"window","slits","shutters"}):
      "The window's shutters are half-open, letting in a draft of bitter " 
      "cold and giving an excellent view of the practice field.",

    ({"globes","globe"}):
      "Two glass globes attached to the ceiling beams shine dimly with " 
      "magical illumination. They seem the only concession to decoration " 
      "in the room.",

    ({"heater","stove"}):
      "A large iron wood heater keeps the chill of the frostmarches away " 
      "with fierce heat. Bits of burnt food and greasestains along the "
      "top surface attest to its use as a stove.",

    ({"bunk","bunks","bunkbed","bunkbeds"}):
      "Two bunkbeds lie along the wall, housing three bunks each. They " 
      "seem made for smaller frames.",
  ]) );
  SetItemAdjectives( ([
    "cabin" : ({"log"}),
    "cot" : ({"simple"}),
    "globe" : ({"glass"}),
    "hardwood" : ({"polished"}),
    "heater" : ({"wood","iron"}),
    "window" : ({"open"}),
  ]) );
  SetListen( ([
    "default" : "The heater crackles and pops with burning wood.",
  ]) );
  SetSmell( ([
    "default" : "The cabin smells faintly of bitter smoke.",
  ]) );

  SetTouch( ([
    "heater" : "The heater is painfully hot to the touch.",
  ]) );
  SetExits( ([
    "out" : FENCE_ROOM "practice_field",
  ]) );
  SetInventory( ([
    FENCE_NPC "cowardly_student" : 2,
    FENCE_NPC "trainer" : 1,
  ]) );
  SetDoor( "out", FENCE_OBJ "iron_door" );
}

