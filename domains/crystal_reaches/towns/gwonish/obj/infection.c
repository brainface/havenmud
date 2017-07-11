#include <lib.h>
#include <damage_types.h>
inherit LIB_GERM;

void eventSuffer();

static void create() {
	::create();
	SetKeyName("stomache infestation");
	SetShort("");
	SetInvis(4);
	SetId( ({ "infestation" }) );
	SetAdjectives( ({ "stomache" }) );
	SetLifeSpan(20);
	SetCureChance(40);
	SetSuffer( (: eventSuffer :) );
}

void eventSuffer() {
	object who = environment();
	
	if (!who) return;
	if (!living(who)) return;
	
	switch(random(8)) {
		case 0..5:
		  send_messages( ({ "vomit" }),
		    "$agent_name%^GREEN%^ $agent_verb%^RESET%^ violently!",
		    who, 0, environment(who));
		  who->eventCollapse();
		  who->SetParalyzed(2);
		  who->AddStaminaPoints(-200);
		  who->eventReceiveDamage(this_object(), DISEASE, 50, 1);
		  break;
		case 6:
		  send_messages( ({ "vomit", "bring" }),
		    "$agent_name%^GREEN%^ $agent_verb%^RESET%^ and $agent_verb "
		    "up %^RED%^blood%^RESET%^!",
		     who, 0, environment(who));
		  who->eventCollapse();
		  who->SetParalyzed(2);
		  who->AddStaminaPoints(-300);
		  who->eventReceiveDamage(this_object(), DISEASE, 100, 1);
		  break;
		case 7:
		  who->AddRecoveryTime(15);
		  who->eventCollapse();
		  who->SetSleeping(20);
		  send_messages( ({ "pass" }),
		    "$agent_name $agent_verb out!",
		    who, 0, environment(who));
		  break;
		default:
		  break;
		}
  return;
}
