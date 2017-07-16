#include <lib.h>

inherit LIB_ITEM;

void eventDancePunk();

static void create() {
  item::create();
  SetKeyName("disco ball");
  SetShort("an unstoppable disco ball");
  SetId(({ "ball" }));
  SetAdjectives( ({ "disco","unstoppable" }) );
  SetLong(
    "This monstrous device is cobbled together from whirring gears and shining "
    "mithral plates. Steam occassionaly bursts from its innards, and beams of "
    "light shine and dart about the room."    
  );
  call_out( (: eventDancePunk :), 0);
}

void eventDancePunk() {
  object *victims;  
  send_messages("shine",
    "The disco ball shines in a %^BOLD%^YELLOW%^prismatic, %^MAGENTA%^tyrannical %^CYAN%^light!%^RESET%^",
    this_object(),0,environment()
  ); 
  victims = all_inventory(environment());
  foreach(object victim in victims) {
    if ( playerp(victim)) {
      victim->eventForce("dance helplessly");
    } else if (creatorp(victim)) {
      victim->eventForce("dance helplessly");
    }
  }
  call_out( (: eventDancePunk :), 30);
}


