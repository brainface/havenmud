
#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include <vendor_types.h>

inherit LIB_ARMOUR;

  /* Prototyping
   * When you create your own functions with in the code you always 
   * want to prototype them at the beginning of your code.  Prototyping
   * is just kind of introducing them to the rest of the code so that when
   * you actually call them, the code knows who they are.
   *
   * Prototyping is done like this:
   * <variable type> <function name>(<arguments>);
   * The variable type is what the function returns when it is finished.
   * you pass "void" as the type if you don't want the function to return
   * anything.
   * The function name is just that, the name of your function.
   * The arguments are any arguments that you pass to the function.  We won't
   * be using any in this example.
   * and finally all prototypes are closed with a ";" like most other 
   * statements in your code.
   */
int CheckDwarf();

static void create()
{
  armour::create();
  SetKeyName("mitril helm");
  SetId(({"helm","helmet","mitril helm","mithril helmet"}));
  SetShort("a softly glowing helm");
  SetLong( "A warm glow is given off by the metal itself of this well "
           "crafted helm" );
  SetDamagePoints(1000);
  SetVendorType(VT_ARMOUR);
  SetMass(450);
  SetValue(1000);
  SetArmourType(A_HELMET);
  
  SetProtection(BLUNT,15);
  SetProtection(SLASH,15);
  SetProtection(PIERCE,17);
  SetProtection(ACID,12);
  
  /* NOTES
   * Ok here is where the function is called.
   *
   * SetWear is calling the function CheckDwarf() which is
   * a little lower in the code.
   */
  SetWear( (: CheckDwarf :) );
  
}

  /* CheckDwarf()
   * Ok, here is the function.  
   * First thing we are  going to do here is check to see if the person
   * trying to wear the helm is a dwarf.  This is done by calling functions
   * defined elsewhere:
   * this_player() is an efun that returns an object representing the player
   * who is doing the action.
   * the -> is saying send this data to the next function.
   * the next function "GetRace" checks in the object "this_player" to see 
   * what race the player is. and finally it compares that with "dwarf"
   * if it is a dwarf it executes the code in the brackets immediately 
   * following the if statement.  The (string) at the beginning is what is
   * called type casting.  It means that no matter what data the functions 
   * return, to treat it as a string.
   *
   * The write function is very simple all it does is write whatever text
   * is enclosed within it to the user's screen.
   * The say function does the same thing except that it writes the data to
   * everyone else in the same room as the user, but not the user.
   * Notice that in the say() we called a couple of functions.
   * this_player() we are already familar with, but GetName() is new.  It
   * does pretty much the same thing as GetRace() except it returns the data
   * stored in the objects short variable ( where it was set by SetShort())
   * finally we do a return.
   * when we return, we exit the function and go back to the function that
   * called this function.
   * In this case SetWear() from above is expecting an integer to be returned,
   * and if that integer is a 1 then it lets the user wear the armour.  If it
   * is a 0 then it won't let the user wear the armour.  This is defined
   * someplace else and we don't need to worry about it.
   */
int CheckDwarf()
{
  if( (string)this_player()->GetRace() == "dwarf")
  {
  write("You feel the strength of your ancestors fill you.");
  say((string)this_player()->GetName() + "wears a glowing helm.");
  return 1;
  }
  else
  {
  write("A strong force prevents you from wearing the helm.");
  return 0;
  }
}
