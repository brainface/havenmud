/*    /lib/move.c
 *    From the Dead Souls Object Library
 *    Functions for basic movement
 *    Created by Descartes of Borg 950209
 *    Version: @(#) move.c 1.4@(#)
 *    Last modified: 96/12/31
 */

#include <message_class.h>
#include <lib.h>

//inherit LIB_SIT;

private static object LastEnvironment = 0;
private int isRiding = 0;

void SetIsRiding(int thing) {isRiding = thing;}
int  GetIsRiding() {return isRiding;}


// abstract methods
varargs void eventPrint(string str, mixed args...);
//object array GetSitters();
// end abstract methods

/* ******************  /lib/move.c attributes  ******************** */
object GetLastEnvironment() {
    return LastEnvironment;
}

/* ********************  /lib/move.c events  ********************** */
int eventMove(mixed dest) {
    object ob, horsie, cart;
    int moved = 0;

    if( !this_object() ) {
        return 0;
    }
    if( environment() ) {
        int x;

        x = (int)environment()->CanRelease(this_object());
        if( !x && !archp() ) {
            return 0;
        }
    }
    if( stringp(dest) ) {
        if( !(ob = find_object(dest)) ) {
            string str;

            if( str = catch(call_other(dest, "???")) ) {
                if( creatorp() ) {
                    eventPrint(str, MSG_ERROR);
                }
                return 0;
            }
            ob = find_object(dest);
        }
    }
    else {

        ob = dest;
    }
    if( !ob || ob == this_object() ) {
      return 0;
    }
    if( living(this_object()) && living(ob) ) {
      return 0;
    }
    if( !ob->CanReceive(this_object()) ) {
        return 0;
    }
    if( LastEnvironment = environment() ) {
        environment()->eventReleaseObject(this_object());
    }
    move_object(ob);
    environment()->eventReceiveObject(this_object());
    if( environment() ) {
        foreach(object peer in all_inventory(environment())) {
            if( peer != this_object() ) {
                catch(peer->eventEncounter(this_object()));
            }
        }
    }
    moved = (LastEnvironment != environment());

    if (moved && this_object()->GetChair() && !this_object()->GetIsRiding()) {
      horsie = this_object()->GetChair();
      horsie->eventReleaseStand(this_object());
      this_object()->SetChair(0);
      //this_object()->eventStand();
    }

    if (this_object()->GetSitters()) {
      // attempt to move everything sitting on me with me.
      foreach (object sitter in this_object()->GetSitters() ){
        sitter->SetIsRiding(1);
        sitter->eventMoveLiving(dest,
          "$N rides away on " + this_object()->GetKeyName() + ".",
          "$N rides in on " + this_object()->GetKeyName() + ".");
        sitter->SetIsRiding(0);
      }
    }
    // attempt to move any cart hitched to me
    if (this_object()->GetHitcher()) {
       cart = this_object()->GetHitcher();
       if (vehiclep(cart)) {
	 // okay it's apparently teleporting and not moving,
	 // so it's tel out/telin, and those can be custom
	 // set to whatever
	 cart->eventMoveLiving(dest,
	   cart->GetMessage("telout"),
	   cart->GetMessage("telin"));
       }
    }
    return moved;
}

