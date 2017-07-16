#include <lib.h>
#include <damage_types.h>
inherit LIB_ITEM;
inherit LIB_TOUCH;

void eventBurnIdiot();

static void create() {
   item::create();
   touch::create();
   SetKeyName("forge");
   SetShort("a roaring forge");
   SetInvis(1);
   SetId( ({ "forge" }) );
   SetAdjectives( ({ "roaring" }) );
   SetLong("Heat radiates from the forge, visable only as "
           "wavy lines of distortion that surround it.  "
           "It would be easy to burn oneself on it.");
   SetPreventGet("The forge is firmly attached to the ground.");
}

varargs mixed eventTouch(object who, string str) {
   who->eventReceiveDamage(HEAT,0,40+random(20));
   send_messages( ({ "burn" }),"$agent_name $agent_verb "
                     "$agent_reflexive on the forge.", 
                     who,0,environment(who));
   return 1;
}
