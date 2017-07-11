/*    /obj/wed_ring.c
 *    from Dead Souls LPMud
 *    created by Descartes of Borg 951211
 */
 
#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include <vendor_types.h>
#include <message_class.h>
#include <armour_class.h>
#include <size.h>
 
inherit LIB_ARMOUR;

int SP(string str);
int ESP(string str);
 
private string Spouse;
 
mixed eventMove(mixed dest);
string SetSpouse(string str);
string GetSpouse();
string RealLong();
 
static void create() {
    armour::create();
    AddSave( ({ "Spouse" }) );
    SetKeyName("wedding ring");
    SetMaterial( ({ "mithril" }) );
    SetId( ({ "ring", "wedding ring" }) );
    SetAdjectives( ({ "golden", "gold" }) );
    SetShort("a wedding ring of gold");
    SetLong( (:RealLong:) );
    SetVendorType(VT_ARMOUR | VT_MAGIC);
    SetArmourClass(ARMOUR_CLOTH);
    SetMass(10);
    SetValue(0);
    SetPreventDrop("You may not drop your wedding ring!");
    SetPreventGet("You cannot take someone else's wedding ring.");
    SetRetainOnDeath(1);
    SetDamagePoints(1000000);
    SetArmourType(A_RING);
}
 
 
string SetSpouse(string str) {
    if( Spouse ) return Spouse;
    else return Spouse = str;
}
 
string GetSpouse() { return Spouse; }
 
string RealLong() {
    if (living(environment()))
      return ("This beautiful golden band was given to you by " +
      environment()->GetSpouse() + " to capture your eternal love.");
    return "This is a wedding ring.";
}
 
void init() {
	::init();
	if (environment()) {
	  add_action((: SP :), "sp" );
	  add_action((: ESP :), "esp");
	}
}

int SP(string str) {
	object me, spouse;
	string msg;
	if (!me = environment()) return 0;
	if (!spouse = find_living(lower_case(me->GetSpouse()))) return 0;
	
	me->eventPrint(capitalize(me->GetKeyName()) + " %^BOLD%^MAGENTA%^<spouse>%^RESET%^ " + str, MSG_CONV);
	spouse->eventPrint(capitalize(me->GetKeyName()) + " %^BOLD%^MAGENTA%^<spouse>%^RESET%^ " + str, MSG_CONV);
	me->AddSPHist(capitalize(me->GetKeyName()) + " %^BOLD%^MAGENTA%^<spouse>%^RESET%^ " + str, MSG_CONV);
	spouse->AddSPHist(capitalize(me->GetKeyName()) + " %^BOLD%^MAGENTA%^<spouse>%^RESET%^ " + str, MSG_CONV);
	/*
	msg = capitalize(me->GetKeyName()) + " %^BOLD%^MAGENTA%^<spouse>%^RESET%^ " + str;
	message("system", msg, ({ me, spouse }) );
	*/
	return 1;
}

int ESP(string str) {
	object me, spouse;
	string msg;
	if (!me = environment()) return 0;
	if (!spouse = find_living(lower_case(me->GetSpouse()))) return 0;
	
	me->eventPrint("%^BOLD%^MAGENTA%^<spouse>%^RESET%^ " + capitalize(me->GetKeyName()) + " " + str, MSG_CONV);
	spouse->eventPrint("%^BOLD%^MAGENTA%^<spouse>%^RESET%^ "  + capitalize(me->GetKeyName()) + " " +str, MSG_CONV);
  me->AddSPHist(capitalize(me->GetKeyName()) + " %^BOLD%^MAGENTA%^<spouse>%^RESET%^ " + str, MSG_CONV);
	spouse->AddSPHist(capitalize(me->GetKeyName()) + " %^BOLD%^MAGENTA%^<spouse>%^RESET%^ " + str, MSG_CONV);

	/*
	msg = "%^BOLD%^MAGENTA%^<spouse>%^RESET%^ " + capitalize(me->GetKeyName()) + " " + str;
	message("system", msg, ({ me, spouse }) );
	*/
	return 1;
}

int GetSize() {
	object e;
	if (living(e = environment()))
	  return e->GetSize();
	return SIZE_MEDIUM;
}
