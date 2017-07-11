/*    /realms/haun/areas/mines/npc/cougar.c
 *    created on 12/20/98
 *    by Haun
 */
#include <lib.h>
#include "../mine1.h"
#include <damage_types.h>
inherit LIB_NPC;
static void create() {
    npc::create();
    SetKeyName("cougar");
    SetId( ( "cougar" ) );
    SetAdjectives( ({"powerful"}) );
    SetShort("a powerful cougar");
    SetLong("This cougar looks like he could destroy any individual that"
      " he feels.  His fur is a light tan color, matted with dried blood."
      "  He appears to be very violent.");             
    
    SetMeleeAttackString("claws");
    SetMeleeDamageType(SLASH);
    SetRace("bear", "cougar");
    SetClass("animal");
    SetGender("male");
    SetLevel(4);
    SetMorality(0);
    SetAction(6, ({ "The cougar roars violently." }));
}
