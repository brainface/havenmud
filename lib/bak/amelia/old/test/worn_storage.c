/*		/lib/worn_storage.c
 *		brutally hacked together from /lib/armour.c
 *		and /lib/storage.c of the Nightmare IV LPC Library
 *		permits things like backpacks to be worn as well as
 *		hold things.
 *		created by Balishae of Haven, March 98
 */
 

#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include <vendor_types.h>
#include "/lib/include/storage.h"
#include "/lib/include/armour.h"
 
inherit LIB_HOLDER;
inherit "/realms/amelia/test/armour.c";
inherit LIB_LOCK;
 
private int CanClose, CanLock;

void create() {
    AddSave( ({ "CanClose", "CanLock" }) );
    holder::create();
    armour::create();
    lock::create();
    SetPreventPut("You can't put this in there.");
    CanClose = 0;
    CanLock = 0;
}

varargs void reset(int count) {
    armour::reset(count);
    holder::reset(count);
}

mixed direct_close_obj(object target, string id) {
    if( !GetCanClose() ) return 0;
    else return lock::direct_close_obj(target, id);
}

mixed indirect_get_obj_out_of_obj(object item) {
    mixed tmp;

    tmp = holder::indirect_get_obj_out_of_obj(item);
    if( tmp != 1 ) return tmp;
    if( GetClosed() ) return capitalize(GetShort()) + " is closed.";
    return 1;
}

mixed direct_lock_obj_with_obj() {
    if( !GetCanLock() ) return 0;
   else return lock::direct_lock_obj_with_obj(0,0,0);
}

mixed direct_look_inside_obj(object target, string id) {
    mixed tmp;

    if( (tmp = holder::direct_look_inside_obj(target, id)) != 1 ) return tmp;
    if( GetClosed() ) return "It is closed";
    return 1;
}

mixed indirect_look_at_obj_word_obj(object target, string wrd, object ob,
				    string id, string my_id) {
    mixed tmp;

    if( (tmp = holder::indirect_look_at_obj_word_obj(target, wrd, ob, id,
						     my_id)) != 1 )
      return tmp;
    if( GetClosed() ) return "It is closed.";
    return 1;
}      
  
int direct_unlock_obj_with_obj() {
    if( !GetCanLock() ) return 0;
   else return lock::direct_unlock_obj_with_obj(0,0,0);
}

int inventory_accessible() { return lock::inventory_accessible(); }

int inventory_visible() {
    if( !lock::inventory_visible() ) return 0;
    else return holder::inventory_visible();
}

mixed CanClose(object who, string id) {
    if( !GetCanClose() ) return 0;
    else return lock::CanClose(who, id);
}

mixed CanOpen(object who, string id) {
    if( !GetCanClose() ) return 0;
    else return lock::CanOpen(who, id);
}

mixed CanPick(object who, string id) {
    if( !GetCanLock() ) return "It isn't lockable in the first place.";
    else return lock::CanPick(who, id);
}

mixed CanPutIn(object who, object what) {
    if( GetClosed() ) return capitalize(GetShort()) + " is closed.";
    else return holder::CanPutIn(who, what);
}

mixed CanUnlock(object who, string id, object key) {
    if( !GetCanLock() ) return 0;
    else return lock::CanUnlock(who, id, key);
}

int eventReceiveObject() {
    object ob;

    ob = previous_object();
    if( GetClosed() ) return 0;
    return holder::eventReceiveObject();
}

int SetCanClose(int x) { CanClose = x; }

int GetCanClose() { return CanClose; }

int SetCanLock(int x) { return SetCanClose(CanLock = x); }

int GetCanLock() { return CanLock; }

void SetKey(string key) { SetKeys(key); } /* for backwards compat */

varargs string GetLong(string str) {
    string tmp;

    tmp = armour::GetLong(str);
    if( GetClosed() ) {
	if( GetOpacity() < 30 ) {
	    tmp += "\n" + holder::GetLong(str);
	}
	else if( GetOpacity() < 50 ) {
	    if( sizeof(all_inventory()) > 0 ) {
		tmp += "\n" + "There is something in it.";
	    }
	}
	tmp +="\nIt is closed.";
    }
    else tmp += "\n" + holder::GetLong(str);
    return tmp;
}

int GetOpacity() {
    if( GetClosed() ) return holder::GetOpacity();
    else return 0;
}

int GetRadiantLight(int ambient) {
    return armour::GetRadiantLight(ambient) + holder::GetRadiantLight(ambient);
}

static mixed *AddSave(mixed *vars) { return armour::AddSave(vars); }

int SetSaveRecurse(int x) { return armour::SetSaveRecurse(x); }

