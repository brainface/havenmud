/*    /verbs/vehicles/hitch.c
 * hitch a thing to a thing
 * living to wagon or wagon to living
 */

#include <lib.h>
// #include <position.h>
// #include <rounds.h>

inherit LIB_VERB;

static void create() {
    verb::create();
    SetVerb("hitch");
    SetRules("", "LIV to OBJ", "OBJ to LIV");
    SetErrorMessage("Hitch what animal to what wagon?");
    SetHelp(
      "Syntax: <hitch [horse] to [wagon]>\n"
      "                <hitch [wagon] to [horse]>\n"
      "\n"
      "Allows you to hitch a horselike thing to a wagon in order to "
      "drive it around."
      "See also: mount, unhitch, drive, board, hijack.\n"
    );
}

mixed can_hitch_obj_to_liv() {
   if(this_player()->GetSleeping()) {
      return "You cannot do that while sleeping!";
   }
   if( this_player()->GetParalyzed() ) {
     return "You cannot do anything!";
   }
   return 1;
}

mixed can_hitch_liv_to_obj() {
    return can_hitch_obj_to_liv();
}

// please note that the cart might be a horse and the horse might be a cart,
// no object type checking has been performed yet.
mixed do_hitch_obj_to_liv(object cart, object horse) {
  mixed horsehitch;
  
  // "if both of us are carts or both of us aren't carts, fail, there shall 
  // be exactly one cart (and hopefully therefore one horse.)
  if ( wagonp(cart)+wagonp(horse)!=1) {
  	this_player()->eventPrint("You can only hitch a horse or other draft animal to a wagon, "
  	  "not two wagons together nor two horses.");
    return 0;
  }
  
  // ownership check for cart (which may be a horse)
  if ( cart->GetOwner() != this_player()->GetKeyName() && cart->GetDriver() != this_player()->GetKeyName() ) {
    this_player()->eventPrint("You do not own " + cart->GetName() + " and are "
      "not registered as the driver.");
    return 0;
  }

  // ownership check for horse (which may be a cart)
  if ( horse->GetOwner() != this_player()->GetKeyName() && horse->GetDriver() != this_player()->GetKeyName() ) {
    this_player()->eventPrint("You do not own " + horse->GetName() + " and are "
      "not registered as the driver.");
    return 0;
  }  
  
  // leaving agent blank so no message is generated
  horsehitch = horse->eventReceiveHitch(cart, 0);
  // fail and return error message if we failed to hitch the target to us.
  if (stringp(horsehitch)) return horsehitch;
  if (!horsehitch) {
    this_player()->eventPrint( "Could not hitch " + horse->GetShort() +
    " to " + cart->GetShort() + ".");
    return 0;
  }
  
  // remove leader status
  if (horse->GetLeader()){
  	horse->GetLeader()->RemoveFollower(this_object());
  }
  if (cart->GetLeader()) {
  	  cart->GetLeader()->RemoveFollower(this_object());
  }
  
  return cart->eventReceiveHitch(horse, this_player());

}

mixed do_hitch_liv_to_obj(object horse, object cart) {
  return do_hitch_obj_to_liv(cart,horse);
}

