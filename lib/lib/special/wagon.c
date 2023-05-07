/* wagon.c
 * Mahkefel 2016
 * basically, land ships
 * 
 * Except you sit on them from outside and drive them around
 * it's gonner be rad and by that i mean ehhh
 */                   

#include <lib.h>
#include <vehicle.h>
#include <daemons.h>
                     
inherit LIB_VEHICLE;
inherit LIB_HITCH;
inherit LIB_SIT;

// non-owner allowed to drive wagon
string Driver = "";

string GetDriver() {return Driver;}
string SetDriver(string str) {return Driver = str;}

static void create() {
  vehicle::create();
  // inherited:
  // "Owner",
  // "BridgeDescription",
  // "CurrentLocation",                                    
  // "VehicleName", 
  // "VId", 
  // "VLong",               
  // "VShort"
  AddSave( ({ "Driver" }) );
  // $N shows the VID, so hardcoding it to rickety wagon here.
  // chariots, carts, et al should have custom messages defined in
  // their files.
  SetProperty("PROP_VEHICLE","wagon");
  // the way i've got it set, the wagons are secretly teleporting
  // so come/leave don't really work, it's telout/telin
  // the player's movement will display direction, context etc.
  SetMessages( ([
    "come"   : "$N clatters in.",
    "leave"  : "$N clatters $D.",
    "telout" : "",
    "telin"  : "$N clatters in.",
  ]) );
  SetMaxSitters(1);
}                               

void heart_beat() {                                          
  object sea = environment();
  ResetExit();
  if (hasMoved ) {
     all_inventory()->eventPrint("The wheels click and clatter against the ground.");
     SaveVehicle();                                
  }              
  hasMoved = 0;                                        
  if (time() - LastSave > 600) SaveVehicle();
}

void init() {
  vehicle::init();                
  if (environment(this_player()) == environment(this_object())) { 
    eventPrint("Something moved outside the wagon!");
  }
}

// override because wagon names are weird
string GetName() {
  return GetKeyName();
}

// ownership plaque (Essentially the "crystal ball" on ships, but this is only viewable from outside the wagon
// and part of the wagon object.
string GetRead(string str) {
  string ownerInformation;
  debug(str);
  if (str == "plaque") {
    if (GetOwner() && GetOwner() != "") {
      ownerInformation = "Owned by: " + this_object()->GetOwner();
    } else {
      ownerInformation = "The name of the owner has been scratched to the point of illegibility.";
    }
    if ( GetDriver() && GetDriver() != "" ) {
      ownerInformation += "\nMr. or Ms.: " + this_object()->GetDriver() + " is permitted to drive this wagon.";
    }
    ownerInformation += "\n(HINT: You can <set driver to playername> to allow another player to drive a wagon you own.";
    //ownerInformation += "\nYou may also <hijack wagon> to steal ownership of this wagon. ";
    ownerInformation += "\nYou must be sitting on the wagon to do either.)";
    return ownerInformation;
  } else {
    return ::GetRead(str);                                 
  }
}

// have to override this to enable custom "read plaque" behavior
mixed direct_read_str_word_obj(string str) {
    str = remove_article(lower_case(str));
    if (str == "plaque") {
      return 1;
    } else if( GetRead(str) ) {
      return 1;
    } else {
      return 0;
    }
}

/*
// a helper function that simply returns generic wagon help info
// use it to add instructions to custom wagon longs
// i.e. SetLong("A really badass wagon" + GetWagonHelp() );
string WagonHelp() {
  string help = "";
  help  = "A brass plaque nailed to the side has some writing on it. ";
  help += "\n(<sit on wagon> to sit on the driver's seat and <drive> the wagon. ";
  help += "<hitch horse to wagon> to hitch some draft animal you control to the wagon, otherwise it won't go far!";
  help += "<unhitch horse> to release the horse, <hijack wagon> to steal the wagon. ";
  help += "<read plaque on wagon> to check who owns it.)";
  return help;
}                                                   
*/
// add some helpish like things to all wagon descs so I don't have to type it a bajillion times.
varargs string GetExternalDesc(object who) {
  return vehicle::GetExternalDesc(who) + " There is a brass plaque nailed to the side with some writing on it. (<read plaque on wagon>)";
}            


// haaaack
void LoadVehicle() {
  vehicle::LoadVehicle();
  SetKeyName(GetShort());
  parse_refresh();     
}
